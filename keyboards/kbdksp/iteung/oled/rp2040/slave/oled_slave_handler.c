// Copyright 2022 Jose Pablo Ramirez (@jpe230)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "jpe230.h"
#include "transactions.h"
#include <stdio.h>
#include <stdlib.h>
#include <hal.h>

/* ---------------------------------------------------------------------------
 * Right-half (slave) OLED, rendered vertically (32 wide x 128 tall).
 *
 *   [ animated eye      ]   pupil tracks the last typed key, blinks, recenters
 *   -----
 *    WPM
 *    000                    live WPM, never blanks (shows 000 when idle)
 *   -----
 *    RP                     "RP2040" stacked (only 5 chars fit per line)
 *   2040
 *    23C                    RP2040 internal die temperature
 * ------------------------------------------------------------------------- */

// Eye geometry (logical coordinates, in the rotated 32x128 frame).
#define EYE_CX 16            // eye center x
#define EYE_CY 19            // eye center y
#define EYE_R  15            // eyeball radius
#define EYE_PR 5             // pupil radius
#define EYE_REGION_BOTTOM 38 // clear/redraw the eye within y = 0..EYE_REGION_BOTTOM

// Text rows (8 px each). Rows 0..4 are the eye; rows 5..6 are a blank gap.
#define ROW_DIV1 7
#define ROW_WPM_LABEL 8
#define ROW_WPM_VALUE 9
#define ROW_DIV2 10
#define ROW_RP1 11
#define ROW_RP2 12
#define ROW_TEMP 13

/* ------------------------------ Temperature ------------------------------ */
// RP2040 on-die temperature sensor is wired to ADC channel 4. ChibiOS does
// not expose it through QMK's analog wrapper, so drive the ADC directly.

static const ADCConfig            adc_cfg = {0, 0, false};
static const ADCConversionGroup   adc_grp = {
    false,         // not circular (one-shot)
    1,             // one channel
    NULL,          // end callback
    NULL,          // error callback
    RP_ADC_CHTS,   // channel mask: temperature sensor (CH4)
};
static adcsample_t adc_buf[1];
static bool        adc_started = false;

static int read_temp_c(void) {
    if (!adc_started) {
        adcStart(&ADCD1, &adc_cfg);
        adcRPEnableTS(&ADCD1);
        adc_started = true;
    }
    adcConvert(&ADCD1, &adc_grp, adc_buf, 1);
    // 12-bit sample over 3.3V reference; datasheet transfer function.
    float voltage = adc_buf[0] * (3.3f / 4096.0f);
    float temp_c  = 27.0f - (voltage - 0.706f) / 0.001721f;
    return (int)(temp_c + 0.5f);
}

/* --------------------------------- Eye ----------------------------------- */

static float    pupil_x = 0.0f; // current eased pupil offset (px)
static float    pupil_y = 0.0f;
static bool     blinking      = false;
static uint32_t blink_timer   = 0;     // time since last blink ended / started
static uint32_t blink_len     = EYE_BLINK_MIN_MS;

static void eye_clear_region(void) {
    for (uint8_t y = 0; y <= EYE_REGION_BOTTOM; y++) {
        for (uint8_t x = 0; x < 32; x++) {
            oled_write_pixel(x, y, false);
        }
    }
}

static void eye_draw(int16_t px, int16_t py, bool closed) {
    eye_clear_region();

    if (closed) {
        // Closed eye: a short horizontal lid line.
        for (uint8_t x = EYE_CX - 11; x <= EYE_CX + 11; x++) {
            oled_write_pixel(x, EYE_CY, true);
            oled_write_pixel(x, EYE_CY + 1, true);
        }
        return;
    }

    // Eyeball outline (ring).
    for (int16_t y = -EYE_R; y <= EYE_R; y++) {
        for (int16_t x = -EYE_R; x <= EYE_R; x++) {
            int16_t d2 = x * x + y * y;
            if (d2 <= EYE_R * EYE_R && d2 >= (EYE_R - 1) * (EYE_R - 1)) {
                oled_write_pixel(EYE_CX + x, EYE_CY + y, true);
            }
        }
    }

    // Filled pupil, offset by the eased gaze.
    int16_t cx = EYE_CX + px;
    int16_t cy = EYE_CY + py;
    for (int16_t y = -EYE_PR; y <= EYE_PR; y++) {
        for (int16_t x = -EYE_PR; x <= EYE_PR; x++) {
            if (x * x + y * y <= EYE_PR * EYE_PR) {
                oled_write_pixel(cx + x, cy + y, true);
            }
        }
    }
}

static void eye_update_and_draw(void) {
    // Resolve the gaze target into a pixel offset, honoring optional inversion.
    float tx = g_eye_tx / 100.0f * EYE_MAX_OFFSET;
    float ty = g_eye_ty / 100.0f * EYE_MAX_OFFSET;
#if EYE_INVERT_X
    tx = -tx;
#endif
#if EYE_INVERT_Y
    ty = -ty;
#endif

    // Inertia: ease the pupil toward the target.
    pupil_x += (tx - pupil_x) * EYE_INERTIA;
    pupil_y += (ty - pupil_y) * EYE_INERTIA;

    // Blink scheduling (semi-random interval).
    if (blinking) {
        if (timer_elapsed32(blink_timer) > EYE_BLINK_DURATION_MS) {
            blinking    = false;
            blink_timer = timer_read32();
            blink_len   = EYE_BLINK_MIN_MS + (rand() % (EYE_BLINK_MAX_MS - EYE_BLINK_MIN_MS + 1));
        }
    } else if (timer_elapsed32(blink_timer) > blink_len) {
        blinking    = true;
        blink_timer = timer_read32();
    }

    eye_draw((int16_t)(pupil_x + (pupil_x >= 0 ? 0.5f : -0.5f)),
             (int16_t)(pupil_y + (pupil_y >= 0 ? 0.5f : -0.5f)),
             blinking);
}

/* ------------------------------- Render ---------------------------------- */

void render_slave_oled(void) {
    static uint32_t frame_timer = 0;
    static uint32_t temp_timer  = 0;
    static int      temp_c      = 0;

    oled_on(); // ever-present: never sleep the eye

    if (timer_elapsed32(frame_timer) < EYE_FRAME_MS) {
        return;
    }
    frame_timer = timer_read32();

    eye_update_and_draw();

    char buf[8];

    // Section divider.
    oled_set_cursor(0, ROW_DIV1);
    oled_write_P(PSTR("-----"), false);

    // WPM.
    oled_set_cursor(0, ROW_WPM_LABEL);
    oled_write_P(PSTR("WPM"), false);
    snprintf(buf, sizeof(buf), "%03d", get_current_wpm());
    oled_set_cursor(0, ROW_WPM_VALUE);
    oled_write(buf, false);

    // Section divider.
    oled_set_cursor(0, ROW_DIV2);
    oled_write_P(PSTR("-----"), false);

    // RP2040 (stacked: "RP2040" does not fit in 5 chars per line).
    oled_set_cursor(0, ROW_RP1);
    oled_write_P(PSTR("RP"), false);
    oled_set_cursor(0, ROW_RP2);
    oled_write_P(PSTR("2040"), false);

    // Temperature (refreshed ~1 Hz).
    if (timer_elapsed32(temp_timer) > 1000 || temp_timer == 0) {
        temp_c     = read_temp_c();
        temp_timer = timer_read32();
    }
    char tmp[8];
    snprintf(tmp, sizeof(tmp), "%dC", temp_c);
    snprintf(buf, sizeof(buf), "%-5s", tmp); // left-justify, pad to clear stale chars
    oled_set_cursor(0, ROW_TEMP);
    oled_write(buf, false);
}

oled_rotation_t rotate_slave(oled_rotation_t rotation) { return OLED_SLAVE_ROTATION; }

// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┐
     * │ 4 │ 5 │ 6 │
     * ├───┼───┼───┤
     * │ 1 │ 2 │ 3 │
     * └───┴───┴───┘
     */
    [0] = LAYOUT(
        KC_P4,   KC_P5,   KC_P6,
        KC_P1,   KC_P2,   KC_P3
    )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] = { 
        ENCODER_CCW_CW(KC_VOLD, KC_VOLU), 
        ENCODER_CCW_CW(KC_WH_D, KC_WH_U), 
        ENCODER_CCW_CW(KC_TRNS, KC_TRNS)
    },
};
#endif

#ifdef OLED_ENABLE
bool oled_task_user(void) {
    oled_on();

    // Host Keyboard Layer Status
    oled_write_P(PSTR(" KBD "), false);
    oled_write_P(PSTR(" KSP "), false);

    oled_write_ln_P(PSTR(""), false);

    oled_write_P(PSTR(" CEN "), false);
    oled_write_P(PSTR(" GEK "), false);
    return false;
};
#endif
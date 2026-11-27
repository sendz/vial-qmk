 /* Copyright 2022 sendz
  *
  * This program is free software: you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
  * the Free Software Foundation, either version 2 of the License, or
  * (at your option) any later version.
  *
  * This program is distributed in the hope that it will be useful,
  * but WITHOUT ANY WARRANTY; without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  * GNU General Public License for more details.
  *
  * You should have received a copy of the GNU General Public License
  * along with this program.  If not, see <http://www.gnu.org/licenses/>.
  */

#include "config_rp2040.h"
#pragma once

// #include "config_common.h"

#define OLED_DISPLAY_128X32
#define I2C1_SCL_PIN        GP3
#define I2C1_SDA_PIN        GP2
#define I2C_DRIVER I2CD1
#define OLED_BRIGHTNESS 128
#define OLED_FONT_H "keyboards/kbdksp/iteung/fonts/glcdfont.c"
// #define MASTER_RIGHT

/* ---------------------------
 * Right-half (slave) OLED: eye + WPM + RP2040 + temperature
 * ---------------------------
 */

// Custom split transaction used to push the eye gaze target master -> slave.
#define SPLIT_TRANSACTION_IDS_KB RPC_ID_KB_EYE_SYNC

// Rotation of the right-half OLED. The left half uses OLED_ROTATION_270.
// If the right screen comes out upside-down, flip this to OLED_ROTATION_90
// (and, if needed, toggle EYE_INVERT_X / EYE_INVERT_Y below).
#define OLED_SLAVE_ROTATION OLED_ROTATION_270
#define EYE_INVERT_X 0
#define EYE_INVERT_Y 0

// Eye tuning.
// EYE_INERTIA: how fast the pupil chases the target each frame, 0.0-1.0.
//   Higher = snappier / less inertia, lower = slower / more lag.
#define EYE_INERTIA 0.35f
#define EYE_FRAME_MS 50      // eye animation/update interval (ms) -> ~20 fps
#define EYE_RETURN_MS 3000   // return pupil to center after this idle time (ms)
#define EYE_MAX_OFFSET 7     // max pupil travel from center (px)
#define EYE_BLINK_MIN_MS 3000
#define EYE_BLINK_MAX_MS 5000
#define EYE_BLINK_DURATION_MS 120

#define SERIAL_USART_FULL_DUPLEX
#define SERIAL_USART_TX_PIN GP0
#define SERIAL_USART_RX_PIN GP1

#define VBUS_SENSE GP12

#define OLED_TIMEOUT 0
#define CUSTOM_OLED_TIMEOUT 10000
#define DIODE_DIRECTION COL2ROW

#define ANALOG_JOYSTICK_X_AXIS_PIN GP14
#define ANALOG_JOYSTICK_Y_AXIS_PIN GP15
#define ANALOG_JOYSTICK_SPEED_REGULATOR 15

#ifdef RGBLIGHT_ENABLE
  #define WS2812_DI_PIN GP13
  #define WS2812_PIO_USE_PIO1 // Force the usage of PIO1 peripheral, by default the WS2812 implementation uses the PIO0 peripheral

	#define RGBLIGHT_EFFECT_BREATHING
	#define RGBLIGHT_EFFECT_RAINBOW_MOOD
	#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
	#define RGBLIGHT_EFFECT_SNAKE
	#define RGBLIGHT_EFFECT_KNIGHT
	#define RGBLIGHT_EFFECT_CHRISTMAS
	#define RGBLIGHT_EFFECT_STATIC_GRADIENT
	#define RGBLIGHT_EFFECT_RGB_TEST
	#define RGBLIGHT_EFFECT_ALTERNATING
	#define RGBLIGHT_EFFECT_TWINKLE
  
  #define RGBLIGHT_LED_COUNT 16

  #define RGBLED_SPLIT { 8, 8 }

  #define RGBLIGHT_LIMIT_VAL 120
  #define RGBLIGHT_HUE_STEP 10
  #define RGBLIGHT_SAT_STEP 17
  #define RGBLIGHT_VAL_STEP 17
#endif

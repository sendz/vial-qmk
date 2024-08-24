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

#pragma once

// #include "config_common.h"

#define OLED_DISPLAY_128X32
#define I2C1_SCL_PIN        GP3
#define I2C1_SDA_PIN        GP2
#define I2C_DRIVER I2CD1
#define OLED_BRIGHTNESS 128
#define OLED_FONT_H "keyboards/kbdksp/iteung/fonts/glcdfont.c"
// #define MASTER_RIGHT

/* key matrix size */
#define MATRIX_ROWS 12
#define MATRIX_COLS 6

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

#define SERIAL_USART_FULL_DUPLEX
#define SERIAL_USART_TX_PIN GP0
#define SERIAL_USART_RX_PIN GP1

#define VBUS_SENSE GP12
// #define MASTER_LEFT

#include "config_rp2040.h"

#define OLED_TIMEOUT 0
#define CUSTOM_OLED_TIMEOUT 10000


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

	#define RGBLED_NUM 16

  #define RGBLED_SPLIT { 8, 8 }

  #define RGBLIGHT_LIMIT_VAL 120
  #define RGBLIGHT_HUE_STEP 10
  #define RGBLIGHT_SAT_STEP 17
  #define RGBLIGHT_VAL_STEP 17
#endif

#define ANALOG_JOYSTICK_X_AXIS_PIN GP14
#define ANALOG_JOYSTICK_Y_AXIS_PIN GP15
#define ANALOG_JOYSTICK_SPEED_REGULATOR 15
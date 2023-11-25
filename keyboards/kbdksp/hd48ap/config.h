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

/* USB Device descriptor parameter */
#define VENDOR_ID       0x7370
#define PRODUCT_ID      0x3438
#define DEVICE_VER      0x0001

/* key matrix size */
#define MATRIX_ROWS 8
#define MATRIX_COLS 6

/* Keyboard Matrix Assignments */
#define MATRIX_ROW_PINS { D3, D2, D7, E6, B2, B6, B5, B4 }
#define MATRIX_COL_PINS { F4, F5, F6, F7, B1, B3 }
#define UNUSED_PINS


/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE


/* COL2ROW, ROW2COL*/
#define DIODE_DIRECTION COL2ROW

/* encoder support */
#define ENCODERS_PAD_A { D4 } // 4 + 4
#define ENCODERS_PAD_B { C6 } // 4 + 4
#define ENCODER_RESOLUTION 2

#define OLED_FONT_H "fonts/glcdfont.c"
#define OLED_DISPLAY_128X64

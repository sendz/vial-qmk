/* Copyright 2023 sendz
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

 #include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0x5359
#define PRODUCT_ID      0x4953
#define DEVICE_VER      0x0001
#define MANUFACTURER    sendyyeah
#define PRODUCT         Euis

/* key matrix size */

#define MATRIX_ROWS 8
#define MATRIX_COLS 6

/* Keyboard Matrix Assignments */
// clang-format off

#define MATRIX_ROW_PINS { GP18, GP19, GP3, GP2, GP10, GP15, GP11, GP14 }
#define MATRIX_COL_PINS { GP21, GP20, GP25, GP8, GP1, GP0 }

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE


/* COL2ROW, ROW2COL*/
#define DIODE_DIRECTION COL2ROW

/* encoder support */
#define ENCODERS_PAD_A { GP12 } // 4 + 4
#define ENCODERS_PAD_B { GP13 } // 4 + 4
#define ENCODER_RESOLUTION 2
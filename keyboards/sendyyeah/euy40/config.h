 /* Copyright 2022 sendyyeah
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
#define PRODUCT_ID      0x4534
#define DEVICE_VER      0x0001
#define MANUFACTURER    sendyyeah
#define PRODUCT         Euy40 Combo

/* key matrix size */
#define MATRIX_ROWS 16
#define MATRIX_COLS 6

/* Keyboard Matrix Assignments */
#define MATRIX_ROW_PINS { F4, F5, F6, F7, B1, B3, B2, B6 }
#define MATRIX_COL_PINS { D1, D0, D4, C6, D7, E6 }
#define UNUSED_PINS


/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE


/* COL2ROW, ROW2COL*/
#define DIODE_DIRECTION COL2ROW


/*
 * Split Keyboard specific options, make sure you have 'SPLIT_KEYBOARD = yes' in your rules.mk, and define SOFT_SERIAL_PIN.
 */
#define SOFT_SERIAL_PIN D3  // or D1, D2, D3, E6

/* encoder support */
#define ENCODERS_PAD_A { B4 }
#define ENCODERS_PAD_B { B5 }
#define ENCODERS_PAD_A_RIGHT { B4 }
#define ENCODERS_PAD_B_RIGHT { B5 }
#define ENCODER_RESOLUTION 2

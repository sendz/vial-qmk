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

/* key matrix size */
#define MATRIX_ROWS 10
#define MATRIX_COLS 6

/* Keyboard Matrix Assignments */
#define MATRIX_ROW_PINS { GP29, GP28, GP15, GP26, GP27 }
#define MATRIX_COL_PINS { GP9, GP8, GP7, GP4, GP5, GP6 }

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* COL2ROW, ROW2COL*/
#define DIODE_DIRECTION COL2ROW

/* encoder support */
#define ENCODERS_PAD_A { GP10 } // 4 + 4
#define ENCODERS_PAD_B { GP11 } // 4 + 4
#define ENCODER_RESOLUTION 2

#define SERIAL_USART_FULL_DUPLEX
#define SERIAL_USART_TX_PIN GP0
#define SERIAL_USART_RX_PIN GP1

#define MASTER_LEFT

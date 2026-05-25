 /* Copyright 2020 sendyyeah
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

#include QMK_KEYBOARD_H

#define LAYERNUM 2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(KC_MUTE, KC_MPLY, KC_MPRV, KC_MNXT, TO(1)),
    [1] = LAYOUT(KC_TRNS, KC_MSTP, KC_MRWD, KC_MFFD, TO(2)),
    // [2] = LAYOUT(KC_LSFT, UG_NEXT, UG_HUEU, UG_SATU, TO(0))
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][1][2] = {
    [0] =   { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [1] =   { ENCODER_CCW_CW(KC_PGUP, KC_PGDN)  },
    // [2] =   { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  }
};
#endif
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
#include QMK_KEYBOARD_H
#include <stdio.h>

// Defines names for use in layer keycodes and the keymap
enum layer_names {
  _QWERTY = 0,
  _RAISE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_ortho(
                    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
                    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_MUTE,    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
        KC_MUTE,    KC_LCTL, KC_LALT, KC_LALT, KC_LGUI,  _RAISE, _RAISE, KC_SPC,  KC_SPC,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
    ),

    [_RAISE] = LAYOUT_ortho(
                    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
                    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
        _______,    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______,
        _______,    _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
    ),
};

#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand

    return rotation;
}

bool oled_task_user(void) {

    static const char PROGMEM ICON_LAYER[] = {0x80, 0x81, 0x82, 0x83, 0};
    static const char PROGMEM KDBKSP[] = {0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0};

    oled_write_P(ICON_LAYER, false);

    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_P(PSTR("QWERTY"), false);
        break;
        case 1:
            oled_write_P(PSTR("LOWER "), false);
        break;
        case 2:
            oled_write_P(PSTR("RAISE "), false);
        break;
        case 3:
            oled_write_P(PSTR("ADJUST"), false);
        break;
        default:
            oled_write_P(PSTR("UNDEF "), false);
    }

    oled_write_P(PSTR("   "), false);
    oled_write_P(KDBKSP, false);
    return false;
}

#endif

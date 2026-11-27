/* Copyright 2020 Josef Adamcik
 * Modification for VIA support and RGB underglow by Jens Bonk-Wiltfang
 * Modification for Vial support by Drew Petersen
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

// clang-format off

#include <stdio.h>
char wpm_str[10];
#include QMK_KEYBOARD_H

// Default keymap. This can be changed in Vial. Use oled.c to change beavior that Vial cannot change.

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY WINDOWS
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[0] = LAYOUT(
  KC_ESC,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_DEL,
  KC_TAB,   KC_A,   KC_S,    KC_D,    KC_F,    KC_G, KC_MUTE,                    XXXXXXX, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT,
                 KC_LGUI,KC_LALT,KC_LCTL, MO(1), KC_SPC,                              KC_ENT,  MO(2), KC_MINS, KC_EQL, KC_RGUI
),
/* LOWER
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   |  |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * | Shift|  =   |  -   |  +   |   {  |   }  |-------|    |-------|   [  |   ]  |   ;  |   :  |   \  | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[1] = LAYOUT(
  KC_GRV,  _______, _______, _______,  _______, _______,                                           KC_PGUP, KC_HOME, KC_UP,   KC_END,  _______,  _______,
  _______, _______, RGB_TOG, RGB_MOD,  RGB_VAI, _______, _______,                         _______, KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT, _______, _______,
  KC_CAPS, _______, _______, RGB_RMOD, RGB_VAD, _______, _______, _______,       _______, _______, _______, _______, _______, _______, _______, _______,
                    _______, _______,  _______, _______, _______,                         _______, _______, _______, _______, _______
),
/* RAISE
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Esc  | Ins  | Pscr | Menu |      |      |                    |      | PWrd |  Up  | NWrd | DLine| Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  | LAt  | LCtl |LShift|      | Caps |-------.    ,-------|      | Left | Down | Rigth|  Del | Bspc |
 * |------+------+------+------+------+------|  MUTE  |    |       |------+------+------+------+------+------|
 * |Shift | Undo |  Cut | Copy | Paste|      |-------|    |-------|      | LStr |      | LEnd |      | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[2] = LAYOUT(
  _______, KC_INS,  KC_PSCR,   KC_APP,  XXXXXXX,  XXXXXXX,                                       KC_PGUP,  _______, KC_UP,   _______,  _______, KC_BSPC,
  _______, KC_LALT, KC_LCTL,   KC_LSFT, XXXXXXX,  KC_CAPS,  _______,                    _______, KC_PGDN,  KC_LEFT, KC_DOWN, KC_RGHT,  KC_DEL,  KC_BSPC,
  _______, KC_UNDO, KC_CUT,    KC_COPY, KC_PASTE, XXXXXXX,  _______, _______,  _______, _______, XXXXXXX,  _______, XXXXXXX, _______,  XXXXXXX, _______,
                    _______, _______, _______, _______, _______,                          _______, _______, _______, _______, _______
),
/*
 * COLEMAK
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   Q  |   W  |   F  |   P  |   G  |                    |   J  |   L  |   U  |   Y  |   ;  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |   A  |   R  |   S  |   T  |   D  |-------.    ,-------|   H  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   K  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[3] = LAYOUT(
  KC_ESC,   KC_Q,   KC_W,    KC_F,    KC_P,    KC_G,                                        KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN,  KC_BSPC,
  KC_TAB,   KC_A,   KC_R,    KC_S,    KC_T,    KC_D, KC_MUTE,                      XXXXXXX, KC_H,    KC_N,    KC_E,    KC_I,    KC_O,  KC_QUOT,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, KC_K,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT,
                    KC_LGUI, KC_LALT, KC_LCTL, KC_TRNS, KC_ENT,                  KC_SPC,  KC_TRNS, KC_RCTL, KC_RALT, KC_RGUI
),
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_WH_D, KC_WH_U) },
    [1] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [2] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [3] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
};
#endif

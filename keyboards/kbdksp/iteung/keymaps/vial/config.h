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

// clang-format off

#pragma once

// Vial Support
#define VIAL_KEYBOARD_UID {0x6C, 0x4E, 0xA2, 0x1E, 0x08, 0xE7, 0xF3, 0x09}

#define VIAL_ENCODER_DEFAULT { \
    KC_VOLU, KC_VOLD, \
    KC_PGUP, KC_PGDN, \
    KC_TRNS, KC_TRNS, \
    KC_TRNS, KC_TRNS, \
    KC_TRNS, KC_TRNS, \
    KC_TRNS, KC_TRNS, \
    KC_TRNS, KC_TRNS, \
    KC_TRNS, KC_TRNS \
}

#define DYNAMIC_KEYMAP_LAYER_COUNT 10

/* ---------------------------
 * Common Spit Configuration
 * ---------------------------
 */
#define SPLIT_OLED_ENABLE

/* ---------------------------
 * Common Bootmagic Lite
 * ---------------------------
 */
#define BOOTMAGIC_LITE_ROW 0
#define BOOTMAGIC_LITE_COLUMN 0

/* ---------------------------
 * Common RGB Configuration
 * ---------------------------
 */
#ifdef RGB_MATRIX_ENABLE
    #define RGB_DISABLE_WHEN_USB_SUSPENDED
    #define RGB_DISABLE_TIMEOUT CUSTOM_OLED_TIMEOUT
    #define RGB_MATRIX_MAXIMUM_BRIGHTNESS 128
    #define RGB_MATRIX_DEFAULT_HUE 215
    #define RGB_MATRIX_DEFAULT_SAT 255
    #define RGB_MATRIX_DEFAULT_VAL RGB_MATRIX_MAXIMUM_BRIGHTNESS
#endif

/* ---------------------------
 * Common other Configuration
 * ---------------------------
 */
#define ENABLE_COMPILE_KEYCODE

#define VIAL_UNLOCK_COMBO_ROWS { 0, 0 }
#define VIAL_UNLOCK_COMBO_COLS { 0, 3 }

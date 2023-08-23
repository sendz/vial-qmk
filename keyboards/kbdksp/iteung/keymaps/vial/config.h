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

#define DYNAMIC_KEYMAP_LAYER_COUNT 4

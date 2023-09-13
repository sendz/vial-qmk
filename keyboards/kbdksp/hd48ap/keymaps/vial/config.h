/* SPDX-License-Identifier: GPL-2.0-or-later */

#pragma once

#define VIAL_KEYBOARD_UID {0x66, 0x8F, 0x22, 0x2F, 0x54, 0xB4, 0xD9, 0x99}

#define VIAL_ENCODER_DEFAULT { \
    KC_VOLU, KC_VOLD, \
    KC_TRNS, KC_TRNS, \
    KC_TRNS, KC_TRNS, \
}

#define DYNAMIC_KEYMAP_LAYER_COUNT 3

/* encoder support */
#define ENCODERS_PAD_A { D4 } // 4 + 4
#define ENCODERS_PAD_B { C6 } // 4 + 4
#define ENCODER_RESOLUTION 2

#define OLED_FONT_H "fonts/glcdfont.c"
#define OLED_DISPLAY_128X64
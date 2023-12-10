// Copyright 2022 Jose Pablo Ramirez (@jpe230)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "jpe230.h"

static const char PROGMEM ICON_LAYER[] = {0x80, 0x81, 0x82, 0x83, 0};

void render_master_oled(void) {
    oled_on();

    oled_write_ln(ICON_LAYER, false);

    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_P(PSTR("QWERT"), false);
        break;
        case 1:
            oled_write_P(PSTR("LOWER"), false);
        break;
        case 2:
            oled_write_P(PSTR("RAISE"), false);
        break;
        case 3:
            oled_write_P(PSTR("ADJST"), false);
        break;
        default:
            oled_write_P(PSTR("UNDEF"), false);
    }
}

oled_rotation_t rotate_master(oled_rotation_t rotation) {return OLED_ROTATION_270;}

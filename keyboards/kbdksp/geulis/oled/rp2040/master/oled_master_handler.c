// Copyright 2022 Jose Pablo Ramirez (@jpe230)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "jpe230.h"

// static const char PROGMEM ICON_LAYER[] = {0x80, 0x81, 0x82, 0x83, 0};

void render_master_oled(void) {
    oled_on();

    oled_write_P(PSTR(" KBD "), false);
    oled_write_P(PSTR(" KSP "), false);

    oled_write_ln_P(PSTR(""), false);

    oled_write_P(PSTR(" ITE "), false);
    oled_write_P(PSTR(" UNG "), false);

    oled_write_ln_P(PSTR(""), false);
    oled_write_P(PSTR("_____"), false);
    oled_write_ln_P(PSTR(""), false);
    oled_write_ln_P(PSTR(""), false);

    char layer_string[8] = {0};
    sprintf(layer_string, "LYR %d", get_highest_layer(layer_state));
    oled_write(layer_string, false);
    
    oled_write_ln_P(PSTR(""), false);

    led_t led_usb_state = host_keyboard_led_state();
    oled_write_P(PSTR("CAPS "), led_usb_state.caps_lock);
    oled_write_P(PSTR("SHIFT"), shift_pressed);
    oled_write_P(PSTR("CTRL "), ctrl_pressed);
    oled_write_P(PSTR("GUI  "), gui_pressed);
    oled_write_P(PSTR("ALT  "), alt_pressed);
}

oled_rotation_t rotate_master(oled_rotation_t rotation) {return OLED_ROTATION_270;}

// Copyright 2022 Jose Pablo Ramirez (@jpe230)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "jpe230.h"
#ifdef OLED_ENABLE
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        oled_timer_reset();
        set_keylog(keycode, record);

        switch (keycode) {
            case QK_BOOT:
                // rgb_matrix_set_color_all(30, 0, 0);
                // rgb_matrix_driver.flush();
                oled_off();
                return true;
        }
    }
    return true;
}

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
switch (keycode) {
            case KC_LSFT:
            case KC_RSFT:
                if (record->event.pressed) {
                    shift_pressed = true;
                } else {
                    shift_pressed = false;
                }
                break;
            case KC_LALT:
            case KC_RALT:
                if (record->event.pressed) {
                    alt_pressed = true;
                } else {
                    alt_pressed = false;
                }
                break;
            case KC_LCTL:
            case KC_RCTL:
                if (record->event.pressed) {
                    ctrl_pressed = true;
                } else {
                    ctrl_pressed = false;
                }
                break;
            case KC_LGUI:
            case KC_RGUI:
                if (record->event.pressed) {
                    gui_pressed = true;
                } else {
                    gui_pressed = false;
                }
            break;
            default:
                gui_pressed = false;
                ctrl_pressed = false;
                alt_pressed = false;
                shift_pressed = false;
        }
}
#endif
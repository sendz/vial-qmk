// Copyright 2022 Jose Pablo Ramirez (@jpe230)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include QMK_KEYBOARD_H

bool shift_pressed;
bool alt_pressed;
bool ctrl_pressed;
bool gui_pressed;

/* ---------------------------
 * Eye gaze target (right-half OLED)
 * ---------------------------
 * Range -100..100. On the master these are computed from the last keypress;
 * they are then pushed to the slave over RPC_ID_KB_EYE_SYNC. The slave eases
 * the rendered pupil toward this target.
 */
extern int8_t g_eye_tx;
extern int8_t g_eye_ty;

/* ---------------------------
 * Custom OLED Fncs Prototypes
 * ---------------------------
 */
void render_slave_oled(void);
void render_master_oled(void);
void oled_timer_reset(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);

// Copyright 2022 Jose Pablo Ramirez (@jpe230)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "jpe230.h"
#include "transactions.h"
#ifdef OLED_ENABLE
uint8_t logged_row;
uint8_t logged_col;
uint32_t oled_timer = 0;

// Eye gaze target, shared with the slave OLED renderer (see jpe230.h).
int8_t g_eye_tx = 0;
int8_t g_eye_ty = 0;
// Timestamp of the last keypress on the master, used to recenter the eye.
static uint32_t eye_input_timer = 0;

// Map a keypress (matrix position) to an eye gaze target.
// Horizontal: derived from the key's physical column relative to board center.
//   Left half  -> look left, right half -> look right.
// Vertical: derived from the matrix row.
//   number row -> up, home row -> ~neutral, bottom row / thumbs -> down.
// This reproduces: 6 -> up-right, n -> down-right, w -> left, b -> down-left.
static void eye_set_target_from_key(keyrecord_t *record) {
    uint8_t row = record->event.key.row; // logical row 0..11 (left 0-5, right 6-11)
    uint8_t col = record->event.key.col; // 0..5
    bool    right = row >= 6;
    uint8_t vis_row = row % 6;            // 0 num, 1 top, 2 home, 3 bottom, 4/5 thumb

    // Physical x across the whole board (0=far left .. 14=far right), center = 7.
    // Left half:  x = col (0..5). Right half: x = 14 - col (9..14).
    int16_t phys_x = right ? (14 - (int16_t)col) : (int16_t)col;
    int16_t tx = (phys_x - 7) * 100 / 7; // -100..100

    int16_t ty;
    switch (vis_row) {
        case 0:  ty = -100; break; // number row -> up
        case 1:  ty =  -10; break; // top alpha  -> ~neutral
        case 2:  ty =   25; break; // home row   -> slightly down
        case 3:  ty =   80; break; // bottom row -> down
        default: ty =  100; break; // thumb cluster -> down
    }

    if (tx > 100) tx = 100; else if (tx < -100) tx = -100;
    g_eye_tx = (int8_t)tx;
    g_eye_ty = (int8_t)ty;
    eye_input_timer = timer_read32();
}

// Slave-side: receive the gaze target pushed by the master.
static void eye_sync_handler(uint8_t in_buflen, const void *in_data, uint8_t out_buflen, void *out_data) {
    if (in_buflen >= 2) {
        const int8_t *d = (const int8_t *)in_data;
        g_eye_tx = d[0];
        g_eye_ty = d[1];
    }
}

void keyboard_post_init_kb(void) {
    transaction_register_rpc(RPC_ID_KB_EYE_SYNC, eye_sync_handler);
    keyboard_post_init_user();
}

void housekeeping_task_kb(void) {
    if (is_keyboard_master()) {
        static uint32_t last_send = 0;
        // Recenter the eye after a period of no typing.
        if (timer_elapsed32(eye_input_timer) > EYE_RETURN_MS) {
            g_eye_tx = 0;
            g_eye_ty = 0;
        }
        if (timer_elapsed32(last_send) > 50) {
            int8_t payload[2] = {g_eye_tx, g_eye_ty};
            if (transaction_rpc_send(RPC_ID_KB_EYE_SYNC, sizeof(payload), payload)) {
                last_send = timer_read32();
            }
        }
    }
    housekeeping_task_user();
}

__attribute__ ((weak)) void handle_oled_keypress(uint16_t keycode, keyrecord_t *record) {}

__attribute__ ((weak)) oled_rotation_t rotate_master(oled_rotation_t rotation) {return rotation;}
__attribute__ ((weak)) oled_rotation_t rotate_slave(oled_rotation_t rotation) {return rotation;}

void oled_timer_reset(void) { oled_timer = timer_read32(); }

oled_rotation_t oled_init_user(oled_rotation_t rotation) {

    if (!is_keyboard_master()) {
        return rotate_slave(rotation);
    }

    return rotate_master(rotation);
}


void set_keylog(uint16_t keycode, keyrecord_t *record) {
    logged_row = record->event.key.row;
    logged_col = record->event.key.col;

    eye_set_target_from_key(record);

    handle_oled_keypress(keycode, record);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        render_master_oled();
    } else {
        render_slave_oled();
    }
    return false;
}
#endif
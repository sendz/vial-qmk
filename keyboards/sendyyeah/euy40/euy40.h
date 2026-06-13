/* Copyright 2022 sendyyeah
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

#pragma once

#include "quantum.h"

/* This is a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */

#define LAYOUT_ortho_macropad(\
    L00, L10, L01, L11, L02, L12, L03, L13, L04, L14, L05, L15,     R00, R10, R01, R11, \
    L20, L30, L21, L31, L22, L32, L23, L33, L24, L34, L25, L35,     R20, R30, R21, R31, \
    L40, L50, L41, L51, L42, L52, L43, L53, L44, L54, L45, L55,     R40, R50, R41, R51, \
    L60, L70, L61, L71, L62, L72, L63, L73, L64, L74, L65, L75,     R60, R70, R61, R71  \
) \
{ \
    { L00, L01, L02, L03, L04, L05 }, \
    { L10, L11, L12, L13, L14, L15 }, \
    { L20, L21, L22, L23, L24, L25 }, \
    { L30, L31, L32, L33, L34, L35 }, \
    { L40, L41, L42, L43, L44, L45 }, \
    { L50, L51, L52, L53, L54, L55 }, \
    { L60, L61, L62, L63, L64, L65 }, \
    { L70, L71, L72, L73, L74, L75 }, \
    { R00, R01, KC_NO, KC_NO, KC_NO, KC_NO }, \
    { R10, R11, KC_NO, KC_NO, KC_NO, KC_NO }, \
    { R20, R21, KC_NO, KC_NO, KC_NO, KC_NO }, \
    { R30, R31, KC_NO, KC_NO, KC_NO, KC_NO }, \
    { R40, R41, KC_NO, KC_NO, KC_NO, KC_NO }, \
    { R50, R51, KC_NO, KC_NO, KC_NO, KC_NO }, \
    { R60, R61, KC_NO, KC_NO, KC_NO, KC_NO }, \
    { R70, R71, KC_NO, KC_NO, KC_NO, KC_NO } \
}

#define LAYOUT_ortho_longboi(\
    L00, L10, L01, L11, L02, L12, L03, L13, L04, L14, L05, L15,     R00, R10, R01, R11, R02, R12, R03, R13, R04, R14, R05, R15, \
    L20, L30, L21, L31, L22, L32, L23, L33, L24, L34, L25, L35,     R20, R30, R21, R31, R22, R32, R23, R33, R24, R34, R25, R35, \
    L40, L50, L41, L51, L42, L52, L43, L53, L44, L54, L45, L55,     R40, R50, R41, R51, R42, R52, R43, R53, R44, R54, R45, R55, \
    L60, L70, L61, L71, L62, L72, L63, L73, L64, L74, L65, L75,     R60, R70, R61, R71, R62, R72, R63, R73, R64, R74, R65, R75  \
) \
{ \
    { L00, L01, L02, L03, L04, L05 }, \
    { L10, L11, L12, L13, L14, L15 }, \
    { L20, L21, L22, L23, L24, L25 }, \
    { L30, L31, L32, L33, L34, L35 }, \
    { L40, L41, L42, L43, L44, L45 }, \
    { L50, L51, L52, L53, L54, L55 }, \
    { L60, L61, L62, L63, L64, L65 }, \
    { L70, L71, L72, L73, L74, L75 }, \
    { R00, R01, R02, R03, R04, R05 }, \
    { R10, R11, R12, R13, R14, R15 }, \
    { R20, R21, R22, R23, R24, R25 }, \
    { R30, R31, R32, R33, R34, R35 }, \
    { R40, R41, R42, R43, R44, R45 }, \
    { R50, R51, R52, R53, R54, R55 }, \
    { R60, R61, R62, R63, R64, R65 }, \
    { R70, R71, R72, R73, R74, R75 }, \
}

/* Copyright 2022 sendz
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

#define LAYOUT_ortho(\
    L00, L10, L01, L11, L02, L12, L03, L13, L04, L14, L05, L15, \
    L20, L30, L21, L31, L22, L32, L23, L33, L24, L34, L25, L35, \
    L40, L50, L41, L51, L42, L52, L43, L53, L44, L54, L45, L55, \
    L60, L70, L61, L71, L62, L72, L63, L73, L64, L74, L65, L75 \
) \
{ \
    { L00, L01, L02, L03, L04, L05 }, \
    { L10, L11, L12, L13, L14, L15 }, \
    { L20, L21, L22, L23, L24, L25 }, \
    { L30, L31, L32, L33, L34, L35 }, \
    { L40, L41, L42, L43, L44, L45 }, \
    { L50, L51, L52, L53, L54, L55 }, \
    { L60, L61, L62, L63, L64, L65 }, \
    { L70, L71, L72, L73, L74, L75 } \
}

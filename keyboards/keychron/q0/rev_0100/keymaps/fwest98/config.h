/* Copyright 2022 @ Keychron (https://www.keychron.com)
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

/* Set dynamic keymap layer counts */
#define DYNAMIC_KEYMAP_LAYER_COUNT 8

// Unicode config
#define UNICODE_SELECTED_MODES UC_WINC

/* RGB Matrix Configuration */
#ifdef RGB_MATRIX_ENABLE
#    define RGB_DISABLE_WHEN_USB_SUSPENDED
#    define RGB_MATRIX_KEYPRESSES
#    define RGB_MATRIX_FRAMEBUFFER_EFFECTS

#    define NUM_LOCK_ON_COLOR RGB_OFF
#    define NUM_LOCK_OFF_COLOR RGB_RED
#    define NUM_LOCK_INDICATOR_LIGHT_NUMS

#    define LAYER_1_COLOR RGB_OFF
#    define LAYER_2_COLOR RGB_YELLOW
#    define LAYER_3_COLOR RGB_GREEN
#    define LAYER_4_COLOR RGB_BLUE

#    define FN_LAYER_TRANSPARENT_KEYS_OFF
#endif

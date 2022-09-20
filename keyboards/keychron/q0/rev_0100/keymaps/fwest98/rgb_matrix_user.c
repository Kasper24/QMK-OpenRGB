/* Copyright 2021 @ Grayson Carr
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

#include QMK_KEYBOARD_H
#include "keymap_setup.h"
#include "rgb_matrix_user.h"

keypos_t led_index_key_position[DRIVER_LED_TOTAL];

// Initialise RGB matrix; invert the mapping of g_led_config.matrix_co,
// so instead of a mapping from key position to led index, we now create
// led intex to key position.
void rgb_matrix_init_user(void) {
    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        for (uint8_t col = 0; col < MATRIX_COLS; col++) {
            uint8_t led_index = g_led_config.matrix_co[row][col];
            if (led_index != NO_LED) {
                led_index_key_position[led_index] = (keypos_t){.row = row, .col = col};
            }
        }
    }
}

// Callback by QMK for advanced indicators
void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    uint8_t current_layer = get_highest_layer(layer_state);
    switch (current_layer) {
        case FN_1:
#ifdef FN_LAYER_TRANSPARENT_KEYS_OFF
            rgb_matrix_set_color_by_keycode(led_min, led_max, current_layer, is_transparent, RGB_OFF);
#endif
            // Fall-through for layer colours

        case BASE_1:
#ifdef LAYER_1_COLOR // Layer-specific colour
            if (!rgb_color_is_transparent(LAYER_1_COLOR)) {
                rgb_matrix_set_color_by_keycode(led_min, led_max, current_layer, not_transparent, LAYER_1_COLOR);
            }
#endif
#ifdef NUM_LOCK_ON_COLOR // Custom colour when numlock is on
            if (!rgb_color_is_transparent(NUM_LOCK_ON_COLOR) && host_keyboard_led_state().num_lock) {
                rgb_matrix_set_color_by_keycode(led_min, led_max, current_layer, is_num_lock_indicator, NUM_LOCK_ON_COLOR);
            }
#endif
#ifdef NUM_LOCK_OFF_COLOR // Custom colour when numlock if off
            if (!rgb_color_is_transparent(NUM_LOCK_OFF_COLOR) && !host_keyboard_led_state().num_lock) {
                rgb_matrix_set_color_by_keycode(led_min, led_max, current_layer, is_num_lock_indicator, NUM_LOCK_OFF_COLOR);
            }
#endif
            break;

        case FN_2:
#ifdef FN_LAYER_TRANSPARENT_KEYS_OFF
            rgb_matrix_set_color_by_keycode(led_min, led_max, current_layer, is_transparent, RGB_OFF);
#endif
            // Fall-through for layer colours

        case BASE_2:
#ifdef LAYER_2_COLOR // Layer-specific colour
            if (!rgb_color_is_transparent(LAYER_2_COLOR)) {
                rgb_matrix_set_color_by_keycode(led_min, led_max, current_layer, not_transparent, LAYER_2_COLOR);
            }
#endif
            break;

        case FN_3:
#ifdef FN_LAYER_TRANSPARENT_KEYS_OFF
            rgb_matrix_set_color_by_keycode(led_min, led_max, current_layer, is_transparent, RGB_OFF);
#endif
            // Fall-through for layer colours

        case BASE_3:
#ifdef LAYER_3_COLOR // Layer-specific colour
            if (!rgb_color_is_transparent(LAYER_3_COLOR)) {
                rgb_matrix_set_color_by_keycode(led_min, led_max, current_layer, not_transparent, LAYER_3_COLOR);
            }
#endif
            break;

        case FN_4:
#ifdef FN_LAYER_TRANSPARENT_KEYS_OFF
            rgb_matrix_set_color_by_keycode(led_min, led_max, current_layer, is_transparent, RGB_OFF);
#endif
            // Fall-through for layer colours

        case BASE_4:
#ifdef LAYER_4_COLOR // Layer-specific colour
            if (!rgb_color_is_transparent(LAYER_4_COLOR)) {
                rgb_matrix_set_color_by_keycode(led_min, led_max, current_layer, not_transparent, LAYER_4_COLOR);
            }
#endif
            break;
    }
}

void rgb_matrix_set_color_by_keycode(uint8_t led_min, uint8_t led_max, uint8_t layer, bool (*is_keycode)(uint16_t), uint8_t red, uint8_t green, uint8_t blue) {
    for (uint8_t i = led_min; i < led_max; i++) {
        uint16_t keycode = keymap_key_to_keycode(layer, led_index_key_position[i]);
        if ((*is_keycode)(keycode)) {
            rgb_matrix_set_color(i, red, green, blue);
        }
    }
}

bool rgb_color_is_transparent(uint8_t red, uint8_t green, uint8_t blue) {
    // We define "off"/"black" to be "transparent" aka we don't modify the colors
    return (red == 0 && green == 0 && blue == 0);
}

bool is_num_lock_indicator(uint16_t keycode) {
#ifdef NUM_LOCK_INDICATOR_LIGHT_NUMS
    return (KC_P1 <= keycode && keycode <= KC_P0) || keycode == KC_NUMLOCK || keycode == KC_PDOT;
#else
    return keycode == KC_NUMLOCK;
#endif
}

bool is_transparent(uint16_t keycode) { return keycode == KC_TRNS; }
bool not_transparent(uint16_t keycode) { return !is_transparent(keycode); }

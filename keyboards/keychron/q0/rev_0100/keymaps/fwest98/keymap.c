/* Copyright 2021 @ Keychron (https://www.keychron.com)
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
#ifdef RGB_MATRIX_ENABLE
#    include "rgb_matrix_user.h"
#endif

enum custom_keycodes {
    KC_DRGB = USER00
};

const uint32_t PROGMEM unicode_map[] = {
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE_1] = LAYOUT_numpad_6x4(
        MO(FN_1),   KC_ESC,  KC_BSPACE, KC_TAB,
        KC_NUMLOCK, KC_PSLS, KC_PAST,   KC_PMNS,
        KC_P7,      KC_P8,   KC_P9,
        KC_P4,      KC_P5,   KC_P6,     KC_PPLS,
        KC_P1,      KC_P2,   KC_P3,
        KC_P0,               KC_PDOT,   KC_PENT),

    [FN_1] = LAYOUT_numpad_6x4(
        KC_NO,      TO(BASE_2), TO(BASE_3), TO(BASE_4),
        RGB_MOD,    RGB_VAI,    EE_CLR,     QK_BOOT,
        RGB_RMOD,   RGB_VAD,    RGB_HUD,
        RGB_SAI,    RGB_SPI,    KC_MPRV,    KC_DRGB,
        RGB_SAD,    RGB_SPD,    KC_MPLY,
        RGB_TOG,                KC_MNXT,    KC_TRNS),

    [BASE_2] = LAYOUT_numpad_6x4(
        KC_NO,      MO(FN_2), KC_NO,     KC_NO,
        KC_NO,      KC_NO,    KC_NO,     KC_NO,
        KC_NO,      KC_NO,    KC_NO,
        KC_NO,      KC_NO,    KC_NO,     KC_NO,
        KC_NO,      KC_NO,    KC_NO,
        KC_NO,                KC_NO,     KC_NO),

    [FN_2] = LAYOUT_numpad_6x4(
        TO(BASE_1), KC_TRNS, TO(BASE_3), TO(BASE_4),
        KC_TRNS,    KC_TRNS, KC_TRNS,    KC_TRNS,
        KC_TRNS,    KC_TRNS, KC_TRNS,
        KC_TRNS,    KC_TRNS, KC_TRNS,    KC_TRNS,
        KC_TRNS,    KC_TRNS, KC_TRNS,
        KC_TRNS,             KC_TRNS,    KC_TRNS),

    [BASE_3] = LAYOUT_numpad_6x4(
        KC_NO,      KC_NO,   MO(FN_3),   KC_NO,
        KC_NO,      KC_NO,   KC_CALC,    KC_NO,
        KC_NO,      KC_NO,   KC_NO,
        KC_NO,      KC_NO,   KC_NO,      KC_NO,
        KC_NO,      KC_NO,   KC_NO,
        KC_NO,               KC_NO,      KC_NO),

    [FN_3] = LAYOUT_numpad_6x4(
        TO(BASE_1), TO(BASE_2), KC_TRNS, TO(BASE_4),
        KC_TRNS,    KC_TRNS,    KC_TRNS,  KC_TRNS,
        KC_TRNS,    KC_TRNS,    KC_TRNS,
        KC_TRNS,    KC_TRNS,    KC_TRNS,  KC_TRNS,
        KC_TRNS,    KC_TRNS,    KC_TRNS,
        KC_TRNS,                KC_TRNS,  KC_TRNS),

    [BASE_4] = LAYOUT_numpad_6x4(
        KC_NO,      KC_NO,   KC_NO,     MO(FN_4),
        KC_NO,      KC_NO,   KC_NO,     KC_NO,
        KC_NO,      KC_NO,   KC_NO,
        KC_NO,      KC_NO,   KC_NO,     KC_NO,
        KC_NO,      KC_NO,   KC_NO,
        KC_NO,               KC_NO,     KC_NO),

    [FN_4] = LAYOUT_numpad_6x4(
        TO(BASE_1), TO(BASE_2), TO(BASE_3), KC_TRNS,
        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
        KC_TRNS,    KC_TRNS,    KC_TRNS,
        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
        KC_TRNS,    KC_TRNS,    KC_TRNS,
        KC_TRNS,                KC_TRNS,    KC_TRNS)
};

void matrix_init_user(void) {
#   ifdef RGB_MATRIX_ENABLE
    rgb_matrix_init_user();
#   endif
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Enable RGB on any keypress if currently disabled after hotkey
    static bool rgb_sleep = false;
    if(rgb_sleep && record->event.pressed) {
        rgb_matrix_enable_noeeprom();
        rgb_sleep = false;
    }

    switch (keycode) {
        // Disable RGB on custom keycode
        case KC_DRGB:
            if (record->event.pressed && rgb_matrix_is_enabled()) {
                rgb_matrix_disable_noeeprom();
                rgb_sleep = true;
            }
            return false; // no further processing of this custom key

        default:
            return true;
    }
}

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
    KC_MISSION_CONTROL = USER00,
    KC_LAUNCHPAD,
    KC_LOPTN,
    KC_ROPTN,
    KC_LCMMD,
    KC_RCMMD,
    KC_SIRI,
    KC_TASK_VIEW,
    KC_FILE_EXPLORER,
    KC_SCREEN_SHOT,
    KC_CORTANA
};

#define KC_MCTL KC_MISSION_CONTROL
#define KC_LPAD KC_LAUNCHPAD
#define KC_TASK KC_TASK_VIEW
#define KC_FLXP KC_FILE_EXPLORER
#define KC_SNAP KC_SCREEN_SHOT
#define KC_CRTA KC_CORTANA

typedef struct PACKED {
    uint8_t len;
    uint8_t keycode[3];
} key_combination_t;

key_combination_t key_comb_list[4] = {
    {2, {KC_LWIN, KC_TAB}},
    {2, {KC_LWIN, KC_E}},
    {3, {KC_LSFT, KC_LCMD, KC_4}},
    {2, {KC_LWIN, KC_C}}
};

static uint8_t mac_keycode[4] = { KC_LOPT, KC_ROPT, KC_LCMD, KC_RCMD };

enum unicode_names {
    ALPHA, BETA, GAMMA, GGAMMA, DELTA, DDELTA, EPSILON, ZETA, ETA, THETA, TTHETA, IOTA, KAPPA, LAMBDA, LLAMBDA,
    MU, NU, XI, XXI, PI, PPI, RHO, SIGMA, SSIGMA, TAU, UPSILON, PHI, PPHI, XHI, PSI, PPSI, OMEGA, OOMEGA,

    U_9, U_0, U_LB, U_RB
};

const uint32_t PROGMEM unicode_map[] = {
    [ALPHA] = 0x03B1, [BETA] = 0x03B2, [GAMMA] = 0x03B3, [GGAMMA] = 0x0393, [DELTA] = 0x03B4, [DDELTA] = 0x0394,
    [EPSILON] = 0x03B5, [ZETA] = 0x03B6, [ETA] = 0x03B7, [THETA] = 0x03B8, [TTHETA] = 0x0398, [IOTA] = 0x03B9,
    [KAPPA] = 0x03BA, [LAMBDA] = 0x03BB, [LLAMBDA] = 0x039B, [MU] = 0x03BC, [NU] = 0x03BD, [XI] = 0x03BE,
    [XXI] = 0x039E, [PI] = 0x03C0, [PPI] = 0x03A0, [RHO] = 0x03C1, [SIGMA] = 0x03C3, [SSIGMA] = 0x03A3,
    [TAU] = 0x03C4, [UPSILON] = 0x03C5, [PHI] = 0x03C6, [PPHI] = 0x03A6, [XHI] = 0x03C7,
    [PSI] = 0x03C8, [PPSI] = 0x03A8, [OMEGA] = 0x03C9, [OOMEGA] = 0x03A9,

    [U_9] = 0x39, [U_0] = 0x30, [U_LB] = 0x5B, [U_RB] = 0x5D
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_all(
        KC_ESC,   KC_BRID,  KC_BRIU,  KC_MCTL,  KC_LPAD,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,    KC_VOLD, KC_MUTE, KC_VOLU, KC_SNAP,  KC_SIRI,  RGB_MOD,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,    KC_BSPC,  KC_INS,   KC_HOME,  KC_PGUP,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,   KC_BSLS,  KC_DEL,   KC_END,   KC_PGDN,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,             KC_ENT,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,             KC_RSFT,            KC_UP,
        KC_LCTL,  KC_LOPTN, KC_LCMMD,                               KC_SPC,                                 KC_RCMMD, KC_ROPTN,MO(MAC_FN), KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [MAC_FN] = LAYOUT_all(
        KC_TRNS,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,     RGB_VAD, RGB_TOG, RGB_VAI, KC_TRNS,  KC_TRNS,  RGB_TOG,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  NK_TOGG,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        KC_TRNS,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,             KC_TRNS,
        KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,             KC_TRNS,            KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,                                KC_TRNS,                                KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS),

    [WIN_BASE] = LAYOUT_all(
        KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,    KC_VOLD,  KC_MUTE,  KC_VOLU,  KC_PSCR,  KC_F13, KC_CALC,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,    KC_BSPC,  KC_DEL,   KC_HOME,  KC_PGUP,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,   KC_BSLS,  KC_DEL,   KC_END,   KC_PGDN,
        CAPSWRD,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,             KC_ENT,
        KC_LSPO,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,             KC_RSPC,            KC_UP,
        KC_LCPO,  KC_LCMD,  KC_LALT,                                KC_SPC,                                 KC_RALT,  OSL(WIN_GREEK), MO(WIN_FN), KC_RCPC,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [WIN_FN] = LAYOUT_all(
        KC_TRNS,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FLXP,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,   RGB_VAD,  RGB_TOG,  RGB_VAI,  KC_TRNS,  EE_CLR,  QK_BOOT,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  NK_TOGG,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        KC_TRNS,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,             KC_TRNS,
        KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,             KC_TRNS,            KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,                                KC_TRNS,                                KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS),

    [WIN_GREEK] = LAYOUT_all(
        KC_TRNS,  KC_TRNS,       KC_TRNS,           KC_TRNS,           KC_TRNS,       KC_TRNS,           KC_TRNS,           KC_TRNS,    KC_TRNS,  KC_TRNS,             KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, UC_MOD,
        KC_TRNS,  KC_TRNS,       KC_TRNS,           KC_TRNS,           KC_TRNS,       KC_TRNS,           KC_TRNS,           KC_TRNS,    KC_TRNS,  KC_TRNS,             KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS,                     KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS,  XP(PSI, PPSI), X(ETA),            X(EPSILON),        X(RHO),        X(TAU),            XP(THETA, TTHETA), X(UPSILON), X(IOTA),  XP(OMEGA, OOMEGA),   XP(PI, PPI), KC_TRNS, KC_TRNS, KC_TRNS,                     KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS,  X(ALPHA),      XP(SIGMA, SSIGMA), XP(DELTA, DDELTA), XP(PHI, PPHI), XP(GAMMA, GGAMMA), KC_TRNS,           KC_TRNS,    X(KAPPA), XP(LAMBDA, LLAMBDA), KC_TRNS,     KC_TRNS,       KC_TRNS   ,
        KC_LSFT,  X(ZETA),       XP(XI, XXI),       X(XHI),            KC_TRNS,       X(BETA),           X(NU),             X(MU),      KC_TRNS,  KC_TRNS,             KC_TRNS,                    KC_RSFT   ,                              KC_TRNS,
        KC_TRNS,  KC_TRNS,       KC_TRNS,                                             KC_TRNS,                                                    KC_TRNS,             TO(WIN_BASE),         KC_TRNS, KC_TRNS,                     KC_TRNS, KC_TRNS,  KC_TRNS),
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [MAC_BASE]  = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [MAC_FN]    = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
    [WIN_BASE]  = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [WIN_FN]    = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
    [WIN_GREEK] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) }
};
#endif

#if defined(VIA_ENABLE) && defined(ENCODER_ENABLE)

static uint8_t  encoder_state[NUM_ENCODERS] = {0};
static keypos_t encoder_cw[NUM_ENCODERS]    = {{ 8, 5 }};
static keypos_t encoder_ccw[NUM_ENCODERS]  = {{ 7, 5 }};

void encoder_action_unregister(void) {
    for (int index = 0; index < NUM_ENCODERS; ++index) {
        if (encoder_state[index]) {
            keyevent_t encoder_event = (keyevent_t) {
                .key = encoder_state[index] >> 1 ? encoder_cw[index] : encoder_ccw[index],
                .pressed = false,
                .time = (timer_read() | 1)
            };
            encoder_state[index] = 0;
            action_exec(encoder_event);
        }
    }
}

void encoder_action_register(uint8_t index, bool clockwise) {
    keyevent_t encoder_event = (keyevent_t) {
        .key = clockwise ? encoder_cw[index] : encoder_ccw[index],
        .pressed = true,
        .time = (timer_read() | 1)
    };
    encoder_state[index] = (clockwise ^ 1) | (clockwise << 1);
    action_exec(encoder_event);
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    encoder_action_register(index, clockwise);
    return false;
};

#endif

uint16_t prev;
bool siri;

void matrix_init_user(void) {
#ifdef RGB_MATRIX_ENABLE
    rgb_matrix_init_user();
#endif
}

void matrix_scan_user(void) {
    if (siri) {
        if (timer_elapsed(prev) >= 500) {
            siri = false;
            unregister_code(KC_LCMD);
            unregister_code(KC_SPACE);
        }
    }
#if defined(VIA_ENABLE) && defined(ENCODER_ENABLE)
    encoder_action_unregister();
#endif
}

bool caps_word_press_user(uint16_t keycode) {
    switch(keycode) {
        // Keycodes that continue Caps Word with shift applied
        case KC_A ... KC_Z:
        case X(GGAMMA) ... X(OMEGA):
        case KC_MINS:
            add_weak_mods(MOD_BIT(KC_LSFT)); // apply shift to the next key
            return true;

        // Keycodes that continue Caps Word without shift applied
        case KC_1 ... KC_0:
        case X(U_9): // unicode 9 and 0 to force learning space cadet
        case X(U_0):
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
            return true;

        default:
            return false; // Deactivate Caps Word
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Enable RGB on any keypress if currently disabled after Win+L
    static bool rgb_sleep = false;
    if(rgb_sleep && record->event.pressed) {
        rgb_matrix_enable_noeeprom();
        rgb_sleep = false;
    }

    switch (keycode) {
        // Disable RGB on Win+L if currently enabled
        case KC_L:
            if (record->event.pressed && get_mods() & MOD_MASK_GUI && rgb_matrix_is_enabled()) {
                rgb_matrix_disable_noeeprom();
                rgb_sleep = true;
            }
            return true;

        // Custom Caps Word/Lock activation; activate Caps Word normally, or Caps Lock when holding shift
        case CAPSWRD:
            if ((get_mods() & MOD_MASK_SHIFT || host_keyboard_led_state().caps_lock) && record->event.pressed) {
                tap_code(KC_CAPS);
                return false;
            } else {
                return true;
            }

        // MacOS custom keycodes
        case KC_MISSION_CONTROL:
            if (record->event.pressed) {
                host_consumer_send(0x29F);
            } else {
                host_consumer_send(0);
            }
            return false;  // Skip all further processing of this key
        case KC_LAUNCHPAD:
            if (record->event.pressed) {
                host_consumer_send(0x2A0);
            } else {
                host_consumer_send(0);
            }
            return false;  // Skip all further processing of this key
        case KC_LOPTN:
        case KC_ROPTN:
        case KC_LCMMD:
        case KC_RCMMD:
            if (record->event.pressed) {
                register_code(mac_keycode[keycode - KC_LOPTN]);
            } else {
                unregister_code(mac_keycode[keycode - KC_LOPTN]);
            }
            return false;  // Skip all further processing of this key
        case KC_SIRI:
            if (record->event.pressed) {
                register_code(KC_LCMD);
                register_code(KC_SPACE);
                prev = timer_read() | 1;
                siri = true;
            } else {
                // Do something else when release
            }
            return false;  // Skip all further processing of this key

        // Windows custom keycodes
        case KC_TASK:
        case KC_FLXP:
        case KC_SNAP:
        case KC_CRTA:
            if (record->event.pressed) {
                for (uint8_t i = 0; i < key_comb_list[keycode - KC_TASK].len; i++) {
                    register_code(key_comb_list[keycode - KC_TASK].keycode[i]);
                }
            } else {
                for (uint8_t i = 0; i < key_comb_list[keycode - KC_TASK].len; i++) {
                    unregister_code(key_comb_list[keycode - KC_TASK].keycode[i]);
                }
            }
            return false;  // Skip all further processing of this key
        default:
            return true;  // Process all other keycodes normally
    }
}

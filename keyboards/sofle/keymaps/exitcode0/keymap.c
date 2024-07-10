#include <stdio.h>
#include QMK_KEYBOARD_H

enum sofle_layers {
    _DEFAULTS = 0,
    _QWERTY = 0,
    _LOWER,
    _RAISE,
    _ADJUST,
    _NUMPAD,
    _SWITCH
};

enum custom_keycodes {
    KC_QWERTY = SAFE_RANGE,
    KC_LOWER,
    KC_RAISE,
    KC_ADJUST,
};

#include "oled.c"
#include "leds.c"

#ifdef ENCODER_MAP_ENABLE
    const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
        [_QWERTY] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),           ENCODER_CCW_CW(KC_PGDN, KC_PGUP)  },
        [_LOWER] = {  ENCODER_CCW_CW(_______, _______),           ENCODER_CCW_CW(_______,  _______) },
        [_RAISE] = {  ENCODER_CCW_CW(RGB_HUD, RGB_HUI),           ENCODER_CCW_CW(RGB_SAD,  RGB_SAI) },
        [_ADJUST] = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI),           ENCODER_CCW_CW(RGB_RMOD, RGB_MOD) }
    };
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT(
  KC_GRV,             KC_1, KC_2,    KC_3,    KC_4,     KC_5,                         KC_6,   KC_7,     KC_8,    KC_9,               KC_0,    KC_MINS,
  LT(_NUMPAD,KC_TAB), KC_Q, KC_W,    KC_E,    KC_R,     KC_T,                         KC_Y,   KC_U,     KC_I,    KC_O,               KC_P,    KC_BSPC,
  KC_LSFT,            KC_A, KC_S,    KC_D,    KC_F,     KC_G,                         KC_H,   KC_J,     KC_K,    KC_L,               KC_SCLN, KC_QUOT,
  KC_LCTL,            KC_Z, KC_X,    KC_C,    KC_V,     KC_B,   KC_MUTE,     _______, KC_N,   KC_M,     KC_COMM, KC_DOT,             KC_SLSH, SC_SENT,
                            KC_LALT, KC_LGUI, KC_LOWER, KC_SPC, KC_BSPC,     KC_SPC,  KC_ENT, KC_RAISE, KC_RCTL, MT(KC_RALT, KC_ENT)
),

[_LOWER] = LAYOUT(
  KC_ESC,   KC_F1,  KC_F2,   KC_F3,   KC_F4,    KC_F5,                          KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_BSPC,
  _______,  KC_1,   KC_2,    KC_3,    KC_4,     KC_5,                           KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
  _______,  KC_NO,  KC_NO,   KC_NO,   KC_NO,    KC_WH_U,                        KC_NO,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_PIPE,
  _______,  KC_NO,  KC_CUT,  KC_COPY, KC_PASTE, KC_WH_D, _______,      _______, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS, _______,
                    _______, _______, _______,  _______, _______,      _______, _______, _______, _______, _______
),

[_RAISE] = LAYOUT(
  _______, KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,                        KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  KC_BSPC,
  _______, KC_INS,  KC_PSCR, KC_APP,  KC_NO,   KC_NO,                         KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
  _______, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_WH_U,                       KC_NO,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_PIPE,
  _______, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_WH_D, _______,     _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, _______,
                    _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
),

[_ADJUST] = LAYOUT(
  EE_CLR,  RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX,                        XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX,       XXXXXXX, XXXXXXX,
  QK_BOOT, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, KC_QWERTY,                      XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX,       XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        C(G(KC_LEFT)), KC_NO,   KC_NO,   C(G(KC_RGHT)), XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX,    XXXXXXX, XXXXXXX,       KC_MPRV, KC_MPLY, KC_MNXT,       XXXXXXX, XXXXXXX,
                    _______, _______, _______, _______,   _______,    _______, _______,       _______, _______, _______
),

// [_NUMPAD] = LAYOUT(
//   _______, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX,                     _______, KC_NUM, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX,                     KC_CIRC, KC_P7,  KC_P8,   KC_P9,   KC_ASTR, XXXXXXX,
//   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX,                     KC_MINS, KC_P4,  KC_P5,   KC_P6,   KC_EQL,  KC_PIPE,
//   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX, _______,   _______, KC_PLUS, KC_P1,  KC_P2,   KC_P3,   KC_SLSH, _______,
//                     _______, OSM(MOD_MEH), _______, _______, _______,   _______, _______, KC_P0,  KC_PDOT, _______
// ),

// [_SWITCH] = LAYOUT(
//   _______,         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//   TO(0),           TO(1),   TO(2),   TO(3),   TO(4),   TO(5),                   TO(6),   KC_NO,   KC_NO,   KC_NO,   KC_NO,   QK_BOOT,
//   KC_NO,           KC_NO,   KC_BRIU, KC_NO,   KC_NO,   KC_NO,                   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   EE_CLR,
//   KC_SYSTEM_SLEEP, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO,     KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
//                             KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO,     KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO
// ),
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case KC_LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case KC_RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case KC_ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;
    }
    return true;
}

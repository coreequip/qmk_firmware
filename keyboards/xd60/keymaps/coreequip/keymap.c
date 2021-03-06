#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_all(KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_BSPC,
                   KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS,
                   MO(1), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, KC_ENT,
                   KC_LSFT, KC_NO, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, _______, KC_RCTL, KC_UP, KC_SLSH,
                   KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_DEL, MO(1), KC_LEFT, KC_DOWN, KC_RGHT),

	[1] = LAYOUT_all(KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL, KC_DEL,
                   _______, LALT(KC_F4), _______, RALT(KC_5), KC_BTN1, KC_BTN3, KC_BTN2, RALT(KC_Y), _______, RALT(KC_P), KC_PSCR, BL_DEC, BL_INC, KC_APP,
                   _______, RALT(KC_Q), RALT(KC_S), _______, _______, RALT(S(KC_SCLN)), _______, _______, _______, KC_LOCK, _______, _______, _______, _______,
                   _______, _______, _______, KC_MYCM, KC_CALC, _______, KC_MUTE, KC_VOLD, KC_VOLU, KC_MPRV, KC_MNXT, _______, _______, KC_PGUP, _______,
                   MO(2), _______, LM(2,MOD_LALT), KC_MPLY, KC_INS, _______, KC_HOME, KC_PGDN, KC_END),

	[2] = LAYOUT_all(_______, KC_P1, KC_P2, KC_P3, KC_P4, KC_P5, KC_P6, KC_P7, KC_P8, KC_P9, KC_P0, KC_PMNS, KC_PPLS, _______, _______,
                   _______, _______, _______, _______, _______, _______, _______, _______, KC_PAST, _______, _______, _______, _______, _______,
                   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PDOT, _______, _______, LCTL(KC_PGUP), KC_PSLS,
                   _______, _______, _______, _______, _______, _______, LCTL(KC_HOME), LCTL(KC_PGDN), LCTL(KC_END))

};

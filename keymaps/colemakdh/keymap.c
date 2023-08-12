#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

#define _CLMK 0
#define _SYMB 1
#define _PAD 2


enum custom_keycodes {
    CLMK,
    SYMB,
    PAD,
};

    const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT(LT(2,KC_GRV), KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, LT(2,KC_MINS), KC_TAB, KC_Q, KC_W, KC_F, KC_P, KC_B, MO(1), MO(1), KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_EQL, KC_ESC, KC_A, KC_R, KC_S, KC_T, KC_G, KC_LBRC, KC_RBRC, KC_M, KC_N, KC_E, KC_I, KC_O, KC_QUOT, KC_LSFT, KC_Z, KC_X, KC_C, KC_D, KC_V, LT(2,KC_PGUP), KC_PGDN, KC_HOME, LT(2,KC_END), KC_K, KC_H, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_LGUI, KC_PPLS, KC_PMNS, LALT_T(KC_PAST), LCTL_T(KC_BSLS), KC_BSPC, KC_DEL, KC_ENT, KC_SPC, KC_RALT, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT),
	[1] = LAYOUT(KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_TRNS, KC_TRNS, KC_EXLM, KC_AT, KC_LCBR, KC_RCBR, KC_PIPE, KC_TRNS, KC_TRNS, KC_PSLS, KC_P7, KC_P8, KC_P9, KC_PMNS, TG(0), KC_TRNS, KC_HASH, KC_DLR, KC_LBRC, KC_RBRC, KC_GRV, KC_TRNS, KC_TRNS, KC_PAST, KC_P4, KC_P5, KC_P6, KC_PPLS, TG(1), KC_TRNS, KC_PERC, KC_TRNS, KC_LPRN, KC_RPRN, KC_TILD, KC_MUTE, KC_VOLU, KC_MRWD, KC_MFFD, KC_TRNS, KC_P1, KC_P2, KC_P3, KC_PENT, TG(2), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLD, KC_MSTP, KC_MPLY, KC_TRNS, KC_TRNS, KC_P0, KC_P0, KC_PDOT, KC_PENT, KC_TRNS),
	[2] = LAYOUT(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2, KC_BTN3, KC_BTN4, KC_BTN5, KC_TRNS, KC_ESC, KC_A, KC_S, KC_D, KC_F, KC_G, KC_TRNS, KC_TRNS, KC_TRNS, KC_WH_U, KC_UP, KC_WH_D, KC_TRNS, KC_TRNS, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_TRNS, KC_TRNS, KC_2, KC_3, KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, KC_TRNS, KC_LCTL, KC_LALT, KC_TRNS, KC_TRNS, KC_TRNS, KC_SPC, KC_ENT, KC_1, KC_4, KC_5, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R)
    };

void keyboard_post_init_user(void) {
    rgblight_setrgb(127, 0, 255);
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _CLMK:
            rgblight_setrgb(127, 0, 255);
            break;
        case _SYMB:
            rgblight_setrgb(0, 200, 50);
            break;
        case _PAD:
            rgblight_setrgb(200, 100, 0);
            break;
        default: // for any other layers, or the default layer
            rgblight_setrgb(127, 0, 255);
            break;
    }
    return state;
}

#include "zeal60.h"

//Tap Dance Declarations
//In Layer declaration, add tap dance item in place of a key code, e.g., TD(TD_GRV)
// mpjuers layout for Zeal60

enum {
    TD_GRV = 0
};

enum planck_keycodes {
    DYNAMIC_MACRO_RANGE
};

#include "dynamic_macro.h"

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    if (!process_record_dynamic_macro(keycode, record)) 
    {
        return false;
    }
    return true;
}


//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    //Tap once for Esc, twice for grave accent
    [TD_GRV] = ACTION_TAP_DANCE_DOUBLE(KC_GRV, KC_ESC)
        // Other declarations would go here, separated by commas, if you have them
};

// [0,13] is either left key of split backspace (e.g. HHKB \| key) or 2U backspace
// [1,13] is either backslash or ISO Enter
// [2,12] is either ANSI Enter or key left of ISO Enter
// [2,13] is right key of split backspace (e.g. HHKB `~ key)
// [3,1] is right key of split left-shift (e.g ISO key)
// [3,13] is right key of split right-shift (e.g. HHKB Fn key)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    // Default layer
    [0] = {
        {TD(TD_GRV),KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC},
        {KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS},
        {FN_TT13,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,  KC_NO  },
        {KC_LSFT,   KC_NO,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_NO  },
        {KC_LCTL,   KC_LALT, KC_LGUI, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_SPC,  KC_NO,   KC_NO,   KC_RALT, FN_MO13, FN_MO23, KC_RCTL}
    },

    // Fn1 Layer
    [1] = {
        {KC_GRV,  KC_F1,            KC_F2,          KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,    KC_DEL },
        {KC_TRNS, DYN_REC_START1,   DYN_REC_STOP,   DYN_MACRO_PLAY1,  KC_TRNS, KC_TRNS, KC_TRNS, KC_PGUP, KC_INS,  KC_TRNS, KC_PSCR, KC_SLCK,   KC_PAUS, KC_TRNS},
        {KC_TRNS, KC_VOLD,          KC_VOLU,        KC_PGDN, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TRNS, KC_PGUP, KC_POWER,  KC_TRNS},
        {KC_TRNS, KC_TRNS,          KC_MUTE,        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPRV, KC_MPLY, KC_MNXT, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS},
        {KC_TRNS, KC_TRNS,          KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS}
    },

    // Fn2 Layer
    [2] = {
        {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS},
        {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS},
        {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME, KC_TRNS, KC_TRNS, KC_END,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS},
        {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS},
        {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS}
    },

    // Fn3 Layer (zeal60 Configuration)
    [3] = {
        {RESET,   EF_DEC,  EF_INC,  H1_DEC,  H1_INC,  H2_DEC,  H2_INC,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, BR_DEC,  BR_INC,  KC_TRNS},
        {KC_TRNS, KC_TRNS, KC_TRNS, S1_DEC,  S1_INC,  S2_DEC,  S2_INC,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, ES_DEC,  ES_INC,  KC_TRNS},
        {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS},
        {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS},
        {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS}
    }

};

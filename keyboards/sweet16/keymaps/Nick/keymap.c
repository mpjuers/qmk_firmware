#include "sweet16.h"

enum layers {
    _DEFAULT,
    _MACROS
};

enum custom_keycodes {
    UP_URL = SAFE_RANGE,
    FUNSTART
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_DEFAULT] = LAYOUT_ortho_4x4(
            KC_KP_7,    KC_KP_8,    KC_KP_9,        KC_KP_MINUS, 
            KC_KP_4,    KC_KP_5,    KC_KP_6,        KC_KP_PLUS, 
            KC_KP_1,    KC_KP_2,    KC_KP_3,        KC_KP_ASTERISK, 
            MO(_MACROS),KC_KP_0,    KC_KP_DOT,      KC_KP_SLASH
            ),

    [_MACROS] = LAYOUT_ortho_4x4(
            KC_TAB,     M(FUNSTART),    KC_LPRN,    KC_RPRN,
            KC_F2,      KC_F4,          KC_UP,      KC_DEL,
            KC_TRNS,    KC_LEFT,        KC_DOWN,    KC_RGHT,
            KC_TRNS,    KC_TRNS,        KC_TRNS,    KC_ENT
            )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case UP_URL:
            if (record->event.pressed) {
                SEND_STRING("http://1upkeyboards.com");
            }
        case FUNSTART:
            if(record->event.pressed) {
                SEND_STRING("=(");
            }
            return false;
            break;
    }
    return true;
}

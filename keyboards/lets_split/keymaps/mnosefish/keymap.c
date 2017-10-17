#include "lets_split.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _COLEMAK 1
#define _DVORAK 2
#define _LOWER 3
#define _RAISE 4
#define _ADJUST 16
#define _TENKEY 10
#define _ARROWS 20

enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    COLEMAK,
    DVORAK,
    LOWER,
    RAISE,
    ADJUST,
    TENKEY,
    ARROWS
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO
#define TKEYOFF M(10)
#define DZERO M(20)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Qwerty
     * ,-----------------------------------------------------------------------------------.
     * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * | Tab  |Arrow |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |EShift|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |lctrl |Adjust| Alt  | GUI  |Lower |Space |Space |Raise | Left | Vol- | Vol+ |RCtrl |
     * `-----------------------------------------------------------------------------------'
     */
    [_QWERTY] = KEYMAP( \
            KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
            KC_TAB,  F(4),    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
            KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, F(5),    \
            KC_LCTL, ADJUST,  KC_LGUI, KC_LALT, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_MPLY, KC_VOLD, KC_VOLU, KC_RCTL  \
            ),

    /* Colemak
     * ,-----------------------------------------------------------------------------------.
     * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "   |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |Adjust| Ctrl | Alt  | GUI  |Lower |Space |Space |Raise | Left | Down |  Up  |Right |
     * `-----------------------------------------------------------------------------------'
     */
    [_COLEMAK] = KEYMAP( \
            KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC, \
            KC_ESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT, \
            KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT , \
            ADJUST,  KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
            ),

    /* Dvorak
     * ,-----------------------------------------------------------------------------------.
     * | Tab  |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  /   |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |Adjust| Ctrl | Alt  | GUI  |Lower |Space |Space |Raise | Left | Down |  Up  |Right |
     * `-----------------------------------------------------------------------------------'
     */
    [_DVORAK] = KEYMAP( \
            KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC, \
            KC_ESC,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH, \
            KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_ENT , \
            ADJUST,  KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
            ),

    /* Lower
     * ,-----------------------------------------------------------------------------------.
     * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |     |    \  |  |   |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | |      |      |Enter |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
     * `-----------------------------------------------------------------------------------'
     */
    [_LOWER] = KEYMAP( \
            KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL, \
            KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, \
            _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,S(KC_NUHS),S(KC_NUBS),_______, _______, _______, \
            _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY \
            ),

    /* Raise
     * ,-----------------------------------------------------------------------------------.
     * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |      |      |Enter |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
     * `-----------------------------------------------------------------------------------'
     */
    [_RAISE] = KEYMAP( \
            KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL, \
            KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, \
            _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, _______, _______, _______, \
            _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY \
            ),

    /* Adjust (Lower + Raise)
     * ,-----------------------------------------------------------------------------------.
     * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|Tenkey|Dvorak|      |      |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |             |      |      |      |      |      |
     * `-----------------------------------------------------------------------------------'
     */
    [_ADJUST] =  KEYMAP( \
            _______, RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL, \
            _______, _______, _______, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  TENKEY,  _______, _______, _______, \
            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
            ),

    [_ARROWS] = KEYMAP( \
            _______, _______, _______, _______, _______, _______, _______, KC_PGUP, _______, _______, _______, _______, \
            _______, _______, _______, KC_PGDN, _______, _______, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______, _______, \
            _______, _______, _______, _______, _______, _______, F(0)   , F(1)   , F(2)   , F(3)   , _______, _______, \
            _______, _______, _______, _______, _______, _______, F(6)   , F(7)   , F(8)   , F(9)   , _______, _______  \
            ),

    [_TENKEY] = KEYMAP( \
            TKEYOFF, _______, _______, _______, _______, _______, KC_NLCK, KC_P7,  KC_P8,   KC_P9,   KC_PSLS, _______, \
            _______, _______, _______, _______, _______, _______, KC_TAB,  KC_P4,  KC_P5,   KC_P6,   KC_PPLS, _______, \
            _______, _______, _______, _______, _______, _______, KC_F4,   KC_P1,  KC_P2,   KC_P3,   KC_PMNS, KC_PENT, \
            _______, _______, _______, _______, _______, _______, _______, KC_P0,  DZERO,   KC_PDOT, KC_PAST, _______  \
            )

};

const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_MODS_KEY(MOD_LALT, KC_LEFT), //Navigate text outside of evil in osx
    [1] = ACTION_MODS_KEY(MOD_LGUI, KC_LEFT), //Navigate text outside of evil in osx
    [2] = ACTION_MODS_KEY(MOD_LGUI, KC_RGHT), //Navigate text outside of evil in osx
    [3] = ACTION_MODS_KEY(MOD_LALT, KC_RGHT), //Navigate text outside of evil in osx
    [4] = ACTION_LAYER_TAP_KEY(_ARROWS, KC_A), //A functions as A when tappedn, arrow layer when held
    [5] = ACTION_MODS_TAP_KEY(MOD_RSFT, KC_ENT), //Enter functions as right shift
    [6] = ACTION_MODS_KEY(MOD_LALT, KC_BSPC), //delete word to left
    [7] = ACTION_MODS_KEY(MOD_LGUI, KC_BSPC), //delete to SOL
    [8] = ACTION_MODS_KEY(MOD_LGUI, KC_DEL), //delete to EOL
    [9] = ACTION_MODS_KEY(MOD_LALT, KC_DEL) //delete word to right
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
    switch (id) {
        case 10: // TKEYOFF
            if (record->event.pressed) {
                layer_off(_TENKEY);
            }
            break;
        case 20: // .00
            if (record->event.pressed) {
                return MACRO(T(PDOT), T(0), T(0), END);
            }
            break;
    }

    return MACRO_NONE;
}

#ifdef AUDIO_ENABLE
    float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
    float tone_dvorak[][2]     = SONG(DVORAK_SOUND);
    float tone_colemak[][2]    = SONG(COLEMAK_SOUND);
#endif

    void persistant_default_layer_set(uint16_t default_layer) {
        eeconfig_update_default_layer(default_layer);
        default_layer_set(default_layer);
    }

    bool process_record_user(uint16_t keycode, keyrecord_t *record) {
        switch (keycode) {
            case QWERTY:
                if (record->event.pressed) {
                    #ifdef AUDIO_ENABLE
                    PLAY_NOTE_ARRAY(tone_qwerty, false, 0);
                    #endif
                    persistant_default_layer_set(1UL<<_QWERTY);
                }
                return false;
                break;
            case COLEMAK:
                if (record->event.pressed) {
                    #ifdef AUDIO_ENABLE
                    PLAY_NOTE_ARRAY(tone_colemak, false, 0);
                    #endif
                    persistant_default_layer_set(1UL<<_COLEMAK);
                }
                return false;
                break;
            case DVORAK:
                if (record->event.pressed) {
                    #ifdef AUDIO_ENABLE
                    PLAY_NOTE_ARRAY(tone_dvorak, false, 0);
                    #endif
                    persistant_default_layer_set(1UL<<_DVORAK);
                }
                return false;
                break;
            case LOWER:
                if (record->event.pressed) {
                    layer_on(_LOWER);
                    update_tri_layer(_LOWER, _RAISE, _ADJUST);
                } else {
                    layer_off(_LOWER);
                    update_tri_layer(_LOWER, _RAISE, _ADJUST);
                }
                return false;
                break;
            case RAISE:
                if (record->event.pressed) {
                    layer_on(_RAISE);
                    update_tri_layer(_LOWER, _RAISE, _ADJUST);
                } else {
                    layer_off(_RAISE);
                    update_tri_layer(_LOWER, _RAISE, _ADJUST);
                }
                return false;
                break;
            case ADJUST:
                if (record->event.pressed) {
                    layer_on(_ADJUST);
                } else {
                    layer_off(_ADJUST);
                }
                return false;
                break;
            case TENKEY:
                if (record->event.pressed) {
                    layer_off(_RAISE);
                    layer_off(_LOWER);
                    layer_off(_ADJUST);
                    layer_on(_TENKEY);
                }
                return false;
                break;
        }
        return true;
    }

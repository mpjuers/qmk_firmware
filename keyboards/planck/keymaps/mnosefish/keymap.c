/* This is the layout of mnosefish, based on the Planck default
 * It has features a togglable tenkey layer and a dedicated vim-like arrow layer.
 * as well as toggleable backlight breathing
 */

#include "planck.h"
#include "action_layer.h"
#ifdef AUDIO_ENABLE
#include "audio.h"
#endif
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

enum planck_layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
    _TENKEY,
    _ARROWS
};

enum planck_keycodes {
    QWERTY = SAFE_RANGE,
    LOWER,
    RAISE,
    BACKLIT,
    EXT_PLV,
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
     * | Tab  |Aarrow|   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |EShift|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Ctrl | Brite| Alt  | GUI  |Lower |    Space    |Raise | Play | Vol+ |  Vol-| Ctrl |
     * `-----------------------------------------------------------------------------------'
     * EShift: Enter/shift
     * Aarrow: A/arrow layer
     */
    [_QWERTY] = {
        {KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC},
        {KC_TAB,  F(4),    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
        {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, F(5)   },
        {KC_LCTL, BACKLIT, KC_LALT, KC_LGUI, LOWER,   KC_SPC       ,    RAISE,   KC_MPLY, KC_VOLD, KC_VOLU, KC_RCTL}
    },

    /* Lower
     * ,-----------------------------------------------------------------------------------.
     * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
     * `-----------------------------------------------------------------------------------'
     */
    [_LOWER] = {
        {KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_DEL},
        {_______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS,    KC_PLUS,    KC_LCBR, KC_RCBR, KC_PIPE},
        {_______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  S(KC_NUHS), S(KC_NUBS), KC_HOME, KC_END,  _______},
        {_______, _______, _______, _______, _______,          _______, _______,    KC_MNXT,    KC_VOLD, KC_VOLU, KC_MPLY}
    },

    /* Raise
     * ,-----------------------------------------------------------------------------------.
     * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |Pg Up |Pg Dn |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
     * `-----------------------------------------------------------------------------------'
     */
    [_RAISE] = {
        {KC_GRV,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL},
        {_______,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS},
        {_______,  KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______},
        {_______, _______, _______, _______, _______,           _______, _______,  KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY}
    },

    /* Adjust (Lower + Raise)
     * ,-----------------------------------------------------------------------------------.
     * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|Tenkey|      |      |      |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |             |      |      |      |      |      |
     * `-----------------------------------------------------------------------------------'
     */
    [_ADJUST] = {
        {_______, RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL },
        {_______, _______, _______, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY , TENKEY , _______, _______, _______},
        {_______, MUV_DE , MUV_IN,  MU_ON,   MU_OFF,  MI_ON ,  MI_OFF , _______, _______, _______, _______, _______},
        {_______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______}
    },

    /* Arrows
     * ,-----------------------------------------------------------------------------------.
     * |      |      |      |      |      |      |      | pgUP |      |      |      |      |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |      |      |      | pgDn |      |      | Left | Down |  Up  | Right|      |      |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |      |      |      |      |      |      | SOL  |WDLEFT|WDRGHT| EOL  |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |   DelSOL    |DelWdL|DelWdR|DelEOL|      |      |
     * `-----------------------------------------------------------------------------------'
     */
    [_ARROWS] = {
        {_______, _______, _______, _______, _______, _______, _______, KC_PGUP, _______, _______, _______, _______},
        {_______, _______, _______, KC_PGDN, _______, _______, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______, _______},
        {_______, _______, _______, _______, _______, _______, F(0)   , F(1)   , F(2)   , F(3)   , _______, _______},
        {_______, _______, _______, _______, _______,          F(6)   , F(7)   , F(8)   , F(9)   , _______, _______}
    },

    /* Tenkey
     * ,------------------------------------------------------------------------------------
     * | Off  |      |      |      |      |      |NUMLOK|   7  |   8  |   9  |   /  |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------+
     * |      |      |      |      |      |      | TAB  |   4  |   5  |   6  |   +  |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------+
     * |      |      |      |      |      |      | F4   |   1  |   2  |   3  |   -  |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------+
     * |      |      |      |      |      |             |   0  | .00  |   .  |   *  |      |
     * `------------------------------------------------------------------------------------
     */
    [_TENKEY] = {
        {TKEYOFF, _______, _______, _______, _______, _______, KC_NLCK, KC_P7,  KC_P8,   KC_P9,   KC_PSLS, _______},
        {_______, _______, _______, _______, _______, _______, KC_TAB,  KC_P4,  KC_P5,   KC_P6,   KC_PPLS, _______},
        {_______, _______, _______, _______, _______, _______, KC_F4,   KC_P1,  KC_P2,   KC_P3,   KC_PMNS, KC_PENT},
        {_______, _______, _______, _______, _______,          _______, KC_P0,  DZERO,   KC_PDOT, KC_PAST, _______}
    }
};

#ifdef AUDIO_ENABLE

float tone_startup[][2]    = SONG(STARTUP_SOUND);
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_plover_gb[][2]  = SONG(PLOVER_GOODBYE_SOUND);
float music_scale[][2]     = SONG(MUSIC_SCALE_SOUND);

float tone_goodbye[][2] = SONG(GOODBYE_SOUND);
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
        case BACKLIT:
            if (record->event.pressed) {
                register_code(KC_RSFT);
                #ifdef BACKLIGHT_ENABLE
                if (get_backlight_level() == BACKLIGHT_LEVELS) {
                    breathing_toggle();
                }
                else {
                    if (is_breathing()) {
                        breathing_toggle();
                    }
                    else {
                        backlight_step();
                    }
                }
                #endif
            } else {
                unregister_code(KC_RSFT);
            }
            return false;
            break;
        case TENKEY:
            if (record->event.pressed) {
                layer_off(_RAISE);
                layer_off(_LOWER);
                layer_off(_ADJUST);
                layer_on(_TENKEY);
                #ifdef BACKLIGHT_ENABLE
                breathing_speed_set(2);
                breathing_pulse();
                #endif
                #ifdef AUDIO_ENABLE
                PLAY_NOTE_ARRAY(tone_plover_gb, false, 0);
                #endif
            }
            return false;
            break;
    }
    return true;
}
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

void matrix_init_user(void) {
#ifdef AUDIO_ENABLE
    startup_user();
#endif
}

#ifdef AUDIO_ENABLE

void startup_user()
{
    _delay_ms(20); // gets rid of tick
    PLAY_NOTE_ARRAY(tone_startup, false, 0);
}

void shutdown_user()
{
    PLAY_NOTE_ARRAY(tone_goodbye, false, 0);
    _delay_ms(150);
    stop_all_notes();
}

void music_on_user(void)
{
    music_scale_user();
}

void music_scale_user(void)
{
    PLAY_NOTE_ARRAY(music_scale, false, 0);
}

#endif

const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_MODS_KEY(KC_LCTL, KC_A), //Navigate text outside of evil in osx
    [1] = ACTION_MODS_KEY(KC_LCTL, KC_E), //Navigate text outside of evil in osx
    [2] = ACTION_MODS_KEY(KC_LALT, KC_LEFT), //Navigate text outside of evil in osx
    [3] = ACTION_MODS_KEY(KC_LALT, KC_RGHT), //Navigate text outside of evil in osx
    [4] = ACTION_LAYER_TAP_KEY(_ARROWS, KC_A), //A functions as A when tappedn, arrow layer when held
    [5] = ACTION_MODS_TAP_KEY(MOD_RSFT, KC_ENT), //Enter functions as right shift
    [6] = ACTION_MODS_KEY(KC_LGUI, KC_BSPC), //delete to SOL
    [7] = ACTION_MODS_KEY(KC_LALT, KC_BSPC), //delete word to left
    [8] = ACTION_MODS_KEY(KC_LALT, KC_DEL), //delete word to right
    [9] = ACTION_MODS_KEY(KC_LGUI, KC_DEL) //delete to EOL
};

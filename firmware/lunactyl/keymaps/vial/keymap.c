#include QMK_KEYBOARD_H
#include "lunactyl_keys.h"


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT(
            KC_GRV,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,                   KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_EQL,
            KC_MINUS,   KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,                   KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_MINS,
            KC_LCTL,    KC_A,       KC_S,       KC_D,       KC_F,       KC_G,                   KC_H,       KC_J,       KC_K,       KC_L,       KC_QUOT,    KC_SCLN,
            KC_LGUI,    KC_Z,       KC_X,     KC_C,     HOME_V,     KC_B,                     KC_N,       HOME_M,     KC_COMM,    KC_DOT,    KC_SLSH,    KC_BSLS,
                                    KC_LALT,    KC_LCTL,                                                                KC_RCTL,   KC_RALT,
                                                            MLSFT,      KC_SPC,                 KC_BSPC,    MRSFT,
                                                            MO(4),    NAV_TAB,                 KC_ENT,     KC_CAPS,
                                                            KC_ESC,   _______,               KC_RGUI,    SYM_DEL
    ),
    // when pressing the left shift
    [1] = LAYOUT(
            KC_F12,     KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,                  KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,
            _______,    _______,    _______,     _______,    _______,   _______,                KC_HOME,    _______,    KC_INS,     _______,    _______,    KC_MUTE,
            KC_CAPS,    _______,    _______,    _______,    _______,    _______,                KC_LEFT,    KC_DOWN,    KC_UP,      KC_RGHT,    KC_END,     KC_VOLU,
            KC_LGUI,    _______,    _______,    _______,    KC_LSFT,    _______,                 KC_HOME,    KC_PGDN,    KC_PGUP,   KC_END,    KC_INS,     KC_VOLD,
                                    _______,     _______,                                                             KC_RCTL,   KC_RALT,
                                                            _______,    _______,                KC_QUES,    CW_TOGG,
                                                            _______,    _______,                _______,    _______,
                                                            _______,    _______,                  MO(3),    _______
        ),
    // when pressing the right shift
    [2] = LAYOUT(
            _______,    _______,    _______,    _______,    _______,    _______,                _______,    _______,    _______,    _______,    _______,    _______,
            _______,    _______,    _______,    KC_MINUS,    KC_LCBR,    KC_RCBR,               C(KC_W),    KC_WBAK,    _______,    KC_WFWD,    C(S(KC_T)),    ALGR(KC_W),
            _______,    _______,    _______,    KC_EQL,     KC_LPRN,    KC_RPRN,                KC_LEFT,    KC_DOWN,    KC_UP,      KC_RGHT,    ALGR(KC_P),    ALGR(KC_Q),
            _______,    _______,    _______,    _______,    KC_LBRC,    KC_RBRC,                _______,    _______,    _______,    _______,    _______,    _______,
                                    _______,    _______,                                                                _______,    _______,
                                                            _______,    _______,                _______,    _______,
                                                            _______,    _______,                _______,    _______,
                                                            _______,    _______,                _______,    _______
        ),
    [3] = LAYOUT(
            QK_BOOT,    QK_MAKE,    _______,    _______,    _______,    _______,                _______,    _______,    _______,    _______,    _______,    _______,
            _______,    _______,    _______,    _______,    _______,    _______,                _______,    _______,    _______,    _______,    _______,    _______,
            _______,    _______,    _______,    _______,    _______,    _______,                _______,    _______,    _______,    _______,    _______,    _______,
            _______,    _______,    _______,    _______,    _______,    _______,                _______,    _______,    _______,    _______,    _______,    _______,
                                    _______,    _______,                                                                KC_BRID,    KC_BRIU,
                                                            _______,    _______,                _______,    _______,
                                                            _______,    _______,                _______,    _______,
                                                            _______,    _______,                _______,    _______
        )
};


// I want the shift button(s) to behave as one-shot shifts when clicked but as layers when pressed.
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(1, MOD_LSFT):
            if (record->tap.count && record->event.pressed) {
                set_oneshot_mods(MOD_BIT(KC_LSFT));
                return false;
            }
            break;
        case LT(2, MOD_RSFT):
            if (record->tap.count && record->event.pressed) {
                set_oneshot_mods(MOD_BIT(KC_RSFT));
                return false;
            }
            break;
    }
    return true;
}

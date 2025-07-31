// Copyright 2025 @alvarezb
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// ┌─────────────────────────────────────────────────┐
// │ d e f i n e   l a y e r s                       │
// └─────────────────────────────────────────────────┘

enum totem_layers {
    _BASE,
    _QWERTY,
    _COLEMAK,
    _LOWER,
    _RAISE,
    _ADJUST,
};

// ┌─────────────────────────────────────────────────┐
// │ d e f i n e   k e y c o d e s                   │
// └─────────────────────────────────────────────────┘

enum custom_keycodes {
    COLEMAK=SAFE_RANGE,
    QWERTY,
    LOWER,
    RAISE,
    ADJUST,
    MAKE_H,
    SNAP,
    CDMR,
};

// ┌─────────────────────────────────────────────────┐
// │ s a v e   c h o s e n   l a y o u t             │
// └─────────────────────────────────────────────────┘

typedef union {
  uint32_t raw;
  struct {
    uint8_t locked_alpha_layer : 8;
  };
} user_config_t;

user_config_t user_config;

// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ K E Y M A P S                                                                                                          │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /*
      ┌─────────────────────────────────────────────────┐
      │ b a s e   s y m b o l s                         │      ╭╮╭╮╭╮╭╮
      └─────────────────────────────────────────────────┘      │╰╯╰╯╰╯│
                ┌─────────┬─────────┬─────────┬─────────┬──────╨──┐┌──╨──────┬─────────┬─────────┬─────────┬─────────┐
        ╌┄┈┈───═╡         │         │         │         │         ││         │         │         │         │   ; :   │
                ├─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┤
                │         │         │         │         │         ││         │         │         │         │         │
      ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐
      │   ' "   │         │         │         │         │         ││         │         │   , <   │   . >   │   / ?   │   - _   │
      └─────────┴─────────┴─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┴─────────┴─────────┘
                                    │   DEL   │   TAB   │  SPACE  ││  SPACE  │  ENTER  │  BSPC   │  (tap)
                                    ├─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┤
                                   /  RAISE  /  LOWER  /   CMD   //  SHIFT  /  LOWER  /  RAISE  /   (hold)
                                  └─────────┴─────────┴─────────┘└─────────┴─────────┴─────────┘ */

    [_BASE] = LAYOUT(
                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_SCLN,
                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_QUOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, KC_COMM, KC_DOT,  KC_SLSH, KC_MINS,

                  LT(3,KC_DEL), LT(2,KC_TAB), LGUI_T(KC_SPC),    LSFT_T(KC_SPC), LT(2,KC_ENT), LT(3,KC_BSPC)
    ),
    
    
    /*
      ┌─────────────────────────────────────────────────┐
      │ q w e r t y                                     │      ╭╮╭╮╭╮╭╮
      └─────────────────────────────────────────────────┘      │╰╯╰╯╰╯│
                ┌─────────┬─────────┬─────────┬─────────┬──────╨──┐┌──╨──────┬─────────┬─────────┬─────────┬─────────┐
        ╌┄┈┈───═╡    Q    │    W    │    E    │    R    │    T    ││    Y    │    U    │    I    │    O    │    ▼    │
                ├─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┤
                │    A    │    S    │    D    │    F    │    G    ││    H    │    J    │    K    │    L    │    P    │
      ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐
      │    ▼    │    Z    │    X    │    C    │    V    │    B    ││    N    │    M    │    ▼    │    ▼    │    ▼    │    ▼    │
      └─────────┴─────────┴─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┴─────────┴─────────┘
                                    │    ▼    │    ▼    │    ▼    ││    ▼    │    ▼    │    ▼    │  (tap)
                                    ├─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┤
                                   /    ▼    /    ▼    /    ▼    //    ▼    /    ▼    /    ▼    /   (hold)
                                  └─────────┴─────────┴─────────┘└─────────┴─────────┴─────────┘ */

    [_QWERTY] = LAYOUT(
                 KC_Q,         KC_W,         KC_E,          KC_R,          KC_T,      KC_Y,      KC_U,           KC_I,          KC_O,          _______,
                 LCTL_T(KC_A), LALT_T(KC_S), LGUI_T(KC_D),  LSFT_T(KC_F),  KC_G,      KC_H,      LSFT_T(KC_J),   LGUI_T(KC_K),  LALT_T(KC_L),  LCTL_T(KC_P),
        _______, KC_Z,         KC_X,         KC_C,          KC_V,          KC_B,      KC_N,      KC_M,           _______,       _______,        _______,       _______,
                                             _______,       _______,       _______,   _______,   _______,        _______
    ),

    /*
      ┌─────────────────────────────────────────────────┐
      │ c o l e m a c - d h                             │      ╭╮╭╮╭╮╭╮
      └─────────────────────────────────────────────────┘      │╰╯╰╯╰╯│
                ┌─────────┬─────────┬─────────┬─────────┬──────╨──┐┌──╨──────┬─────────┬─────────┬─────────┬─────────┐
        ╌┄┈┈───═╡    Q    │    W    │    F    │    P    │    B    ││    J    │    L    │    U    │    Y    │    ▼    │
                ├─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┤
                │    A    │    R    │    S    │    T    │    G    ││    M    │    N    │    E    │    I    │    O    │
      ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐
      │    ▼    │    Z    │    X    │    C    │    D    │    V    ││    K    │    H    │    ▼    │    ▼    │    ▼    │    ▼    │
      └─────────┴─────────┴─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┴─────────┴─────────┘
                                    │    ▼    │    ▼    │    ▼    ││    ▼    │    ▼    │    ▼    │  (tap)
                                    ├─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┤
                                   /    ▼    /    ▼    /    ▼    //    ▼    /    ▼    /    ▼    /   (hold)
                                  └─────────┴─────────┴─────────┘└─────────┴─────────┴─────────┘ */

    [_COLEMAK] = LAYOUT(
                 KC_Q,         KC_W,         KC_F,          KC_P,          KC_B,        KC_J,      KC_L,           KC_U,          KC_Y,          _______,
                 LCTL_T(KC_A), LALT_T(KC_R), LGUI_T(KC_S),  LSFT_T(KC_T),  KC_G,        KC_M,      LSFT_T(KC_N),   LGUI_T(KC_E),  LALT_T(KC_I),  LCTL_T(KC_O),
        _______, KC_Z,         KC_X,         KC_C,          KC_D,          KC_V,        KC_K,      KC_H,           _______,       _______,       _______,       _______,
                                             _______,       _______,       _______,     _______,   _______,        _______
    ),

    /*
      ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸

      ┌─────────────────────────────────────────────────┐
      │ l o w e r (RED)                                 │      ╭╮╭╮╭╮╭╮
      └─────────────────────────────────────────────────┘      │╰╯╰╯╰╯│
                ┌─────────┬─────────┬─────────┬─────────┬──────╨──┐┌──╨──────┬─────────┬─────────┬─────────┬─────────┐
        ╌┄┈┈───═╡ LCS+TAB │  CMD+W  │    ↑    │  LSG+T  │    {    ││    }    │    7    │    8    │    9    │    +    │
                ├─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┤
                │ CTL+TAB │    ←    │    ↓    │    →    │    [    ││    ]    │    4    │    5    │    6    │    -    │
      ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐
      │  emoji  │         │         │ LGUI+[  │ LGUI+]  │    (    ││    )    │    1    │    2    │    3    │    *    │    =    │
      └─────────┴─────────┴─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┴─────────┴─────────┘
                                    │    ▼    │    ▼    │    ▼    ││    ▼    │    ▼    │    0    │
                                    ├─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┤
                                   / ADJUST  /         /         //         /         / ADJUST  /
                                  └─────────┴─────────┴─────────┘└─────────┴─────────┴─────────┘ */

    [_LOWER] = LAYOUT(
                 LCS(KC_TAB),  LGUI(KC_W), KC_UP,        LSG(KC_T),    KC_LCBR,    KC_RCBR, KC_7,         KC_8,         KC_9,         KC_PPLS,
                 LCTL(KC_TAB), KC_LEFT,    KC_DOWN,      KC_RGHT,      KC_LBRC,    KC_RBRC, LSFT_T(KC_4), LGUI_T(KC_5), LALT_T(KC_6), LCTL_T(KC_MINS),
    LCG(KC_SPC), XXXXXXX,      XXXXXXX,    LGUI(KC_LBRC),LGUI(KC_RBRC),KC_LPRN,    KC_RPRN, KC_1,         KC_2,         KC_3,         KC_PAST,         KC_EQL,
                                        LT(4, _______),  _______,      _______,    _______, _______,      LT(4, KC_0)
    ),
    /*
      ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸

      ┌─────────────────────────────────────────────────┐
      │ r a i s e  (BLUE)                               │      ╭╮╭╮╭╮╭╮
      └─────────────────────────────────────────────────┘      │╰╯╰╯╰╯│
                ┌─────────┬─────────┬─────────┬─────────┬──────╨──┐┌──╨──────┬─────────┬─────────┬─────────┬─────────┐
        ╌┄┈┈───═╡    !    │    @    │    #    │    $    │    %    ││    ^    │    &    │    *    │    (    │    )    │
                ├─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┤
                │  CTRL   │   ALT   │   CMD   │  SHIFT  │   ` ~   ││   ' "   │  SHIFT  │   CMD   │   ALT   │  CTRL   │
      ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐
      │         │         │   CUT   │  COPY   │  PASTE  │   ESC   ││ VOL DWN │ VOL UP  │SKIP BACK│ PLAY/PAU│SKIP FORW│    \    │
      └─────────┴─────────┴─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┴─────────┴─────────┘
                                    │    ▼    │    ▼    │    ▼    ││    ▼    │    ▼    │    ▼    │
                                    ├─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┤
                                   /         /  ADJUST /         //         / ADJUST  /         /
                                  └─────────┴─────────┴─────────┘└─────────┴─────────┴─────────┘ */

    [_RAISE] = LAYOUT(
                 KC_EXLM,  KC_AT,      KC_HASH,    KC_DLR,     KC_PERC,    KC_CIRC, KC_AMPR,   KC_PAST,  LSFT(KC_9), LSFT(KC_0),
                 KC_LCTL,  KC_LALT,    KC_LGUI,    KC_LSFT,    KC_GRV,     KC_QUOT, KC_RSFT,   KC_RGUI,  KC_RALT,    KC_RCTL,
        XXXXXXX, XXXXXXX,  LGUI(KC_X), LGUI(KC_C), LGUI(KC_V), KC_ESC,     KC_VOLD, KC_VOLU,   KC_MPRV,  KC_MPLY,    KC_MNXT,      KC_BSLS,
                                        _______,LT(4, _______), _______,   _______, LT(4, _______),_______
    ),
    /*
      ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸

      ┌─────────────────────────────────────────────────┐
      │ a d j u s t                                     │      ╭╮╭╮╭╮╭╮
      └─────────────────────────────────────────────────┘      │╰╯╰╯╰╯│
                ┌─────────┬─────────┬─────────┬─────────┬──────╨──┐┌──╨──────┬─────────┬─────────┬─────────┬─────────┐
        ╌┄┈┈───═╡  RESET  │CAPS LOCK│ COLEMAK │         │         ││         │    F7   │   F8    │   F9    │   F12   │
                ├─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┤
                │  DEBUG  │SCRL LOCK│ QWERTY  │         │         ││         │    F4   │   F5    │   F4    │   F11   │
      ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐
      │  MAKE   │         │NUM LOCK │         │         │monorepo ││         │    F1   │   F2    │   F3    │   F10   │         │
      └─────────┴─────────┴─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┴─────────┴─────────┘
                                    │    ▼    │    ▼    │    ▼    ││    ▼    │    ▼    │    ▼    │
                                    └─────────┴─────────┴─────────┘└─────────┴─────────┴─────────┘ */

    [_ADJUST] = LAYOUT(
                QK_BOOT, KC_CAPS, COLEMAK, XXXXXXX, XXXXXXX,    XXXXXXX, KC_F7, KC_F8, KC_F9, KC_F12,
                DB_TOGG, KC_SCRL, QWERTY,  XXXXXXX, XXXXXXX,    XXXXXXX, KC_F4, KC_F5, KC_F6, KC_F11,
        MAKE_H, XXXXXXX, KC_NUM,  XXXXXXX, XXXXXXX, CDMR,       XXXXXXX, KC_F1, KC_F2, KC_F3, KC_F10, XXXXXXX,
                                  _______, _______, _______,    _______, _______, _______
    )
};

// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ M A C R O S                                                                                                            │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {

            // ┌─────────────────────────────────────────────────┐
            // │ l a y e r                                       │
            // └─────────────────────────────────────────────────┘

        case COLEMAK:
            if (record->event.pressed) {
                //set_single_persistent_default_layer(_COLEMAK);

                // get config, update locked layer, write it back
                user_config.raw = eeconfig_read_user();
                user_config.locked_alpha_layer = _COLEMAK;
                eeconfig_update_user(user_config.raw);

                // re-initialize the keyboard
                keyboard_post_init_user();
            }
            return false;

        case QWERTY:
            if (record->event.pressed) {
                //set_single_persistent_default_layer(_QWERTY);

                // get config, update locked layer, write it back
                user_config.raw = eeconfig_read_user();
                user_config.locked_alpha_layer = _QWERTY;
                eeconfig_update_user(user_config.raw);

                // re-initialize the keyboard
                keyboard_post_init_user();
            }
            return false;

            // ┌─────────────────────────────────────────────────┐
            // │ q m k                                           │
            // └─────────────────────────────────────────────────┘

        case MAKE_H:
            if (record->event.pressed) {
                SEND_STRING("qmk flash -kb totem -km alvarezb");
                tap_code(KC_ENTER);
            }
            break;

            // ┌─────────────────────────────────────────────────┐
            // │ p r o d u c t i v i t y                         │
            // └─────────────────────────────────────────────────┘

        case SNAP:
            if (record->event.pressed) {
                if (!keymap_config.swap_lctl_lgui) {
                    SEND_STRING(SS_LSFT(SS_LWIN("S"))); // WIN
                } else {
                    SEND_STRING(SS_LSFT(SS_LCMD(SS_LCTL("4")))); // MAC
                }
            }
            break;
        
        case CDMR:
            if (record->event.pressed) {
                SEND_STRING("cd ~/devel/monorepo; source venv/bin/activate;");
                tap_code(KC_ENTER);
            }
            break;
    }
    return true;
}

// longer tapping term for pinkies
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    // custom tapping term overrides
    switch (keycode) {
        case LCTL_T(KC_A): // left pinky
            return TAPPING_TERM + 50;
        case LCTL_T(KC_P): // right pinky
            return TAPPING_TERM + 30;
        default:
            return TAPPING_TERM;
    }
}

bool process_detected_host_os_user(os_variant_t detected_os){
    if ((detected_os == OS_MACOS) | (detected_os == OS_IOS)) {
        keymap_config.swap_lctl_lgui = false; // MacOS
        return true;
    }
    else if ((detected_os == OS_LINUX) | (detected_os == OS_WINDOWS)){
        keymap_config.swap_lctl_lgui = true; // Windows
        return true;
    }
    else {
        return false;
    }
}

// load default alpha layer from eeprom
void keyboard_post_init_user(void) {
  // Call the keymap level matrix init.

  // Read the user config from EEPROM
  user_config.raw = eeconfig_read_user();

  // Locks the default alpha layer
  switch (user_config.locked_alpha_layer) {
    case _COLEMAK:
        layer_lock_on(_COLEMAK);
        layer_lock_off(_QWERTY);
        break;
    case _QWERTY:
        layer_lock_on(_QWERTY);
        layer_lock_off(_COLEMAK);
        break;
    default:
        layer_lock_on(_COLEMAK);
        layer_lock_off(_QWERTY);
        break;
  }
}

// set eeprom default values
void eeconfig_init_user(void) {  // EEPROM is getting reset!
    user_config.raw = 0;
    user_config.locked_alpha_layer = _COLEMAK;
    eeconfig_update_user(user_config.raw); // Write default value to EEPROM now
}
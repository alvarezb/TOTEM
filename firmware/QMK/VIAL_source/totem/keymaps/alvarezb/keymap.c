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
    CLS_TAB,
    CLS_WIN,
    SWP_LAYOUT,
    MAXIMIZE,
    BOT_HALF,
    TOP_HALF,
    L_HALF,
    R_HALF,
    R_1_WIN,
    L_1_WIN,
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


// ┌─────────────────────────────────────────────────┐
// │ h e l p e r   f u n c t i o n s   s t u b s     │
// └─────────────────────────────────────────────────┘
bool is_apple_os(void);

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

        LT(_RAISE,KC_DEL), LT(_LOWER,KC_TAB), LGUI_T(KC_SPC),    LSFT_T(KC_SPC), LT(_LOWER,KC_ENT), LT(_RAISE,KC_BSPC)
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
        ╌┄┈┈───═╡ LCS+TAB │ CLS_TAB │    ↑    │  LSG+T  │    {    ││    }    │    7    │    8    │    9    │    +    │
                ├─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┤
                │ CTL+TAB │    ←    │    ↓    │    →    │    [    ││    ]    │    4    │    5    │    6    │    -    │
      ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐
      │  emoji  │         │         │brws_fwd │brws_back│    (    ││    )    │    1    │    2    │    3    │    *    │    =    │
      └─────────┴─────────┴─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┴─────────┴─────────┘
                                    │    ▼    │    ▼    │    ▼    ││    ▼    │    ▼    │    0    │
                                    ├─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┤
                                   / ADJUST  /         /         //         /         / ADJUST  /
                                  └─────────┴─────────┴─────────┘└─────────┴─────────┴─────────┘ */

    [_LOWER] = LAYOUT(
                 RCS(KC_TAB),  CLS_TAB,    KC_UP,        LSG(KC_T),    KC_LCBR,    KC_RCBR, KC_7,         KC_8,         KC_9,         KC_PPLS,
                 RCTL(KC_TAB), KC_LEFT,    KC_DOWN,      KC_RGHT,      KC_LBRC,    KC_RBRC, LSFT_T(KC_4), LGUI_T(KC_5), LALT_T(KC_6), LCTL_T(KC_MINS),
    LCG(KC_SPC), XXXXXXX,      XXXXXXX,    KC_WBAK,      KC_WFWD,      KC_LPRN,    KC_RPRN, KC_1,         KC_2,         KC_3,         KC_PAST,         KC_EQL,
                                  LT(_ADJUST, _______),  _______,      _______,    _______, _______,      LT(_ADJUST, KC_0)
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
                                  _______,LT(_ADJUST, _______), _______,   _______, LT(_ADJUST, _______),_______
    ),
    /*
      ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸

      ┌─────────────────────────────────────────────────┐
      │ a d j u s t                                     │      ╭╮╭╮╭╮╭╮
      └─────────────────────────────────────────────────┘      │╰╯╰╯╰╯│
                ┌─────────┬─────────┬─────────┬─────────┬──────╨──┐┌──╨──────┬─────────┬─────────┬─────────┬─────────┐
        ╌┄┈┈───═╡  RESET  │swp lyout│    ⊤    │         │         ││         │    F7   │   F8    │   F9    │   F12   │
                ├─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┤
                │  DEBUG  │    ⊢    │    ☐    │    ⊣    │         ││         │    F4   │   F5    │   F4    │   F11   │
      ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐
      │  MAKE   │monorepo │    ⊨    │    ⊥    │    ⫤    │         ││         │    F1   │   F2    │   F3    │   F10   │         │
      └─────────┴─────────┴─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┴─────────┴─────────┘
                                    │    ▼    │    ▼    │    ▼    ││    ▼    │    ▼    │    ▼    │
                                    └─────────┴─────────┴─────────┘└─────────┴─────────┴─────────┘ */

    [_ADJUST] = LAYOUT(
                QK_BOOT, SWP_LAYOUT, TOP_HALF, XXXXXXX, XXXXXXX,    XXXXXXX, KC_F7, KC_F8, KC_F9, KC_F12,
                DB_TOGG, L_HALF,     MAXIMIZE, R_HALF,  XXXXXXX,    XXXXXXX, KC_F4, KC_F5, KC_F6, KC_F11,
        MAKE_H, CDMR,    L_1_WIN,    BOT_HALF, R_1_WIN, XXXXXXX,    XXXXXXX, KC_F1, KC_F2, KC_F3, KC_F10, XXXXXXX,
                                  _______,    _______, _______,    _______, _______, _______
    )
};

// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ M A C R O S                                                                                                            │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed){
        // NOTE this main switch section only activates on key pressed events.
        switch (keycode) {

                // ┌─────────────────────────────────────────────────┐
                // │ l a y e r                                       │
                // └─────────────────────────────────────────────────┘

            case COLEMAK:
                // get config, update locked layer, write it back
                user_config.raw = eeconfig_read_user();
                user_config.locked_alpha_layer = _COLEMAK;
                eeconfig_update_user(user_config.raw);

                // re-initialize the keyboard
                keyboard_post_init_user();
                return false;

            case QWERTY:
                // get config, update locked layer, write it back
                user_config.raw = eeconfig_read_user();
                user_config.locked_alpha_layer = _QWERTY;
                eeconfig_update_user(user_config.raw);

                // re-initialize the keyboard
                keyboard_post_init_user();
                return false;

            case SWP_LAYOUT:
                // toggle between possible layouts, and save to eeprom
                user_config.raw = eeconfig_read_user();
                if (user_config.locked_alpha_layer == _COLEMAK) {
                    user_config.locked_alpha_layer = _QWERTY;
                } else {
                    user_config.locked_alpha_layer = _COLEMAK;
                }
                eeconfig_update_user(user_config.raw);
                keyboard_post_init_user();
                return false;

                // ┌─────────────────────────────────────────────────┐
                // │ q m k                                           │
                // └─────────────────────────────────────────────────┘

            case MAKE_H:
                SEND_STRING("qmk flash -kb totem -km alvarezb");
                tap_code(KC_ENTER);
                break;

                // ┌─────────────────────────────────────────────────┐
                // │ p r o d u c t i v i t y                         │
                // └─────────────────────────────────────────────────┘

            case SNAP:
                if (!keymap_config.swap_lctl_lgui) {
                    SEND_STRING(SS_LSFT(SS_LWIN("S"))); // WIN
                } else {
                    SEND_STRING(SS_LSFT(SS_LCMD(SS_LCTL("4")))); // MAC
                }
                break;
            
            case CDMR:
                SEND_STRING("cd ~/devel/monorepo; source venv/bin/activate;");
                tap_code(KC_ENTER);
                break;


            // ┌─────────────────────────────────────────────────┐
            // │ O S   D i f f e r e n c e s                     │
            // └─────────────────────────────────────────────────┘
            case KC_WBAK:
                if (is_apple_os()){
                    SEND_STRING(SS_LGUI("["));
                } else {
                    tap_code(KC_WBAK);
                }
                break;

            case KC_WFWD:
                if (is_apple_os()){
                    SEND_STRING(SS_LGUI("]"));
                } else {
                    tap_code(KC_WFWD);
                }
                break;
            case CLS_TAB:
                if (is_apple_os()){
                    SEND_STRING(SS_LGUI("w"));
                } else {
                    SEND_STRING(SS_LCTL(SS_TAP(X_F4)));
                }
                break;

            case MAXIMIZE:
                if(is_apple_os()){
                    SEND_STRING(SS_LCTL(SS_LALT(SS_TAP(X_ENTER))));
                } else {
                    // need to experiment
                }
                break;
            case BOT_HALF:
                if(is_apple_os()){
                    SEND_STRING(SS_LCTL(SS_LALT(SS_TAP(X_DOWN))));
                } else {
                    SEND_STRING(SS_RGUI(SS_TAP(X_DOWN)));
                }
                break;
            case TOP_HALF:
                if(is_apple_os()){
                    SEND_STRING(SS_LCTL(SS_LALT(SS_TAP(X_UP))));
                } else {
                    SEND_STRING(SS_RGUI(SS_TAP(X_UP)));
                }
                break;
            case L_HALF:
                if(is_apple_os()){
                    SEND_STRING(SS_LCTL(SS_LALT(SS_TAP(X_LEFT))));
                } else {
                    SEND_STRING(SS_RGUI(SS_TAP(X_LEFT)));
                }
                break;
            case R_HALF:
                if(is_apple_os()){
                    SEND_STRING(SS_LCTL(SS_LALT(SS_TAP(X_RIGHT))));
                } else {
                    SEND_STRING(SS_RGUI(SS_TAP(X_RIGHT)));
                }
                break;
            case L_1_WIN:
                if(is_apple_os()){
                    SEND_STRING(SS_LCTL(SS_LALT(SS_LGUI(SS_TAP(X_LEFT)))));
                } else {
                    SEND_STRING(SS_RGUI(SS_TAP(X_LEFT)));
                }
                break;
            case R_1_WIN:
                if(is_apple_os()){
                    SEND_STRING(SS_LCTL(SS_LALT(SS_LGUI(SS_TAP(X_RIGHT)))));
                } else {
                    SEND_STRING(SS_RGUI(SS_TAP(X_RIGHT)));
                }
                break;

        }
    }
    // Any key presses that are not exclusively used on event.pressed
    // should be handled below:
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

// handle macos vs windows/linux
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

// any keyboard setup goes here
void keyboard_post_init_user(void) {
  // Read the user config from EEPROM
  user_config.raw = eeconfig_read_user();
  
  set_single_persistent_default_layer(_BASE);
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

// helper functions
bool is_apple_os(void){
    // check if we're set up for macos/ios or another OS
    return keymap_config.swap_lctl_lgui == false; // MacOS
}
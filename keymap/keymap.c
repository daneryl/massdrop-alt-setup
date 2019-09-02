#include QMK_KEYBOARD_H

enum alt_keycodes {
    U_T_AUTO = SAFE_RANGE, //USB Extra Port Toggle Auto Detect / Always Active
    U_T_AGCR,              //USB Toggle Automatic GCR control
    DBG_TOG,               //DEBUG Toggle On / Off
    DBG_MTRX,              //DEBUG Toggle Matrix Prints
    DBG_KBD,               //DEBUG Toggle Keyboard Prints
    DBG_MOU,               //DEBUG Toggle Mouse Prints
    MD_BOOT,               //Restart into bootloader after hold timeout
    //
    TMUX_SESSIONS,
    TMUX_LEFT,
    TMUX_RIGHT,
    TMUX_UP,
    TMUX_DOWN,
    TMUX_DETACH,
    TMUX_COPY_MODE,
    TMUX_ZOOM,
    TMUX_HSPLIT,
    TMUX_VSPLIT,
    TMUX_KILL_PANE,
    TMUX_CMD_MODE,
    TMUX_CLEAR,
    TMUX_NEXT_WINDOW,
};

#define TG_NKRO MAGIC_TOGGLE_NKRO //Toggle 6KRO / NKRO mode

keymap_config_t keymap_config;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // MAC 
    [0] = LAYOUT(
        KC_ESC,            KC_1,    KC_2,          KC_3,    KC_4,    KC_5,  KC_6,    KC_7,    KC_8,         KC_9,    KC_0,               KC_MINS,     KC_EQUAL,      KC_BSPC, KC_GRV,  \
        KC_TAB,            KC_Q,    LT(3, KC_W),   KC_E,    KC_R,    KC_T,  KC_Y,    KC_U,    LT(3, KC_I),  KC_O,    KC_P,               KC_LBRC,     KC_RBRC,       KC_BSLS, KC_HOME, \
        LCTL_T(KC_ESC),    KC_A,    KC_S,          KC_D,    KC_F,    KC_G,  KC_H,    KC_J,    KC_K,         KC_L,    LCTL_T(KC_SCOLON),  KC_QUOTE,    KC_ENT,        KC_PGUP, \
        KC_LSPO,           KC_Z,    KC_X,          KC_C,    KC_V,    KC_B,  KC_N,    KC_M,    KC_COMM,      KC_DOT,  KC_SLSH,            KC_RSPC,                    KC_UP,   KC_PGDN, \
        KC_LCTL,           KC_LALT, KC_LGUI,                                KC_SPC,                                  KC_RCBR,            MO(2),       KC_LEFT,       KC_DOWN, KC_RGHT  \
    ),

    // Windows
    [1] = LAYOUT(
        KC_ESC,         KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_DEL,  \
        KC_TAB,         KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_HOME, \
        LCTL_T(KC_ESC), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGUP, \
        KC_LSFT,        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,   KC_PGDN, \
        KC_LCTL,        KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, MO(2),   KC_LEFT, KC_DOWN, KC_RGHT  \
    ),

    [2] = LAYOUT(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, KC_MUTE, \
        _______, RGB_SPD, RGB_VAI, RGB_SPI, RGB_HUI, RGB_SAI, _______, U_T_AUTO,U_T_AGCR,_______, KC_PSCR, KC_SLCK, KC_PAUS, _______, KC_END, \
        _______, RGB_RMOD,RGB_VAD, RGB_MOD, RGB_HUD, RGB_SAD, _______, _______, _______, _______, _______, _______,          _______, KC_VOLU, \
        _______, RGB_TOG, _______, _______, _______, MD_BOOT, TG_NKRO, DBG_TOG, _______, _______, _______, _______,          KC_PGUP, KC_VOLD, \
        DF(1)  , DF(0)  , _______,                            _______,                            _______, _______, KC_HOME, KC_PGDN, KC_END  \
    ),
    
    // tmux layout ?
    [3] = LAYOUT(
        KC_TRNS, KC_TRNS,    KC_TRNS,          KC_TRNS,        KC_TRNS, TMUX_HSPLIT,   TMUX_VSPLIT,     KC_TRNS,      KC_TRNS,      KC_TRNS,    KC_TRNS,        KC_TRNS,              KC_TRNS, TMUX_CLEAR, KC_TRNS, \
        KC_TRNS, KC_TRNS,    KC_TRNS,          KC_TRNS,        KC_TRNS, KC_TRNS,       KC_TRNS,         KC_TRNS,      KC_TRNS,      KC_TRNS,    KC_TRNS,        TMUX_COPY_MODE,       KC_TRNS, KC_TRNS,    KC_TRNS, \
        KC_TRNS, KC_TRNS,    TMUX_SESSIONS,    TMUX_DETACH,    KC_TRNS, KC_TRNS,       TMUX_LEFT,       TMUX_DOWN,    TMUX_UP,      TMUX_RIGHT, TMUX_CMD_MODE,  KC_TRNS,                       KC_TRNS,    KC_TRNS, \
        KC_TRNS, TMUX_ZOOM,  TMUX_KILL_PANE,   KC_TRNS,        KC_TRNS, KC_TRNS,       TMUX_NEXT_WINDOW,KC_TRNS,      KC_TRNS,      KC_TRNS,    KC_TRNS,        KC_TRNS,                       KC_TRNS,    KC_TRNS, \
        KC_TRNS, KC_ESC,     KC_TRNS,                                                  KC_TRNS,                                             KC_TRNS,        KC_TRNS,              KC_TRNS, KC_TRNS,    KC_TRNS  \
    ),
   
    /*
    [X] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, \
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, \
        KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS  \
    ),
    */
};

/* #define RGB_MATRIX_STARTUP_MODE 2 */
// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
  rgblight_mode(RGB_MATRIX_EFFECT_MAX-1);
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
};

#define MODS_SHIFT  (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT))
#define MODS_CTRL  (get_mods() & MOD_BIT(KC_LCTL) || get_mods() & MOD_BIT(KC_RCTRL))
#define MODS_ALT  (get_mods() & MOD_BIT(KC_LALT) || get_mods() & MOD_BIT(KC_RALT))

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint32_t key_timer;

    switch (keycode) {
        case U_T_AUTO:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                TOGGLE_FLAG_AND_PRINT(usb_extra_manual, "USB extra port manual mode");
            }
            return false;
        case U_T_AGCR:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                TOGGLE_FLAG_AND_PRINT(usb_gcr_auto, "USB GCR auto mode");
            }
            return false;
        case DBG_TOG:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_enable, "Debug mode");
            }
            return false;
        case DBG_MTRX:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_matrix, "Debug matrix");
            }
            return false;
        case DBG_KBD:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_keyboard, "Debug keyboard");
            }
            return false;
        case DBG_MOU:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_mouse, "Debug mouse");
            }
            return false;
        case MD_BOOT:
            if (record->event.pressed) {
                key_timer = timer_read32();
            } else {
                if (timer_elapsed32(key_timer) >= 500) {
                    reset_keyboard();
                }
            }
            return false;
        case RGB_TOG:
            if (record->event.pressed) {
              switch (rgb_matrix_get_flags()) {
                case LED_FLAG_ALL: {
                    rgb_matrix_set_flags(LED_FLAG_KEYLIGHT);
                    rgb_matrix_set_color_all(0, 0, 0);
                  }
                  break;
                case LED_FLAG_KEYLIGHT: {
                    rgb_matrix_set_flags(LED_FLAG_UNDERGLOW);
                    rgb_matrix_set_color_all(0, 0, 0);
                  }
                  break;
                case LED_FLAG_UNDERGLOW: {
                    rgb_matrix_set_flags(LED_FLAG_NONE);
                    rgb_matrix_disable_noeeprom();
                  }
                  break;
                default: {
                    rgb_matrix_set_flags(LED_FLAG_ALL);
                    rgb_matrix_enable_noeeprom();
                  }
                  break;
              }
            }
            return false;

        case TMUX_KILL_PANE:
            if (record->event.pressed) {
              SEND_STRING(SS_LCTRL("b")"x");
            }
            return false;

        case TMUX_SESSIONS:
            if (record->event.pressed) {
              SEND_STRING(SS_LCTRL("b")"s");
            }
            return false;

        case TMUX_VSPLIT:
            if (record->event.pressed) {
              SEND_STRING(SS_LCTRL("b")"\"");
            }
            return false;

        case TMUX_HSPLIT:
            if (record->event.pressed) {
              SEND_STRING(SS_LCTRL("b")"%");
            }
            return false;

        case TMUX_ZOOM:
            if (record->event.pressed) {
              SEND_STRING(SS_LCTRL("b")"z");
            }
            return false;

        case TMUX_DETACH:
            if (record->event.pressed) {
              SEND_STRING(SS_LCTRL("b")"d");
            }
            return false;

        case TMUX_COPY_MODE:
            if (record->event.pressed) {
              SEND_STRING(SS_LCTRL("b")SS_TAP(X_LBRACKET));
            }
            return false;

        case TMUX_LEFT:
            if (record->event.pressed) {
              SEND_STRING(SS_LCTRL("b"));
              SEND_STRING(SS_TAP(X_LEFT));
            }
            return false;

        case TMUX_RIGHT:
            if (record->event.pressed) {
              SEND_STRING(SS_LCTRL("b"));
              SEND_STRING(SS_TAP(X_RIGHT));
            }
            return false;

        case TMUX_DOWN:
            if (record->event.pressed) {
              SEND_STRING(SS_LCTRL("b")SS_TAP(X_DOWN));
            }
            return false;

        case TMUX_UP:
            if (record->event.pressed) {
              SEND_STRING(SS_LCTRL("b")SS_TAP(X_UP));
            }
            return false;

        case TMUX_NEXT_WINDOW:
            if (record->event.pressed) {
              SEND_STRING(SS_LCTRL("b"));
              SEND_STRING("n");
            }
            return false;

        case TMUX_CLEAR:
            if (record->event.pressed) {
              SEND_STRING(SS_LCTRL("c"));
              SEND_STRING("clear");
              SEND_STRING(SS_TAP(X_ENTER));
              SEND_STRING(SS_LCTRL("b")SS_DOWN(X_LSHIFT)SS_TAP(X_SCOLON)SS_UP(X_LSHIFT));
              SEND_STRING("clear-history");
              SEND_STRING(SS_TAP(X_ENTER));
            }
            return false;

        case TMUX_CMD_MODE:
            if (record->event.pressed) {
              SEND_STRING(SS_LCTRL("b")SS_DOWN(X_LSHIFT)SS_TAP(X_SCOLON)SS_UP(X_LSHIFT));
            }
            return false;
        default:
            return true; //Process all other keycodes normally
    }
}

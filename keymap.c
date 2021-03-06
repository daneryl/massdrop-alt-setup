#include QMK_KEYBOARD_H

enum alt_keycodes {
    L_BRI = SAFE_RANGE, //LED Brightness Increase
    L_BRD,              //LED Brightness Decrease
    L_PTN,              //LED Pattern Select Next
    L_PTP,              //LED Pattern Select Previous
    L_PSI,              //LED Pattern Speed Increase
    L_PSD,              //LED Pattern Speed Decrease
    L_T_MD,             //LED Toggle Mode
    L_T_ONF,            //LED Toggle On / Off
    L_ON,               //LED On
    L_OFF,              //LED Off
    L_T_BR,             //LED Toggle Breath Effect
    L_T_PTD,            //LED Toggle Scrolling Pattern Direction
    U_T_AUTO,           //USB Extra Port Toggle Auto Detect / Always Active
    U_T_AGCR,           //USB Toggle Automatic GCR control
    DBG_TOG,            //DEBUG Toggle On / Off
    DBG_MTRX,           //DEBUG Toggle Matrix Prints
    DBG_KBD,            //DEBUG Toggle Keyboard Prints
    DBG_MOU,            //DEBUG Toggle Mouse Prints
    MD_BOOT,            //Restart into bootloader after hold timeout
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
    TMUX_PREV_WINDOW,
    TMUX_NEW_WINDOW,

    TD_SCOLON = 0,
    TD_EQUAL,
};

qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Esc, twice for Caps Lock
  [TD_SCOLON] = ACTION_TAP_DANCE_DOUBLE(KC_SCOLON, KC_COLON),
  [TD_EQUAL] = ACTION_TAP_DANCE_DOUBLE(KC_EQUAL, KC_PLUS),

// Other declarations would go here, separated by commas, if you have them
};

#define TG_NKRO MAGIC_TOGGLE_NKRO //Toggle 6KRO / NKRO mode

keymap_config_t keymap_config;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_ESC,            KC_1,    KC_2,          KC_3,    KC_4,    KC_5,  KC_6,    KC_7,    KC_8,         KC_9,    KC_0,               KC_MINS,     KC_EQUAL,      KC_BSPC, KC_GRV,  \
        KC_TAB,            KC_Q,    LT(2, KC_W),   KC_E,    KC_R,    KC_T,  KC_Y,    KC_U,    LT(2, KC_I),  KC_O,    KC_P,               KC_LBRC,     KC_RBRC,       KC_BSLS, KC_HOME, \
        LCTL_T(KC_ESC),    KC_A,    KC_S,          KC_D,    KC_F,    KC_G,  KC_H,    KC_J,    KC_K,         KC_L,    KC_SCOLON,          KC_QUOTE,    KC_ENT,        KC_PGUP, \
        KC_LSPO,           KC_Z,    KC_X,          KC_C,    KC_V,    KC_B,  KC_N,    KC_M,    KC_COMM,      KC_DOT,  KC_SLSH,            KC_RSPC,                    KC_UP,   KC_PGDN, \
        KC_LCTL,           KC_LALT, KC_LGUI,                                KC_SPC,                                  KC_RCBR,            MO(1),       KC_LEFT,       KC_DOWN, KC_RGHT  \
    ),

    [1] = LAYOUT(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TRNS, KC_MUTE, \
        L_T_BR,  L_PSD,   L_BRI,   L_PSI,   KC_TRNS, KC_TRNS, KC_TRNS, U_T_AUTO,U_T_AGCR,KC_TRNS, KC_PSCR, KC_SLCK, KC_PAUS, KC_TRNS, KC_END, \
        L_T_PTD, L_PTP,   L_BRD,   L_PTN,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_VOLU, \
        KC_TRNS, L_T_MD,  L_T_ONF, KC_TRNS, KC_TRNS, MD_BOOT, TG_NKRO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_PGUP, KC_VOLD, \
        KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS,                            KC_TRNS, KC_TRNS, KC_HOME, KC_PGDN, KC_END  \
    ),
    
    // tmux layout
    [2] = LAYOUT(
        KC_TRNS, KC_TRNS,    KC_TRNS,          KC_TRNS,         KC_TRNS, TMUX_HSPLIT,   TMUX_VSPLIT,     KC_TRNS,      KC_TRNS,      KC_TRNS,    KC_TRNS,           KC_TRNS,              KC_TRNS, TMUX_CLEAR, KC_TRNS, \
        KC_TRNS, KC_TRNS,    KC_TRNS,          KC_TRNS,         KC_TRNS, KC_TRNS,       KC_TRNS,         KC_TRNS,      KC_TRNS,      KC_TRNS,    TMUX_PREV_WINDOW,  TMUX_COPY_MODE,       KC_TRNS, KC_TRNS,    KC_TRNS, \
        KC_TRNS, KC_TRNS,    TMUX_SESSIONS,    TMUX_DETACH,     KC_TRNS, KC_TRNS,       TMUX_LEFT,       TMUX_DOWN,    TMUX_UP,      TMUX_RIGHT, TMUX_CMD_MODE,     KC_TRNS,                       KC_TRNS,    KC_TRNS, \
        KC_TRNS, TMUX_ZOOM,  TMUX_KILL_PANE,   TMUX_NEW_WINDOW, KC_TRNS, KC_TRNS,       TMUX_NEXT_WINDOW,KC_TRNS,      KC_TRNS,      KC_TRNS,    KC_TRNS,           KC_TRNS,                       KC_TRNS,    KC_TRNS, \
        KC_TRNS, KC_ESC,     KC_TRNS,                                                   KC_TRNS,                                                 KC_TRNS,           KC_TRNS,              KC_TRNS, KC_TRNS,    KC_TRNS  \
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

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
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
        case L_BRI:
            if (record->event.pressed) {
                if (LED_GCR_STEP > LED_GCR_MAX - gcr_desired) gcr_desired = LED_GCR_MAX;
                else gcr_desired += LED_GCR_STEP;
                if (led_animation_breathing) gcr_breathe = gcr_desired;
            }
            return false;
        case L_BRD:
            if (record->event.pressed) {
                if (LED_GCR_STEP > gcr_desired) gcr_desired = 0;
                else gcr_desired -= LED_GCR_STEP;
                if (led_animation_breathing) gcr_breathe = gcr_desired;
            }
            return false;
        case L_PTN:
            if (record->event.pressed) {
                if (led_animation_id == led_setups_count - 1) led_animation_id = 0;
                else led_animation_id++;
            }
            return false;
        case L_PTP:
            if (record->event.pressed) {
                if (led_animation_id == 0) led_animation_id = led_setups_count - 1;
                else led_animation_id--;
            }
            return false;
        case L_PSI:
            if (record->event.pressed) {
                led_animation_speed += ANIMATION_SPEED_STEP;
            }
            return false;
        case L_PSD:
            if (record->event.pressed) {
                led_animation_speed -= ANIMATION_SPEED_STEP;
                if (led_animation_speed < 0) led_animation_speed = 0;
            }
            return false;
        case L_T_MD:
            if (record->event.pressed) {
                led_lighting_mode++;
                if (led_lighting_mode > LED_MODE_MAX_INDEX) led_lighting_mode = LED_MODE_NORMAL;
            }
            return false;
        case L_T_ONF:
            if (record->event.pressed) {
                led_enabled = !led_enabled;
                I2C3733_Control_Set(led_enabled);
            }
            return false;
        case L_ON:
            if (record->event.pressed) {
                led_enabled = 1;
                I2C3733_Control_Set(led_enabled);
            }
            return false;
        case L_OFF:
            if (record->event.pressed) {
                led_enabled = 0;
                I2C3733_Control_Set(led_enabled);
            }
            return false;
        case L_T_BR:
            if (record->event.pressed) {
                led_animation_breathing = !led_animation_breathing;
                if (led_animation_breathing) {
                    gcr_breathe = gcr_desired;
                    led_animation_breathe_cur = BREATHE_MIN_STEP;
                    breathe_dir = 1;
                }
            }
            return false;
        case L_T_PTD:
            if (record->event.pressed) {
                led_animation_direction = !led_animation_direction;
            }
            return false;
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
        case MD_BOOT:
            if (record->event.pressed) {
                key_timer = timer_read32();
            } else {
                if (timer_elapsed32(key_timer) >= 500) {
                    reset_keyboard();
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

        case TMUX_NEW_WINDOW:
            if (record->event.pressed) {
              SEND_STRING(SS_LCTRL("b"));
              SEND_STRING("c");
            }
            return false;

        case TMUX_NEXT_WINDOW:
            if (record->event.pressed) {
              SEND_STRING(SS_LCTRL("b"));
              SEND_STRING("n");
            }
            return false;

        case TMUX_PREV_WINDOW:
            if (record->event.pressed) {
              SEND_STRING(SS_LCTRL("b"));
              SEND_STRING("p");
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

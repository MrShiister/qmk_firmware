#include QMK_KEYBOARD_H

typedef union {
    uint32_t raw;
    struct {
        uint8_t  mode:6;
        uint16_t hue:9;
        uint8_t  sat:8;
        uint8_t  val:8;
    };
} user_config_t;

user_config_t user_config;

enum my_keycodes {
    SAVE_RGB = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    LAYOUT_60_ansi(
        KC_ESC,		KC_1,		KC_2,		KC_3,		KC_4,		KC_5,		KC_6,		KC_7,		KC_8,		KC_9,		KC_0,		KC_LBRC,	KC_RBRC,	KC_BSPC,		
	    KC_TAB,		KC_QUOT,	KC_COMM,	KC_DOT,		KC_P,		KC_Y,		KC_F,		KC_G,		KC_C,		KC_R,		KC_L,		KC_SLSH,	KC_EQL,		KC_BSLS,		
	    MO(2),	    KC_A,		KC_O,		KC_E,		KC_U,		KC_I,		KC_D,		KC_H,		KC_T,		KC_N,		KC_S,		KC_MINS,		KC_ENT,		
	    KC_LSFT,	KC_SCLN,	KC_Q,		KC_J,		KC_K,		KC_X,		KC_B,		KC_M,		KC_W,		KC_V,		KC_Z,			RSFT_T(KC_DEL),		
	    KC_LCTL,	KC_LGUI,	KC_LALT,					KC_SPC,								KC_LEFT,	KC_DOWN,	KC_UP,		KC_RGHT
    ),

    LAYOUT_60_ansi(
        KC_ESC,		KC_1,		KC_2,		KC_3,		KC_4,		KC_5,		KC_6,		KC_7,		KC_8,		KC_9,		KC_0,		KC_MINS,	KC_EQL,		KC_BSPC,		
        KC_TAB,		KC_Q,		KC_W,		KC_E,		KC_R,		KC_T,		KC_Y,		KC_U,		KC_I,		KC_O,		KC_P,		KC_LBRC,	KC_RBRC,	KC_BSLS,		
        MO(2),  	KC_A,		KC_S,		KC_D,		KC_F,		KC_G,		KC_H,		KC_J,		KC_K,		KC_L,		KC_SCLN,	KC_QUOT,		KC_ENT,		
        KC_LSFT,	KC_Z,		KC_X,		KC_C,		KC_V,		KC_B,		KC_N,		KC_M,		KC_COMM,	KC_DOT,		KC_SLSH,			RSFT_T(KC_DEL),		
        KC_LCTL,	KC_LGUI,	KC_LALT,					KC_SPC,								KC_LEFT,	KC_DOWN,	KC_UP,		KC_RGHT
    ),

    LAYOUT_60_ansi(
        KC_GRV,     KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,     KC_BSPC,
        MO(3),      KC_VOLD,    KC_VOLU,    KC_MPLY,    KC_MSTP,    KC_MPRV,    KC_MNXT,    KC_P7,      KC_P8,      KC_P9,      KC_INS,     KC_PGUP,    KC_PGDN,    KC_PSCR,
        KC_TRNS,    KC_CAPS,    PB_2,       PB_3,       PB_4,       PB_5,       PB_6,       KC_P4,      KC_P5,      KC_P6,      DF(1),      DF(0),          KC_TRNS,
        KC_TRNS,    KC_PWR,     KC_SLEP,    KC_COPY,    KC_PSTE, DYN_REC_START1, DYN_MACRO_PLAY1, KC_P1, KC_P2,     KC_P3,      KC_PDOT,        KC_TRNS,
        KC_HOME,    PB_1,       KC_END,                     KC_P0,                              KC_NUM,     KC_RALT,    NK_TOGG,    KC_RCTL
    ),

    LAYOUT_60_ansi(
        KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
        KC_TRNS,    RGB_HUI,    RGB_HUD,    RGB_SAI,    RGB_SAD,    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      DB_TOGG,    QK_BOOT,    KC_NO,
        KC_NO,      VLK_TOG,    RGB_TOG,    RGB_MOD,    RGB_RMOD,   KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,          SAVE_RGB,
        KC_NO,      RGB_VAI,    RGB_VAD,    RGB_SPI,    RGB_SPD,    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO, 
        KC_NO,      KC_NO,      KC_NO,                      KC_NO,                              KC_NO,      KC_NO,      KC_NO,      KC_NO
    )
};

void matrix_init_user(void) {
    // Call the keymap level matrix init.

    // Read the user config from EEPROM
    user_config.raw = eeconfig_read_user();
}


layer_state_t layer_state_set_user(layer_state_t state) {
#ifdef RGBLIGHT_ENABLE
    switch (biton32(state)) {
    case 2:
        rgblight_mode_noeeprom(1);
        rgblight_setrgb_red();
        break;
    case 3:
        rgblight_mode_noeeprom(1);
		rgblight_setrgb_cyan();
        break;
    default: //  for any other layers, or the default layer
        rgblight_mode_noeeprom(user_config.mode);
        rgblight_sethsv_noeeprom(user_config.hue, user_config.sat, user_config.val);
        break;
    }
#endif
  return state;
}

void keyboard_post_init_user(void) {
	rgblight_mode_noeeprom(user_config.mode);
	rgblight_sethsv_noeeprom(user_config.hue, user_config.sat, user_config.val);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SAVE_RGB:
            if (record->event.pressed) {
                user_config.mode = rgblight_get_mode();
                user_config.hue = rgblight_get_hue();
                user_config.sat = rgblight_get_sat();
                user_config.val = rgblight_get_val();
                eeconfig_update_user(user_config.raw);
            }
            return false;
            break;
        
        default:
            return true;
            break;
    }
    return true;
}

void eeconfig_init_user(void) {  // EEPROM is getting reset!
    user_config.mode = 14;
    user_config.hue = 0;
    user_config.sat = 0;
    user_config.val = 0;
    eeconfig_update_user(user_config.raw);
    rgblight_mode(user_config.mode);
    rgblight_sethsv_noeeprom(user_config.hue, user_config.sat, user_config.val);
}

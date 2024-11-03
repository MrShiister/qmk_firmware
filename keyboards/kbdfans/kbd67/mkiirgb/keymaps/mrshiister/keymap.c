#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
		[0] = LAYOUT_65_ansi_blocker( 
			KC_ESC,  KC_1,     KC_2,     KC_3,  KC_4,  KC_5,  KC_6,    KC_7,  KC_8,    KC_9,     KC_0,     KC_LBRC,  KC_RBRC, KC_BSPC,   KC_HOME,
		    KC_TAB,  KC_QUOT,  KC_COMM,  KC_DOT,KC_P,  KC_Y,  KC_F,    KC_G,  KC_C,    KC_R,     KC_L,     KC_SLSH,  KC_EQL,  KC_BSLASH, KC_PGUP,
			MO(2),   KC_A,     KC_O,     KC_E,  KC_U,  KC_I,  KC_D,    KC_H,  KC_T,    KC_N,     KC_S,     KC_MINS,           KC_ENT,    KC_PGDN,
		    KC_LSFT, KC_SCLN,  KC_Q,     KC_J,  KC_K,  KC_X,  KC_B,    KC_M,  KC_W,    KC_V,     KC_Z,     RSFT_T(KC_DEL),    KC_UP,     KC_END,
		    KC_LCTL, KC_LGUI,  KC_LALT,                KC_SPC,                KC_RALT,           KC_RCTL,  KC_LEFT,           KC_DOWN,   KC_RIGHT),
		[1] = LAYOUT_65_ansi_blocker( 
			KC_ESC,  KC_1,     KC_2,     KC_3,  KC_4,  KC_5,  KC_6,    KC_7,  KC_8,    KC_9,     KC_0,     KC_MINS,  KC_EQL,  KC_BSPC,   KC_HOME,
		    KC_TAB,  KC_Q,     KC_W,     KC_E,  KC_R,  KC_T,  KC_Y,    KC_U,  KC_I,    KC_O,     KC_P,     KC_LBRC,  KC_RBRC, KC_BSLASH, KC_PGUP,
			MO(2),   KC_A,     KC_S,     KC_D,  KC_F,  KC_G,  KC_H,    KC_J,  KC_K,    KC_L,     KC_SCLN,  KC_QUOT,           KC_ENT,    KC_PGDN,
		    KC_LSFT, KC_Z,     KC_X,     KC_C,  KC_V,  KC_B,  KC_N,    KC_M,  KC_COMM, KC_DOT,   KC_SLSH,  RSFT_T(KC_DEL),    KC_UP,     KC_END,
		    KC_LCTL, KC_LGUI,  KC_LALT,                KC_SPC,                KC_RALT,           KC_RCTL,  KC_LEFT,           KC_DOWN,   KC_RIGHT),
		[2] = LAYOUT_65_ansi_blocker( 
			KC_GRV,    KC_F1,    KC_F2,   KC_F3,  KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,  KC_F12,  KC_BSPC,  KC_TRNS,
		    MO(3),     KC_VOLD,  KC_VOLU, KC_MPLY,KC_MSTP, KC_MPRV, KC_MNXT, KC_P7,   KC_P8,   KC_P9,   KC_INS,   KC_PGUP, KC_PGDN, KC_PSCR,  KC_TRNS,
			KC_TRNS,   KC_CAPS,  KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_P4,   KC_P5,   KC_P6,   DF(1),    DF(0),            KC_TRNS,  KC_TRNS,
		    KC_TRNS,   KC_PWR,   KC_SLEP, KC_COPY,KC_PASTE,DYN_REC_START1,DYN_REC_START2, KC_P1, KC_P2, KC_P3, KC_PDOT, KC_TRNS,  KC_TRNS,  KC_TRNS,
		    DYN_MACRO_PLAY1,DYN_MACRO_PLAY2,KC_NO,     KC_P0,                 KC_NUM,            NK_TOGG,   KC_TRNS,          KC_TRNS,  KC_TRNS),
		[3] = LAYOUT_65_ansi_blocker( 
			KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO, KC_NO,
			KC_TRNS,    RGB_HUI,    RGB_HUD,    RGB_SAI,    RGB_SAD,    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      DB_TOGG,    QK_BOOT,    KC_NO, KC_NO,
			KC_NO,      VLK_TOG,    RGB_TOG,    RGB_MOD,    RGB_RMOD,   KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,          KC_NO,         KC_NO,
			KC_NO,      RGB_VAI,    RGB_VAD,    RGB_SPI,    RGB_SPD,    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO, KC_NO, KC_NO,
			KC_NO,      KC_NO,      KC_NO,                      KC_NO,                              KC_NO,      KC_NO,      KC_NO,      KC_NO, KC_NO),
};

/*
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
*/

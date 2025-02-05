#include QMK_KEYBOARD_H


#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

#define EISU LALT(KC_GRV)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Qwerty
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |  =   |   1  |   2  |   3  |   4  |   5  |Pscree|                    | Del  |   6  |   7  |   8  |   9  |   0  |  -   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |  `   |   Q  |   W  |   E  |   R  |   T  |      |                    | PgUp |   Y  |   U  |   I  |   O  |   P  |  \   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Ctrl |   A  |   S  |   D  |   F  |   G  |      |                    | PgDn |   H  |   J  |   K  |   L  |   ;  |  '   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  ||||||||  ESC ||||||||  Alt ||||||||   N  |   M  |   ,  |   .  |   /  | Shift|
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | Ctrl | Alt  |  GUI |      |||||||| Tab  | Space| Lower||||||||  GUI | Enter| Bksp |||||||| Left | Down |  Up  | Right|
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_QWERTY] = LAYOUT( \
    KC_EQL,  KC_1,    KC_2,    KC_3,       KC_4,    KC_5,  KC_PSCR,                      KC_DEL,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, \
    KC_GRV,  KC_Q,    KC_W,    KC_E,       KC_R,    KC_T,  _______,                      KC_PGUP, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS, \
    KC_LCTL, KC_A,    KC_S,    KC_D,       KC_F,    KC_G,  _______,                      KC_PGDN, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
    KC_LSFT, KC_Z,    KC_X,    KC_C,       KC_V,    KC_B,           KC_ESC,    KC_LALT,           KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
    KC_LCTL, KC_LALT, KC_LGUI, _______,           KC_TAB,  KC_SPC,  LOWER,     KC_RGUI,  KC_ENT,  KC_BSPC,          KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT  \
  ),

  /* Lower
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |  ESC |  F1  |  F2  |  F3  |  F4  |  F5  |Pscree|                    | Del  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |  `   |   !  |   @  |   #  |   $  |   %  |      |                    | PgUp |   ^  |   &  |   *  |   (  |   )  |  F12 |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Ctrl |   1  |   2  |   3  |   4  |   5  |      |                    | PgDn |   H  | Left | Down |  Up  | Right|  "   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   6  |   7  |   8  |   9  |   0  |      |  ESC |      |  Alt |      |   N  |   [  |   ]  |   {  |   }  | Shift|
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | Ctrl | Alt  |  GUI |      |||||||| Tab  | Space| Lower||||||||  GUI | Enter| Bksp |||||||| Left | Down |  Up  | Right|
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_LOWER] = LAYOUT(
    KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_PSCR,                       KC_DEL,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  \
    KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______,                       KC_PGUP, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_F12,  \
    KC_LCTL, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______,                       KC_PGDN, KC_H,    KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_DQT,  \
    KC_LSFT, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,              KC_ESC,    KC_LALT,           KC_N,    KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, KC_RSFT, \
    KC_LCTL, KC_LALT, KC_LGUI, _______,          KC_TAB,  KC_SPC,   LOWER,     KC_RGUI,  KC_ENT,  KC_BSPC,          KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT  \
  ),

  // RAISE & ADJUST - not used
};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
         print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
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
  }
  return true;
}

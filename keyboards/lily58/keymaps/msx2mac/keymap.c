#include QMK_KEYBOARD_H
#include "keymap_jp.h"

#ifdef PROTOCOL_LUFA
  #include "lufa.h"
  #include "split_util.h"
#endif
#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif



#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3
#define _NUMERIC 4

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  NUMERIC,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/**
* GUI = Command
* Alt = Option
* CTL = Control
*/

#define TT_LOW TT(_LOWER)
#define TT_RAI TT(_RAISE)
#define TO_QWE TO(_QWERTY)
#define TO_NUM TO(_NUMERIC)

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | KANJI|  1   |  2   |  3   |  4   |  5   |                    |  6   |  7   |  8   |  9   |  0   |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  BS  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |Enter |
 * |------+------+------+------+------+------|  [    |    |  ]    |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |  \   |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI | LOWER| /Space  /       \Enter \  |RAISE | RGUI | Del  |
 *                   |      |      | LOCK |/       /         \      \ |LOCK  |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_QWERTY] = LAYOUT( \
  JP_ZHTG,  KC_1,   KC_2,   KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, \
  KC_TAB,   KC_Q,   KC_W,   KC_E,    KC_R,    KC_T,                       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
  KC_LCTRL, KC_A,   KC_S,   KC_D,    KC_F,    KC_G,                       KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT, \
  KC_LSFT,  KC_Z,   KC_X,   KC_C,    KC_V,    KC_B,    JP_LBRC, JP_RBRC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, JP_BSLS, \
                            KC_LALT, KC_LGUI, TT_LOW,  KC_SPC,  KC_ENT,   TT_RAI,  KC_RGUI, KC_DEL \
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  |  F10 |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |  F11 |  F12 |      |      |      |                    |      |      |      |      |      |  @   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |  1   |  2   |  3   |  4   |  5   |-------.    ,-------|  6   |   7  |   8  |   9  |  0   |  :   |
 * |------+------+------+------+------+------|  [    |    |  ]    |------+------+------+------+------+------|
 * |LShift|      |     |      |      |       |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI | LOWER| /Space  /       \Enter \  |RAISE | RGUI | Del  |
 *                   |      |      | LOCK |/       /         \      \ |LOCK  |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_LOWER] = LAYOUT( \
  KC_ESC,  KC_F1,   KC_F2,  KC_F3,   KC_F4,   KC_F5,                      KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  XXXXXXX, \
  _______, KC_F11,  KC_F12, XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, JP_AT, \
  _______, KC_1,    KC_2,   KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    JP_COLN, \
  _______, XXXXXXX,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______,  XXXXXXX, XXXXXXX,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
                            _______, _______, TO_QWE,  _______, _______,  TO_QWE,  _______, _______\
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |      |      |      |      |      |                    | Ins  |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |      |      |      |      |      |                    |Pause | Home | End  |      |      | DEL  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |      |      |      |      |      |-------.    ,-------| Left | Down | Up   |Right |RCTRL |      |
 * |------+------+------+------+------+------|  [    |    |  ]    |------+------+------+------+------+------|
 * |LShift|      |      |      |      |      |-------|    |-------| NUM  |PageDN|PageUP|      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI | LOWER| /Space  /       \Enter \  |RAISE | RGUI | Del  |
 *                   |      |      | LOCK |/       /         \      \ |LOCK  |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_RAISE] = LAYOUT( \
  KC_ESC,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    KC_INS,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    KC_PAUS, KC_HOME, KC_END,  XXXXXXX, XXXXXXX,  KC_DEL, \
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_LCTRL, XXXXXXX, \
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______,  TO_NUM,  KC_PGDN, KC_PGUP, XXXXXXX, XXXXXXX, XXXXXXX, \
                             _______, _______, TO_QWE,  _______, _______,  TO_QWE,  _______, _______\
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      | MUTE |MEDIA |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      | VOL+ | TRA+ | BRI+ |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      | VOL- | TRA- | BRI- |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI | LOWER| /Space  /       \Enter \  |RAISE | RGUI | Del  |
 *                   |      |      | LOCK |/       /         \      \ |LOCK  |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_ADJUST] = LAYOUT( \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, KC__MUTE, KC_MPLY, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, KC__VOLUP, KC_MFFD, KC_BRMU, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC__VOLDOWN, KC_MRWD, KC_BRMD, XXXXXXX, XXXXXXX,\
                             _______, _______, _______, _______, _______,  _______, _______, _______ \
  ),
/* NUMERIC
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |      | Home | Up   | End  |      |                    |  \   |   7  |   8  |   9  |  +   |  *   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |      | Left | Down |Right |      |-------.    ,-------| .    |   4  |   5  |   6  |  -   |  /   |
 * |------+------+------+------+------+------|  [    |    |  ]    |------+------+------+------+------+------|
 * |LShift|      |PageUp|PageDN|      |     |-------|    |-------|   0  |   1  |   2  |   3  |Enter |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI | LOWER| /Space  /       \Enter \  |RAISE | RGUI | Del  |
 *                   |      |      | LOCK |/       /         \      \ |LOCK  |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_NUMERIC] = LAYOUT( \
  KC_ESC,  XXXXXXX, XXXXXXX,XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  _______, XXXXXXX, KC_HOME,KC_UP,   KC_END,  XXXXXXX,                    JP_YEN,  KC_7,    KC_8,    KC_9,    KC_PLUS, KC_ASTR, \
  _______, XXXXXXX, KC_LEFT,KC_DOWN, KC_RGHT, XXXXXXX,                    KC_DOT,  KC_4,    KC_5,    KC_6,    KC_MINS, KC_SLSH, \
  _______, XXXXXXX, KC_PGUP,KC_PGDN, XXXXXXX, XXXXXXX, _______, _______,  KC_0,    KC_1,    KC_2,    KC_3,    KC_ENT,  XXXXXXX, \
                            _______, _______, TO_QWE,  _______, _______,  TO_QWE,  _______, _______\
),
};

int RGB_current_mode;

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

uint32_t layer_state_set_user(uint32_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

void matrix_init_user(void) {
    #ifdef RGBLIGHT_ENABLE
      RGB_current_mode = rgblight_config.mode;
    #endif
    //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
    #ifdef SSD1306OLED
        iota_gfx_init(!has_usb());   // turns on the display
    #endif
}

//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

// When add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void matrix_scan_user(void) {
   iota_gfx_task();
}

void matrix_render_user(struct CharacterMatrix *matrix) {
  if (is_master) {
    // If you want to change the display of OLED, you need to change here
    matrix_write_ln(matrix, read_layer_state());
    matrix_write_ln(matrix, read_keylog());
    matrix_write_ln(matrix, read_keylogs());
    //matrix_write_ln(matrix, read_mode_icon(keymap_config.swap_lalt_lgui));
    //matrix_write_ln(matrix, read_host_led_state());
    //matrix_write_ln(matrix, read_timelog());
  } else {
    matrix_write(matrix, read_logo());
  }
}

void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;
  matrix_clear(&matrix);
  matrix_render_user(&matrix);
  matrix_update(&display, &matrix);
}
#endif//SSD1306OLED

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef SSD1306OLED
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }

  return true;
}

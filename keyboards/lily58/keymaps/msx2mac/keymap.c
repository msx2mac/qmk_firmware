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
#define _LOWER 11
#define _RAISE 12
#define _ADJUST 3
#define _NUMERIC 4
#define _QWERTY_A 20
#define _LOWER_A 21
#define _RAISE_A 22
#define _NUMERIC_A 24

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  NUMERIC,
  QWERTY_A,
  LOWER_A,
  RAISE_A,
  NUMERIC_A,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/**
* GUI = Command
* Alt = Option
* CTL = Control
*/

#define TT_LOW MO(_LOWER)
#define TT_RAI MO(_RAISE)
#define TO_QWE TO(_QWERTY)
#define TO_NUM TO(_NUMERIC)
#define TT_LOW_A MO(_LOWER_A)
#define TT_RAI_A MO(_RAISE_A)
#define TO_QWE_A TO(_QWERTY_A)
#define TO_NUM_A TO(_NUMERIC_A)

/* QWERTY win
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | KANJI|  1   |  2   |  3   |  4   |  5   |                    |  6   |  7   |  8   |  9   |  0   |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  BS  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |Enter |
 * |------+------+------+------+------+------|  [    |    |  ]    |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |  \   |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LGUI | LAlt | LOWER| /Space  /       \Space \  |RAISE | RCTRL| RShift|
 *                   |      |      | LOCK |/       /         \      \ |LOCK  |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_QWERTY] = LAYOUT( \
  JP_ZHTG,  KC_1,   KC_2,   KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, \
  KC_TAB,   KC_Q,   KC_W,   KC_E,    KC_R,    KC_T,                       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
  KC_LCTRL, KC_A,   KC_S,   KC_D,    KC_F,    KC_G,                       KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT, \
  KC_LSFT,  KC_Z,   KC_X,   KC_C,    KC_V,    KC_B,    JP_LBRC, JP_RBRC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, JP_BSLS, \
                            KC_LGUI, KC_LALT, TT_LOW,  KC_SPC,  KC_SPC,   TT_RAI,  KC_RCTRL, KC_RSFT\
),
/* LOWER win
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  |  F10 |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |  6   |  7   |  8   |  9   |  0   |                    |  YEN |  '   |  "   |  ~   |  -   | -    |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |  1   |  2   |  3   |  4   |  5   |-------.    ,-------|      |  +   |  -   |  =   |  :   |  |   |
 * |------+------+------+------+------+------| F11   |    |  F12 |------+------+------+------+------+------|
 * |LShift|  !   |  @  |  #   |  $   |  %    |-------|    |-------|  ^   |  &   |  *   |  (   |  )   |  _   |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LGUI | LAlt | LOWER| /Space  /       \Space \  |RAISE | RCTRL| RShift|
 *                   |      |      | LOCK |/       /         \      \ |LOCK  |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_LOWER] = LAYOUT( \
  KC_ESC,  KC_F1,   KC_F2,  KC_F3,   KC_F4,   KC_F5,                      KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  XXXXXXX, \
  _______, KC_6,    KC_7,   KC_8,    KC_9,    KC_0,                       JP_YEN,  JP_QUOT, JP_DQUO, JP_TILD, KC_MINS, KC_MINS, \
  _______, KC_1,    KC_2,   KC_3,    KC_4,    KC_5,                       XXXXXXX, JP_PLUS, JP_MINS, JP_EQL, JP_COLN, JP_PIPE, \
  _______, KC_EXLM ,JP_AT,  KC_HASH, KC_DLR,  KC_PERC, KC_F11, KC_F12,  JP_CIRC, JP_AMPR, JP_ASTR, JP_LPRN, JP_RPRN, JP_UNDS, \
                            _______, _______, TO_QWE,  _______, KC_ENT,   TO_QWE,  _______, _______\
),
/* RAISE win
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |      |      |      |      |      |                    | Ins  |      |      |      |      |CTL W |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |  6   |  7   |  8   |  9   |  0   |                    |Pause | Home | End  |      |      | DEL  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |  1   |  2   |  3   |  4   |  5   |-------.    ,-------| Left | Down | Up   |Right |      |RCTRL |
 * |------+------+------+------+------+------|  [    |    |CTL R  |------+------+------+------+------+------|
 * |LShift|DMREC1|DMREC2|DMPLY1|DMPLY2|DMRSTP|-------|    |-------| NUM  |PageDN|PageUP|CTLPUP|CTLPDN|      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | iPad | LAlt | LOWER| /Space  /       \Space \  |RAISE | RCTRL| RShift|
 *                   |      |      | LOCK |/       /         \      \ |LOCK  |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_RAISE] = LAYOUT( \
  KC_ESC,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    KC_INS,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, LCTL(KC_W), \
  _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,                       KC_PAUS, KC_HOME, KC_END,  XXXXXXX, XXXXXXX, KC_DEL, \
  _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                       KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, KC_LCTRL, \
  _______, DM_REC1, DM_REC2, DM_PLY1, DM_PLY2, DM_RSTP  , _______, LCTL(KC_R),  TO_NUM,  KC_PGDN, KC_PGUP, LCTL(KC_PGUP), LCTL(KC_PGDN), XXXXXXX, \
                             DF(_QWERTY_A), _______, TO_QWE,  _______, _______,  TO_QWE,  _______, _______\
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
 *                   | LGUI | LAlt | LOWER| /Space  /       \Space \  |RAISE | RCTRL| RShift|
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
/* NUMERIC win
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |Home  | Up   | End  |      |      |                    |  \   |   7  |   8  |   9  |  +   |  BS  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |Left  | Down | Right|      |      |-------.    ,-------| .    |   4  |   5  |   6  |  -   | Enter|
 * |------+------+------+------+------+------|  [    |    |  ]    |------+------+------+------+------+------|
 * |LShift|      |PageUp|PageDN|      |      |-------|    |-------|   0  |   1  |   2  |   3  |  *   |  /   |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LGUI | LAlt | LOWER| /Space  /       \Space \  |RAISE | RCTRL| RShift|
 *                   |      |      | LOCK |/       /         \      \ |LOCK  |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_NUMERIC] = LAYOUT( \
  JP_ZHTG,  XXXXXXX, XXXXXXX,XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  _______, KC_HOME, KC_UP,  KC_END,  XXXXXXX,  XXXXXXX,                   JP_YEN,  KC_7,    KC_8,    KC_9,    KC_PLUS, KC_BSPC, \
  _______, KC_LEFT, KC_DOWN,KC_RGHT, XXXXXXX, XXXXXXX,                    KC_DOT,  KC_4,    KC_5,    KC_6,    KC_MINS, KC_ENT, \
  _______, XXXXXXX, KC_PGUP,KC_PGDN, XXXXXXX, XXXXXXX, _______, _______,  KC_0,    KC_1,    KC_2,    KC_3,    KC_ASTR, KC_SLSH, \
                            _______, _______, TO_QWE,  _______, _______,  MO(_RAISE),  _______, _______\
),


/* QWERTY iPad
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | KANJI|  1   |  2   |  3   |  4   |  5   |                    |  6   |  7   |  8   |  9   |  0   |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  BS  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |Enter |
 * |------+------+------+------+------+------|  [    |    |  ]    |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |  \   |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LGUI | LAlt | LOWER| /Space  /       \Space \  |RAISE | RCTRL| RShift|
 *                   |      |      | LOCK |/       /         \      \ |LOCK  |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_QWERTY_A] = LAYOUT( \
  KC_CAPS,  KC_1,   KC_2,   KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, \
  KC_TAB,   KC_Q,   KC_W,   KC_E,    KC_R,    KC_T,                       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
  KC_LCTRL, KC_A,   KC_S,   KC_D,    KC_F,    KC_G,                       KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT, \
  KC_LSFT,  KC_Z,   KC_X,   KC_C,    KC_V,    KC_B,    JP_LBRC, JP_RBRC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSLS, \
                            KC_LGUI, KC_LALT, TT_LOW_A,  KC_SPC,  KC_SPC,   TT_RAI_A,  KC_RCTRL, KC_RSFT\
),
/* LOWER iPad
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  |  F10 |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |  6   |  7   |  8   |  9   |  0   |                    |  YEN |  '   |  "   |  ~   |  -   | -    |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |  1   |  2   |  3   |  4   |  5   |-------.    ,-------|      |  +   |  -   |  =   |  :   |  |   |
 * |------+------+------+------+------+------|  F11  |    | F12   |------+------+------+------+------+------|
 * |LShift|  !   |  @  |  #   |  $   |  %    |-------|    |-------|  ^   |  &   |  *   |  (   |  )   |  _   |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LGUI | LAlt | LOWER| /Space  /       \Space \  |RAISE | RCTRL| RShift|
 *                   |      |      | LOCK |/       /         \      \ |LOCK  |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_LOWER_A] = LAYOUT( \
  KC_ESC,  KC_F1,   KC_F2,  KC_F3,   KC_F4,   KC_F5,                      KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  XXXXXXX, \
  _______, KC_6,    KC_7,   KC_8,    KC_9,    KC_0,                       KC_JYEN,  KC_QUOT, KC_DQUO, KC_TILD, KC_MINS, KC_MINS, \
  _______, KC_1,    KC_2,   KC_3,    KC_4,    KC_5,                       XXXXXXX, KC_PLUS, KC_MINS, KC_EQL, KC_COLN, KC_PIPE, \
  _______, KC_EXLM ,KC_AT,  KC_HASH, KC_DLR,  KC_PERC, KC_F11, KC_F12,  KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS, \
                            _______, _______, TO_QWE_A,  _______, KC_ENT,   TO_QWE_A,  _______, _______\
),
/* RAISE iPad
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |      |      |      |      |      |                    | Ins  |      |      |      |      |CTL W|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |  6   |  7   |  8   |  9   |  0   |                    |Pause | Home | End  |      |      | DEL  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |  1   |  2   |  3   |  4   |  5   |-------.    ,-------| Left | Down | Up   |Right |      |RCTRL |
 * |------+------+------+------+------+------|  [    |    |CTRL R |------+------+------+------+------+------|
 * |LShift|DMREC1|DMREC2|DMPLY1|DMPLY2|DMRSTP|-------|    |-------| NUM  |PageDN|PageUP|CTLPUP|CTLPDN|      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | Win | LAlt | LOWER| /Space  /       \Space \  |RAISE | RCTRL| RShift|
 *                   |      |      | LOCK |/       /         \      \ |LOCK  |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_RAISE_A] = LAYOUT( \
  KC_ESC,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    KC_INS,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, LCTL(KC_W), \
  _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,                       KC_PAUS, KC_HOME, KC_END,  XXXXXXX, XXXXXXX, KC_DEL, \
  _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                       KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, KC_LCTRL, \
  _______, DM_REC1, DM_REC2, DM_PLY1, DM_PLY2, DM_RSTP  , _______, LCTL(KC_R),  TO_NUM,  KC_PGDN, KC_PGUP, LCTL(KC_PGUP), LCTL(KC_PGDN), XXXXXXX, \
                             DF(_QWERTY), _______, TO_QWE_A,  _______, _______,  TO_QWE_A,  _______, _______\
),
/* NUMERIC iPad
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |Home  | Up   | End  |      |      |                    |  \   |   7  |   8  |   9  |  +   |  BS  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |Left  | Down | Right|      |      |-------.    ,-------| .    |   4  |   5  |   6  |  -   | Enter|
 * |------+------+------+------+------+------|  [    |    |  ]    |------+------+------+------+------+------|
 * |LShift|      |PageUp|PageDN|      |      |-------|    |-------|   0  |   1  |   2  |   3  |  *   |  /   |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LGUI | LAlt | LOWER| /Space  /       \Space \  |RAISE | RCTRL| RShift|
 *                   |      |      | LOCK |/       /         \      \ |LOCK  |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_NUMERIC_A] = LAYOUT( \
  KC_ESC,  XXXXXXX, XXXXXXX,XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  _______, KC_HOME, KC_UP,  KC_END,  XXXXXXX,  XXXXXXX,                   KC_JYEN,  KC_7,    KC_8,    KC_9,    KC_PLUS, KC_BSPC, \
  _______, KC_LEFT, KC_DOWN,KC_RGHT, XXXXXXX, XXXXXXX,                    KC_DOT,  KC_4,    KC_5,    KC_6,    KC_MINS, KC_ENT, \
  _______, XXXXXXX, KC_PGUP,KC_PGDN, XXXXXXX, XXXXXXX, _______, _______,  KC_0,    KC_1,    KC_2,    KC_3,    KC_ASTR, KC_SLSH, \
                            _______, _______, TO_QWE_A,  _______, _______,  MO(_RAISE_A),  _______, _______\
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
void set_typespeed(void);
const char *read_typespeed(void);

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
    // matrix_write_ln(matrix, read_keylogs());
    matrix_write_ln(matrix, read_typespeed());
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
    set_typespeed();
#endif
    // set_timelog();
  }

  return true;
}

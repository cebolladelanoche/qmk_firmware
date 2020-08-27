#include QMK_KEYBOARD_H


#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;
extern const uint32_t unicode_map[];

#define LAYOUT_uc( \
  L00, L01, L02, L03, L04, L05,           R00, R01, R02, R03, R04, R05, \
  L10, L11, L12, L13, L14, L15,           R10, R11, R12, R13, R14, R15, \
  L20, L21, L22, L23, L24, L25,           R20, R21, R22, R23, R24, R25, \
                      L30, L31, L32, R30, R31, R32 \
  ) \
  LAYOUT( \
    KC_##L00, X(L01), X(L02), X(L03), X(L04), X(L05),                     X(R00), X(R01), X(R02), X(R03), X(R04), KC_##R05, \
    KC_##L10, X(L11), X(L12), X(L13), X(L14), X(L15),                     X(R10), X(R11), X(R12), X(R13), KC_##R14, KC_##R15, \
    KC_##L20, X(L21), X(L22), X(L23), X(L24), X(L25),                     X(R20), X(R21), X(R22), KC_##R23, KC_##R24, KC_##R25, \
                                            KC_##L30, KC_##L31, KC_##L32, KC_##R30, KC_##R31, KC_##R32 \
  )

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3
#define _UNICODE 4

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  BACKLIT,
  RGBRST
};

enum unicode_names {
  A,
  B,
  C,
  D,
  E,
  F,
  G,
  H,
  I,
  J,
  K,
  L,
  M,
  N,
  O,
  P,
  Q,
  R,
  S,
  T,
  U,
  V,
  W,
  X,
  Y,
  Z,
  a,
  b,
  c,
  d,
  e,
  f,
  g,
  h,
  i,
  j,
  k,
  l,
  m,
  n,
  o,
  p,
  q,
  r,
  s,
  t,
  u,
  v,
  w,
  x,
  y,
  z,
  egg,
};


enum macro_keycodes {
  KC_SAMPLEMACRO,
};

#define KC______ KC_TRNS
#define KC_LOWER LOWER
#define KC_RAISE RAISE
#define KC_LESC LT(_LOWER, KC_ESC)
#define KC_RENT LT(_RAISE, KC_ENT)
#define KC_CTLB LCTL(KC_LBRC)
#define KC_ALTB LALT(KC_RBRC)
#define KC_LTOG RGB_TOG
#define KC_LSAI RGB_SAI
#define KC_LSAD RGB_SAD
#define KC_LHUI RGB_HUI
#define KC_LHUD RGB_HUD
#define KC_LVAI RGB_VAI
#define KC_LVAD RGB_VAD
#define KC_LMOD RGB_MOD
#define KC_RMOD RGB_RMOD

const uint32_t PROGMEM unicode_map[] = {
  [A] = 0xff21,
  [B] = 0xff22,
  [C] = 0xff23,
  [D] = 0xff24,
  [E] = 0xff25,
  [F] = 0xff26,
  [G] = 0xff27,
  [H] = 0xff28,
  [I] = 0xff29,
  [J] = 0xff2a,
  [K] = 0xff2b,
  [L] = 0xff2c,
  [M] = 0xff2d,
  [N] = 0xff2e,
  [O] = 0xff2f,
  [P] = 0xff30,
  [Q] = 0xff31,
  [R] = 0xff32,
  [S] = 0xff33,
  [T] = 0xff34,
  [U] = 0xff35,
  [V] = 0xff36,
  [W] = 0xff37,
  [X] = 0xff38,
  [Y] = 0xff39,
  [Z] = 0xff3a,
  [a] = 0xff41,
  [b] = 0xff42,
  [c] = 0xff43,
  [d] = 0xff44,
  [e] = 0xff45,
  [f] = 0xff46,
  [g] = 0xff47,
  [h] = 0xff48,
  [i] = 0xff49,
  [j] = 0xff4a,
  [k] = 0xff4b,
  [l] = 0xff4c,
  [m] = 0xff4d,
  [n] = 0xff4e,
  [o] = 0xff4f,
  [p] = 0xff50,
  [q] = 0xff51,
  [r] = 0xff52,
  [s] = 0xff53,
  [t] = 0xff54,
  [u] = 0xff55,
  [v] = 0xff56,
  [w] = 0xff57,
  [x] = 0xff58,
  [y] = 0xff59,
  [z] = 0xff5a,
  [egg] = 0x1f346
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_kc( \
    //,-----+-----+-----+-----+-----+-----.                 ,-----+-----+-----+-----+-----+-----.
        GRV,   Q,    W,    E,    R,    T,                      Y,    U,    I,    O,    P,  BSLS,\
    //|-----+-----+-----+-----+-----+-----|                 |-----+-----+-----+-----+-----+-----|
        TAB,   A,    S,    D,    F,    G,                      H,    J,    K,    L,  SCLN, QUOT,\
    //|-----+-----+-----+-----+-----+-----.                 ,-----+-----+-----+-----+-----+-----|
        LGUI,  Z,    X,    C,    V,    B,                      N,   M,   COMM, DOT,  SLSH, RGUI,\
    //`-----+-----+-----+-----+-----+-----+-----.     |-----+-----+-----+-----+-----+-----'
                                LSFT, LESC, SPC,       BSPC, RENT, RSFT \
                            //`-----+-----+-----'     `-----+-----+-----'

    ),
    [_LOWER] = LAYOUT_kc( \
    //,-----+-----+-----+-----+-----+-----.                 ,-----+-----+-----+-----+-----+-----.
       TRNS, EXLM,  AT,  HASH,  DLR, PERC,                   CIRC, AMPR, ASTR, LPRN, RPRN, BSLS,\
    //|-----+-----+-----+-----+-----+-----|                 |-----+-----+-----+-----+-----+-----|
       TRNS,  F11,  F12,  F13,  F14,  F15,                   LEFT, DOWN,  UP,  RGHT, TRNS, TRNS,\
    //|-----+-----+-----+-----+-----+-----.                 ,-----+-----+-----+-----+-----+-----|
       LCTL,  F16,  F17,  F18,  F19,  F20,                   MS_L, MS_D, MS_U, MS_R, TRNS, RALT,\
    //`-----+-----+-----+-----+-----+-----+-----.     |-----+-----+-----+-----+-----+-----'
                              TRNS, LOWER , TRNS,       DEL, RAISE, TRNS \
                            //`-----+-----+-----'     `-----+-----+-----'
    ),

    [_RAISE] = LAYOUT_kc(\
    //,-----+-----+-----+-----+-----+-----.                 ,-----+-----+-----+-----+-----+-----.
       TRNS,   1,    2,    3,    4,    5,                      6,    7,    8,    9,    0,  TRNS,\
    //|-----+-----+-----+-----+-----+-----|                 |-----+-----+-----+-----+-----+-----|
       TRNS, HASH,  DLR, LPRN, RPRN, GRV,                    MINS,  EQL, LBRC, RBRC,  BSLS, GRV,\
    //|-----+-----+-----+-----+-----+-----.                 ,-----+-----+-----+-----+-----+-----|
       TRNS, PERC, CIRC, LBRC, RBRC, TILD,                   UNDS, PLUS, LCBR, RCBR, PIPE, TILD,\
    //`-----+-----+-----+-----+-----+-----+-----.     |-----+-----+-----+-----+-----+-----'
                               TRNS, LOWER, TRNS,      TRNS, RAISE, TRNS \
                            //`-----+-----+-----'     `-----+-----+-----'
    ),

    [_UNICODE] = LAYOUT_kc(\
    //,-----+-----+-----+-----+-----+-----.                 ,-----+-----+-----+-----+-----+-----.
        TRNS,  F1,  F2,   F3,   F4,   F5,                      F6,   F7,   F8,  F9,   F10, TRNS,\
    //|-----+-----+-----+-----+-----+-----|                 |-----+-----+-----+-----+-----+-----|
        TRNS, LTOG, LSAI, LHUI, LVAI, LMOD,                  TRNS, TRNS, TRNS, F11,  F12,  TRNS,\
    //|-----+-----+-----+-----+-----+-----.                 ,-----+-----+-----+-----+-----+-----|
        TRNS, TRNS, LSAD, LHUD, LVAD, RMOD,                  TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,\
    //`-----+-----+-----+-----+-----+-----+-----.     |-----+-----+-----+-----+-----+-----'
                               TRNS, TRNS, TRNS,       TRNS, TRNS, TRNS \
                            //`-----+-----+-----'     `-----+-----+-----'
    ),

    [_ADJUST] = LAYOUT_uc(\
    //,-----+-----+-----+-----+-----+-----.                 ,-----+-----+-----+-----+-----+-----.
        GRV,   Q,    W,    E,    R,    T,                      Y,    U,    I,    O,    P,  BSLS,\
    //|-----+-----+-----+-----+-----+-----|                 |-----+-----+-----+-----+-----+-----|
        TAB,   A,    S,    D,    F,    G,                      H,    J,    K,    L,  SCLN, QUOT,\
    //|-----+-----+-----+-----+-----+-----.                 ,-----+-----+-----+-----+-----+-----|
        LGUI,  Z,    X,    C,    V,    B,                      N,   M,   egg, DOT,  SLSH, RGUI,\
    //`-----+-----+-----+-----+-----+-----+-----.     |-----+-----+-----+-----+-----+-----'
                                LSFT, LESC, SPC,       BSPC, RENT, RSFT \
                            //`-----+-----+-----'     `-----+-----+-----'
    )
};

int RGB_current_mode;

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
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
    //matrix_write_ln(matrix, read_keylogs());
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

  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
    case ADJUST:
        if (record->event.pressed) {
          layer_on(_ADJUST);
        } else {
          layer_off(_ADJUST);
        }
        return false;
    case RGB_MOD:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          rgblight_mode(RGB_current_mode);
          rgblight_step();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      return false;
    case RGBRST:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      break;
  }
  return true;
}

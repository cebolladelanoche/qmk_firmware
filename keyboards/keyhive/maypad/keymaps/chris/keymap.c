#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_ortho_5x4(\
                  HYPR(KC_A), HYPR(KC_B), HYPR(KC_C), HYPR(KC_D),\
                  HYPR(KC_E), HYPR(KC_F), HYPR(KC_G), HYPR(KC_H),\
                  HYPR(KC_I), HYPR(KC_J), HYPR(KC_K), HYPR(KC_L),\
                  HYPR(KC_M), HYPR(KC_N), HYPR(KC_O), HYPR(KC_P),\
                  TT(1), TT(2), TT(3), TT(4)),
	[1] = LAYOUT_ortho_5x4(\
                  HYPR(KC_Q), HYPR(KC_R), HYPR(KC_S), HYPR(KC_T),\
                  HYPR(KC_U), HYPR(KC_V), HYPR(KC_W), HYPR(KC_X),\
                  HYPR(KC_Y), HYPR(KC_Z), HYPR(KC_1), HYPR(KC_2),\
                  HYPR(KC_3), HYPR(KC_4), HYPR(KC_5), HYPR(KC_6),\
                  TT(0), TT(2), TT(3), TT(4)),
	[2] = LAYOUT_ortho_5x4(\
                  MEH(KC_A), MEH(KC_B), MEH(KC_C), MEH(KC_D),\
                  MEH(KC_E), MEH(KC_F), MEH(KC_G), MEH(KC_H),\
                  MEH(KC_I), MEH(KC_J), MEH(KC_K), MEH(KC_L),\
                  MEH(KC_M), MEH(KC_N), MEH(KC_O), MEH(KC_P),\
                  TT(1), TT(0), TT(3), TT(4)),
	[3] = LAYOUT_ortho_5x4(\
                  MEH(KC_Q), MEH(KC_R), MEH(KC_S), MEH(KC_T),\
                  MEH(KC_U), MEH(KC_V), MEH(KC_W), MEH(KC_X),\
                  MEH(KC_Y), MEH(KC_Z), MEH(KC_1), MEH(KC_2),\
                  MEH(KC_3), MEH(KC_4), MEH(KC_5), MEH(KC_6),\
                  TT(1), TT(2), TT(0), TT(4)),
	[4] = LAYOUT_ortho_5x4(\
                  RESET, _______, _______, _______,\
                  _______, _______, _______, _______,\
                  _______, _______, _______, _______,\
                  _______, _______, _______, _______,\
                  TT(1), TT(2), TT(3), TT(0)),
};
//just in case
                  //HYPR(KC_7), HYPR(KC_8), HYPR(KC_9), HYPR(KC_0),\
                  //HYPR(KC_MINUS), HYPR(KC_EQL), HYPR(KC_LBRC), HYPR(KC_RBRC),\
                  //HYPR(KC_BSLS), HYPR(KC_SCLN), HYPR(KC_QUOT), HYPR(KC_GRV),\
                  //HYPR(KC_COMM), HYPR(KC_SLSH), HYPR(KC_PPLS), HYPR(KC_PMNS),\

/* Copyright 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "muse.h"


enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _MOUSE,
  _ADJUST
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  MOUSE,
  ADJUST
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define ADJUST MO(_ADJUST)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_planck_grid(
KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC,
KC_TAB, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
KC_LSPO, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSPC,
KC_CAPS, KC_LCTL, KC_LALT, KC_LGUI, LOWER, LT(_MOUSE, KC_SPC), KC_SPC, RAISE, LCA(KC_LEFT), LCA(KC_RGHT), KC_NO, KC_ENT
),

[_LOWER] = LAYOUT_planck_grid(
KC_TRNS, SGUI(KC_T), HYPR(KC_A), HYPR(KC_J), SGUI(KC_4), LSFT(KC_MINS), LSFT(KC_EQL), KC_P7, KC_P8, KC_P9, KC_PMNS, KC_PSLS,
KC_MRWD, KC_MFFD, KC_VOLD, KC_MPLY, KC_VOLU, LSFT(KC_6), LSFT(KC_7), KC_P4, KC_P5, KC_P6, KC_PPLS, KC_PAST,
KC_TRNS, LGUI(KC_A), LGUI(KC_B), LGUI(KC_I), LGUI(KC_DOT), KC_MINS, KC_EQL, KC_P1, KC_P2, KC_P3, KC_PEQL, KC_PDOT,
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LGUI(KC_SPC), LGUI(KC_SPC), KC_P0, LCA(KC_D), LCA(KC_T), LCA(KC_ENT), KC_TRNS
),

[_RAISE] = LAYOUT_planck_grid(
KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,
KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_TRNS, KC_TRNS,
KC_TRNS, KC_GRV, KC_CIRC, KC_AMPR, KC_ASTR, KC_QUES, KC_TRNS, KC_BSPC, LALT(KC_BSPC), LGUI(KC_BSPC), KC_TRNS, KC_TRNS,
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, ADJUST, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),

[_MOUSE] = LAYOUT_planck_grid(
KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_MS_U, KC_NO, KC_NO, KC_NO,
KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_MS_L, KC_MS_D, KC_MS_R, KC_NO, KC_NO,
KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_BTN2, KC_BTN1, KC_NO, KC_NO, KC_NO, KC_NO
),

[_ADJUST] = LAYOUT_planck_grid(
KC_TRNS, RESET, DEBUG, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_DEL,
KC_TRNS, KC_TRNS, MU_MOD, AU_ON, AU_OFF, AG_NORM, AG_SWAP, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS,
KC_TRNS, MUV_DE, MUV_IN, MU_ON, MU_OFF, MI_ON, MI_OFF, TERM_ON, TERM_OFF, KC_TRNS, KC_TRNS, KC_TRNS,
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
)

};

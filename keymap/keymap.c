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
  _DVORAK,
  _LOWER,
  _RAISE,
  _FUNCT,
  _MOUSE,
  _ADJUST
};

// Layer shortcuts
#define DVORAK DF(_DVORAK)
#define QWERTY DF(_QWERTY)
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define MOUSE LT(_MOUSE, KC_SPC)
#define FUNCT MO(_FUNCT)
#define ADJUST MO(_ADJUST)

// Window management via Magnet app
#define WIN50L LCA(KC_LEFT)
#define WIN50R LCA(KC_RGHT)
#define WIN33L LCA(KC_D)
#define WIN66R LCA(KC_T)
#define WIN100 LCA(KC_ENT)

// Misc mac shortcuts
#define ALFRED LGUI(KC_SPC) // Toggle Alfred
#define TYPOGR SGUI(KC_T) // Fire ALS Typograph workflow
#define ADD_TSK HYPR(KC_A) // Add task via Todoist
#define CLIPBRD HYPR(KC_J) // Show Alfred clipboard
#define SCRSHT SGUI(KC_4) // Make a screenshot
#define TIMER HYPR(KC_T) // Toggle Tyme2

// Player shortcuts
#define PREV KC_MEDIA_PREV_TRACK
#define NEXT KC_MEDIA_NEXT_TRACK
#define VOL_DN KC_VOLD
#define VOL_UP KC_VOLU
#define PLAY KC_MPLY

// Copy, paste etc
#define SEL_ALL LGUI(KC_A)
#define CUT LGUI(KC_B)
#define COPY LGUI(KC_I)
#define PASTE LGUI(KC_DOT)
#define RMWRD LALT(KC_BSPC)
#define RMLINE LGUI(KC_BSPC)
#define CTL_TAB LCTL_T(KC_TAB)

// Brackets and punctuation
#define CURLL LSFT(KC_MINS)
#define CURLR LSFT(KC_EQL)
#define RUCOMMA LSFT(KC_6)
#define RUDOT LSFT(KC_7)

#include "tapdance.c"

// Keymap
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_planck_grid(
KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,        KC_T,   KC_Y,   KC_U,  KC_I,    KC_O,    KC_P,    KC_LBRC,
CTL_TAB, KC_A,    KC_S,    KC_D,    KC_F,        KC_G,   KC_H,   KC_J,  KC_K,    KC_L,    KC_SCLN, KC_QUOT,
KC_LSPO, KC_Z,    KC_X,    KC_C,    KC_V,        KC_B,   KC_N,   KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC,
XXXXXXX, XXXXXXX, KC_LALT, KC_LGUI, TD(LOW_ALF), KC_ENT, KC_SPC, RAISE, FUNCT,   XXXXXXX, XXXXXXX, XXXXXXX
),

[_DVORAK] = LAYOUT_planck_grid(
KC_ESC,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,        KC_Y,   KC_F,   KC_G,  KC_C,    KC_R,    KC_L,    KC_SLSH,
CTL_TAB, KC_A,    KC_O,    KC_E,    KC_U,        KC_I,   KC_D,   KC_H,  KC_T,    KC_N,    KC_S,    KC_MINUS,
KC_LSPO, KC_SCLN, KC_Q,    KC_J,    KC_K,        KC_X,   KC_B,   KC_M,  KC_W,    KC_V,    KC_Z,    KC_RSPC,
XXXXXXX, XXXXXXX, KC_LALT, KC_LGUI, TD(LOW_ALF), KC_ENT, KC_SPC, RAISE, FUNCT,   XXXXXXX, XXXXXXX, XXXXXXX
),

[_LOWER] = LAYOUT_planck_grid(
TIMER,   TYPOGR,  ADD_TSK, CLIPBRD, SCRSHT,  CURLL,    CURLR,   KC_P7,  KC_P8,   KC_P9,   KC_PMNS, KC_PSLS,
PREV,    NEXT,    VOL_DN,  PLAY,    VOL_UP,  RUCOMMA,  RUDOT,   KC_P4,  KC_P5,   KC_P6,   KC_PPLS, KC_PAST,
_______, SEL_ALL, CUT,     COPY,    PASTE,   KC_MINS,  KC_EQL,  KC_P1,  KC_P2,   KC_P3,   KC_PEQL, KC_PDOT,
_______, _______, _______, _______, _______, _______,  _______, KC_P0,  _______, _______, _______, _______
),

[_RAISE] = LAYOUT_planck_grid(
XXXXXXX, KC_TILD, KC_BSLS, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, TD(WIN_L),WIN100, TD(WIN_R),  XXXXXXX, XXXXXXX,
KC_CAPS, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_F18, _______,
CURLL,   KC_GRV,  KC_CIRC, KC_AMPR, KC_ASTR, KC_QUES,  _______, KC_BSPC, RMWRD,   RMLINE,  _______, CURLR,
_______, _______, _______, _______, ADJUST,  _______,  _______, _______, _______, _______, _______, _______
),

[_FUNCT] = LAYOUT_planck_grid(
XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   XXXXXXX,
XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, KC_F5,   KC_F6,   KC_F7,   KC_F8,   XXXXXXX,
XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX,
XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

[_MOUSE] = LAYOUT_planck_grid(
XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, KC_MS_U, XXXXXXX, XXXXXXX, XXXXXXX,
XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, XXXXXXX,
XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_BTN2, KC_BTN1, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

[_ADJUST] = LAYOUT_planck_grid(
_______, RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI,  RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_DEL,
_______, _______, MU_MOD,  AU_ON,   AU_OFF,  _______,  DVORAK,  QWERTY, _______, _______, _______, _______,
_______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,    MI_OFF,  TERM_ON, TERM_OFF, _______, _______, _______,
_______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______
)

};


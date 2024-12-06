/*
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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base     */
    [0] = LAYOUT_ortho_4x6(
        KC_VOLU,    KC_VOLD,
        KC_BSPC,    KC_TRNS,    KC_EQL,     KC_ESC,
        KC_NUM,     KC_PSLS,    KC_PAST,    KC_PMNS,
        KC_P7,      KC_P8,      KC_P9,      KC_PPLS,
        KC_P4,      KC_P5,      KC_P6,
        KC_P1,      KC_P2,      KC_P3,      KC_PENT,
        KC_P0,      KC_PDOT
    ),

    /* Numpad
    * ┌─────┬─────┬─────┬─────┐
    * │  7  │  8  │  9  │  *  │
    * ├─────┼─────├─────┼─────┤
    * │  4  │  5  │  6  │  -  │
    * ├─────┼─────┼─────┼─────┤
    * │  1  │  2  │  3  │  +  │
    * ├─────┼─────┼─────┼─────┤
    * │  0  │  .  │  /  │  =  │
    * └─────┴─────┴─────┴─────┘
     */
    [1] = LAYOUT_ortho_4x6(
        KC_VOLU,    KC_VOLD,
        KC_BSPC,    KC_TRNS,    KC_EQL,     KC_ESC,
        KC_NUM,     KC_PSLS,    KC_PAST,    KC_PMNS,
        KC_P7,      KC_P8,      KC_P9,      KC_PPLS,
        KC_P4,      KC_P5,      KC_P6,
        KC_P1,      KC_P2,      KC_P3,      KC_PENT,
        KC_P0,      KC_PDOT
    ),

    /* Mini KeyBoard
    * ┌─────┬─────┬─────┬─────┐
    * │ ESC │  1  │  2  │  3  │
    * ├─────┼─────┼─────┼─────┤
    * │ TAB │  Q  │  W  │  E  │
    * ├─────┼─────┼─────┼─────┤
    * │SHIFT│  A  │  S  │  D  │
    * ├─────┼─────┼─────┼─────┤
    * │CTRL │  C  │  R  │SPACE│
    * └─────┴─────┴─────┴─────┘
     */
    [2] = LAYOUT_ortho_4x6(
        KC_VOLU,    KC_VOLD,
        KC_BSPC,    KC_TRNS,    KC_EQL,     KC_ESC,
        KC_NUM,     KC_PSLS,    KC_PAST,    KC_PMNS,
        KC_P7,      KC_P8,      KC_P9,      KC_PPLS,
        KC_P4,      KC_P5,      KC_P6,
        KC_P1,      KC_P2,      KC_P3,      KC_PENT,
        KC_P0,      KC_PDOT
    ),

    /* FN Keyboard
    * ┌─────┬─────┬─────┬─────┐
    * │ F1  │ F2  │ F3  │ F4  │
    * ├─────┼─────┼─────┼─────┤
    * │ F5  │ F6  │ F7  │ F8  │
    * ├─────┼─────┼─────┼─────┤
    * │ F9  │ F10 │ F11 │ F12 │
    * ├─────┼─────┼─────┼─────┤
    * │BASE │     │     │     │
    * └─────┴─────┴─────┴─────┘
     */
    [3] = LAYOUT_ortho_4x6(
        KC_VOLU,    KC_VOLD,
        KC_BSPC,    KC_TRNS,    KC_EQL,     KC_ESC,
        KC_NUM,     KC_PSLS,    KC_PAST,    KC_PMNS,
        KC_P7,      KC_P8,      KC_P9,      KC_PPLS,
        KC_P4,      KC_P5,      KC_P6,
        KC_P1,      KC_P2,      KC_P3,      KC_PENT,
        KC_P0,      KC_PDOT
    ),
};
#if 0
bool encoder_update_user(uint8_t index, bool clockwise) {
    switch (get_highest_layer(layer_state)) {
        case 0:
            // main layer, volume
            if (clockwise) {
                tap_code(KC_VOLU);
            } else {
                tap_code(KC_VOLD);
            }
            break;
    }
    return false;
}
#else
bool encoder_update_user(uint8_t index, bool clockwise) {
	if(index == 0){
		if(clockwise){
			tap_code(dynamic_keymap_get_keycode(biton32(layer_state),5,1));
		}else{
			tap_code(dynamic_keymap_get_keycode(biton32(layer_state),5,3));
		}
    }
    return true;
}
#endif
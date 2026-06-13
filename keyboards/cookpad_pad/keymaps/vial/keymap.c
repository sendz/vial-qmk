#include "cookpad_pad.h"

#define _BASE 0
#define _FN1 1

#define KC_ KC_TRANSPARENT
#define KC_DFN1 LT(_FN1, KC_D)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT(
  // |----|----|----|
       LCTL(KC_C)  , LCTL(KC_V)  , SGUI(KC_S)  ,
  // |----|----|----|
       QK_MACRO_0  , QK_MACRO_1  , TG(1)
  // |----|----|----|
  ),

  [_FN1] = LAYOUT(
  // |----|----|----|
      KC_MPRV, KC_MPLY, KC_MNXT,
  // |----|----|----|
      KC_VOLD, KC_VOLU , TG(0)
  // |----|----|----|
  )


};
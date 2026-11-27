#include "cookpad_pad.h"

#define _BASE 0
#define _FN1 1

#define KC_ KC_TRANSPARENT
#define KC_DFN1 LT(_FN1, KC_D)

#define KC_RTOG RGB_TOG
#define KC_RMOF RGB_MODE_FORWARD
#define KC_RMOR RGB_MODE_REVERSE
#define KC_RHUI RGB_HUI
#define KC_RHUD RGB_HUD

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT_kc(
  // |----|----|----|
       C  , O  , K  ,
  // |----|----|----|
       P  , A  ,DFN1
  // |----|----|----|
  ),

  [_FN1] = LAYOUT_kc(
  // |----|----|----|
      RMOF,RHUI,RTOG,
  // |----|----|----|
      RMOR,RHUD,
  // |----|----|----|
  )


};
#ifndef COOKPAD_PAD_H
#define COOKPAD_PAD_H

#include "quantum.h"

#define LAYOUT( \
    K01, K02, K03, \
    K11, K12, K13  \
) \
{ \
    { K01, K02, K03 }, \
    { K11, K12, K13 }, \
}


#define LAYOUT_kc( \
    A1, A2, A3, \
    B1, B2, B3 \
  ) \
  LAYOUT( \
    KC_##A1, KC_##A2, KC_##A3, \
    KC_##B1, KC_##B2, KC_##B3  \
  )

#endif
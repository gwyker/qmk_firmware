// Special keys
#define KC_MAGICTAB  MAGICTAB
#define KC_RESET     RESET
#define KC_____     _______

// Mod Taps
#define KC_ALT_TAB   LALT_T(KC_TAB)
#define KC_CTL_ESC   LCTL_T(KC_ESC)
#define KC_rCTL_ENT   RCTL_T(KC_ENT)
#define KC_GUI_BSPC   LGUI_T(KC_BSPC)

// Mod keys
#define KC_G_TAB   LGUI(KC_TAB)
#define KC_G_GRV   LGUI(KC_GRV)
#define KC_G_1   LGUI(KC_1)
#define KC_G_2   LGUI(KC_2)
#define KC_G_3   LGUI(KC_3)
#define KC_G_4   LGUI(KC_4)
#define KC_G_5   LGUI(KC_5)

// Layer taps
#define KC__1_SPC   LT(1,KC_SPC)
#define KC__2_SPC   LT(2,KC_SPC)
#define KC__6_ENT   LT(6,KC_ENT)
#define KC__7_BSPC   LT(7,KC_BSPC)

// Layer toggles
#define KC_GAME     TG(4)
#define KC_MOUSE     TG(5)

// RGB
#define KC_RGB_TOG  RGB_TOG
#define KC_RGB_MOD  RGB_TOG
#define KC_RGB_HUI  RGB_TOG
#define KC_RGB_SAI  RGB_TOG
#define KC_RGB_VAI  RGB_TOG
#define KC_RGB_SPI  RGB_TOG
#define KC_RGB_RMOD  RGB_TOG
#define KC_RGB_HUD  RGB_TOG
#define KC_RGB_SAD  RGB_TOG
#define KC_RGB_VAD  RGB_TOG
#define KC_RGB_SPD  RGB_TOG

// Layer codes
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _POWER 3
#define _GAME 4
#define _MOUSE 5
#define _EMOJI 6

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
//   LOWER,
//   RAISE,
//   POWER,
//   GAME,
//   MOUSE,
  MAGICTAB,
//   EMOJI,
};


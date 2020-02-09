#include QMK_KEYBOARD_H


#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _POWER 3
#define _GAME 4
#define _MOUSE 5
#define _EMOJI 6
bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
//   LOWER,
//   RAISE,
//   POWER,
//   GAME,
//   MOUSE,
  ALT_TAB,
//   EMOJI,
};

#define KC_SALT      ALT_TAB
#define KC_CTL_ESC   LCTL_T(KC_ESC)
#define KC_CTL_ENT   LCTL_T(KC_ENT)
#define KC_GUI_ENT   LGUI_T(KC_ENT)
#define KC_CTL_SPC   LCTL_T(KC_SPC)
#define KC_CTL_SPC   LCTL_T(KC_SPC)
#define KC_GAME      TG(_GAME)
#define KC_LOWER     MO(_LOWER)
#define KC_RAISE_SPC LT(_RAISE, KC_SPC)

enum unicode_name {
  GRIN, // grinning face 😊
  TJOY, // tears of joy 😂
  SMILE, // grining face with smiling eyes 😁
  HEART, // heart ❤
  EYERT, // smiling face with heart shaped eyes 😍
  CRY, // crying face 😭
  SMEYE, // smiling face with smiling eyes 😊
  UNAMU, // unamused 😒
  KISS, // kiss 😘
  HART2, // two hearts 💕
  WEARY, // weary 😩
  OKHND, // ok hand sign 👌
  PENSV, // pensive 😔
  SMIRK, // smirk 😏
  RECYC, // recycle ♻
  WINK, // wink 😉
  THMUP, // thumb up 👍
  THMDN, // thumb down 👎
  PRAY, // pray 🙏
  PHEW, // relieved 😌
  MUSIC, // musical notes
  FLUSH, // flushed 😳
  CELEB, // celebration 🙌
  CRY2, // crying face 😢
  COOL, // smile with sunglasses 😎
  NOEVS, // see no evil
  NOEVH, // hear no evil
  NOEVK, // speak no evil
  POO, // pile of poo
  EYES, // eyes
  VIC, // victory hand
  BHART, // broken heart
  SLEEP, // sleeping face
  SMIL2, // smiling face with open mouth & sweat
  HUNRD, // 100
  CONFU, // confused
  TONGU, // face with tongue & winking eye
  DISAP, // disappointed
  YUMMY, // face savoring delicious food
  CLAP, // hand clapping
  FEAR, // face screaming in fear
  HORNS, // smiling face with horns
  HALO, // smiling face with halo
  BYE, // waving hand
  SUN, // sun
  MOON, // moon
  SKULL, // skull
};

const uint32_t PROGMEM unicode_map[] = {
  [GRIN] = 0x1F600,
  [TJOY] = 0x1F602,
  [SMILE] = 0x1F601,
  [HEART] = 0x2764,
  [EYERT] = 0x1f60d,
  [CRY] = 0x1f62d,
  [SMEYE] = 0x1F60A,
  [UNAMU] = 0x1F612,
  [KISS] = 0x1F618,
  [HART2] = 0x1F495,
  [WEARY] = 0x1F629,
  [OKHND] = 0x1F44C,
  [PENSV] = 0x1F614,
  [SMIRK] = 0x1F60F,
  [RECYC] = 0x267B,
  [WINK] = 0x1F609,
  [THMUP] = 0x1F44D,
  [THMDN] = 0x1F44E,
  [PRAY] = 0x1F64F,
  [PHEW] = 0x1F60C,
  [MUSIC] = 0x1F3B6,
  [FLUSH] = 0x1F633,
  [CELEB] = 0x1F64C,
  [CRY2] = 0x1F622,
  [COOL] = 0x1F60E,
  [NOEVS] = 0x1F648,
  [NOEVH] = 0x1F649,
  [NOEVK] = 0x1F64A,
  [POO] = 0x1F4A9,
  [EYES] = 0x1F440,
  [VIC] = 0x270C,
  [BHART] = 0x1F494,
  [SLEEP] = 0x1F634,
  [SMIL2] = 0x1F605,
  [HUNRD] = 0x1F4AF,
  [CONFU] = 0x1F615,
  [TONGU] = 0x1F61C,
  [DISAP] = 0x1F61E,
  [YUMMY] = 0x1F60B,
  [CLAP] = 0x1F44F,
  [FEAR] = 0x1F631,
  [HORNS] = 0x1F608,
  [HALO] = 0x1F607,
  [BYE] = 0x1F44B,
  [SUN] = 0x2600,
  [MOON] = 0x1F314,
  [SKULL] = 0x1F480,
};

// Tap Dance
typedef struct {
  bool is_press_action;
  int state;
} tap;

enum {
  SINGLE_TAP = 1,
  SINGLE_HOLD = 2,
  DOUBLE_TAP = 3,
  DOUBLE_HOLD = 4,
  DOUBLE_SINGLE_TAP = 5, //send two single taps
  TRIPLE_TAP = 6,
  TRIPLE_HOLD = 7
};

enum {
  TD_SCLN = 0,
  X_SFT
};

int cur_dance (qk_tap_dance_state_t *state);

//for the x tap dance. Put it here so it can be used in any keymap
void x_finished (qk_tap_dance_state_t *state, void *user_data);
void x_reset (qk_tap_dance_state_t *state, void *user_data);

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  // key   :   SEMICOLON
  // one tap: ;
  // two taps: :
  [TD_SCLN] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_COLN)

  // key   :   SHIFT
  // one tap: (
  // two taps: [
  // three taps: {
  // hold: Shift

// Other declarations would go here, separated by commas, if you have them
};

// const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// 	[_QWERTY] = LAYOUT_kc(
//   //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
//      SALT, 1  , 2  , 3  , 4  , 5  ,                6  , 7  , 8  , 9  , 0  ,BSLS,
//   //|----+----+----+----+----+----|              |----+----+----+----+----+----|
//      TAB , Q  , W  , E  , R  , T  ,                Y  , U  , I  , O  , P  ,CRET,
//   //|----+----+----+----+----+----|              |----+----+----+----+----+----|
//      CESC, A  , S  , D  , F  , G  ,                H  , J  , K  , L  ,SCLN,QUOT,
//   //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
//      LSPO, Z  , X  , C  , V  , B  ,GAME,     LALT, N  , M  ,COMM, DOT,SLSH,RSPC,
//   //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
//                        BSPC,LOWR,GENT,         CSPC,RAIS,ENT
//   //                  `----+----+----'        `----+----+----'
//   ),

//   [_QWERTY] = LAYOUT_kc(
//   //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
//         SALT,    1,       2,       3,       4,       5,                                  6,       7,       8,       9,       0,       BSLS,
//   //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
//          TAB,    Q,       W,       E,       R,       T,                                  Y,       U,       I,       O,       P,    CTL_ENT,
//   //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
//      CTL_ESC,    A,       S,       D,       F,       G,                                  H,       J,       K,       L,       SCLN,    QUOT,
//   //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
//         LSPO,    Z,       X,       C,       V,       B,       GAME,            LALT,     N,       M,      COMM,    DOT,      SLSH,    RSPC,
//   //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
//                                        BSPC,  LOWER,  GUI_ENT,                   CTL_SPC, RAISE_SPC,  ENT
//                                 // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
//   ),

//   [_LOWER] = LAYOUT_kc(
//   //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
//      _______,    F1,      F2,      F3,      F4,      F5,                                 F6,      F7,      F8,      F9,      F0,     APP,
//   //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
//      RESET,      1,       2,       3,       4,       5,                                  6,       7,       8,       9,       0,       PGDN,
//   //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
//         DEL,  _______,    LEFT,    RGHT,    UP,      LBRC,                               RBRC,    P4,      P5,      P6,      PLUS,    HOME,
//   //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
//      BL_STEP, _______, _______, _______,    DOWN,    LCBR,    LPRN,             RPRN,    RCBR,    P1,      P2,      P3,      MINS,    END,
//   //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
//                                     _______, _______,    DEL,                       DEL,  _______,    P0
//                                 // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
//   ),

//   [_RAISE] = LAYOUT_kc(
//   //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
//         F12,     F1,      F2,      F3,      F4,      F5,                                 F6,      F7,      F8,      F9,      F10,     F11,
//   //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
//      RGB_TOG,    EXLM,    AT,      HASH,    DLR,     PERC,                               CIRC,    AMPR,    ASTR,    LPRN,    RPRN, _______,
//   //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
//      RGB_MOD,    MPRV,    MNXT,    VOLU,    PGUP,    UNDS,                               EQL,     HOME, RGB_HUI, RGB_SAI, RGB_VAI, _______,
//   //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
//         MUTE,    MSTP,    MPLY,    VOLD,    PGDN,    MINS,    LPRN,          _______,    PLUS,    END,  RGB_HUD, RGB_SAD, RGB_VAD, _______,
//   //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
//                                     _______, _______, _______,                   _______, _______, _______
//                                 // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
//   ),

//   [_POWER] = LAYOUT_kc(
//   //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
//      _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
//   //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
//      _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
//   //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
//      _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
//   //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
//      _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
//   //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
//                                     _______, _______, _______,                   _______, _______, _______
//                                 // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
//   )
// };

// /* Emoji
//  * ,-----------------------------------------------------------------------------------.
//  * |  💕  |  😢  |  😩  | 😍   |  😏  |  😂  |  ♻  |  😒  |  🎶  | 👌  |  😔  |  😌  |
//  * |------+------+------+------+------+-------------+------+------+------+------+------|
//  * |  👍  |  🙏  |  😁  |  😅  |  😳  |  😊  |  ❤  |  👋  |  😘  | 🙌  |  😎  | 🙈   |
//  * |------+------+------+------+------+------+------+------+------+------+------+------|
//  * |  👎  |  😴  |  👏  |  😭  |  ✌  |  💔  |  ☀  |  😊  |  😉  |  🌔  |  😕  |  🙉  |
//  * |------+------+------+------+------+------+------+------+------+------+------+------|
//  * |  💩  |  👀  |  💯  |      |  💀  |  😈  |  😇  |  😱  |     |  😋  |  😞  |  🙊  |
//  * `-----------------------------------------------------------------------------------'
//  */
// [_EMOJI] = LAYOUT(
//   X(HART2), X(CRY2),X(WEARY),X(EYERT),X(SMIRK), X(TJOY),X(RECYC),X(UNAMU),X(MUSIC),X(OKHND),X(PENSV), X(PHEW),
//   X(THMUP), X(PRAY),X(SMILE),X(SMIL2),X(FLUSH), X(GRIN),X(HEART),  X(BYE), X(KISS),X(CELEB), X(COOL),X(NOEVS),
//   X(THMDN),X(SLEEP), X(CLAP),  X(CRY),  X(VIC),X(BHART),  X(SUN),X(SMEYE), X(WINK), X(MOON),X(CONFU),X(NOEVH),
//     X(POO), X(EYES), X(HUNRD),_______, X(SKULL),X(HORNS), X(HALO), X(FEAR),_______,X(YUMMY),X(DISAP),X(NOEVK),
//                                            _______, _______, _______
// ),


//// TODO WHEN KEYMAPPIN ////
// KC_F13 -> ALT_TAB
// KC_F14 -> LT(_EMOJI, OSM(_EMOJI))
// KC_LSPO ->
// KC_RSPO ->
// [disabled] KC_SCLN -> TD(TD_SCLN)
// add emoji layer 6

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT(
        ALT_TAB, KC_1, KC_2, KC_3, KC_4, KC_5,             KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSLS,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,             KC_Y, KC_U, KC_I, KC_O, KC_P, LCTL_T(KC_ENT),
        LCTL_T(KC_ESC), KC_A, KC_S, KC_D, KC_F, KC_G,             KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
        KC_LSPO, KC_Z, KC_X, KC_C, KC_V, KC_B, TG(4),         KC_LALT, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSPC,
                                KC_BSPC, MO(1), KC_LGUI,     LCTL_T(KC_SPC), LT(2,KC_SPC), KC_ENT
    ),
	[1] = LAYOUT(
        KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,             KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_APP,
        RALT(KC_TAB), KC_TRNS, KC_TRNS, KC_UP, KC_TRNS, KC_TRNS,             KC_TRNS, KC_P7, KC_P8, KC_P9, KC_PSCR, KC_INS,
        KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS,             TG(5), KC_P4, KC_P5, KC_P6, KC_HOME, KC_PGUP,
        KC_LALT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MUTE,         KC_TRNS, MO(6), KC_P1, KC_P2, KC_P3, KC_END, KC_PGDN,
                                KC_TRNS, KC_TRNS, KC_TRNS,     KC_DEL, KC_TRNS, KC_P0
    ),
	[2] = LAYOUT(
        KC_F12, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,             KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,
        KC_TRNS, KC_LCBR, KC_LPRN, KC_LBRC, KC_EQL, KC_TILD,             KC_PIPE, KC_PLUS, KC_RBRC, KC_RPRN, KC_RCBR, KC_TRNS,
        KC_TRNS, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC,             KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DQUO,
        KC_LALT, KC_TRNS, KC_TRNS, KC_TRNS, KC_UNDS, KC_GRV, KC_TRNS,         KC_TRNS, KC_BSLS, KC_MINS, KC_LT, KC_GT, KC_QUES, KC_RALT,
                                KC_TRNS, KC_TRNS, KC_DEL,     KC_TRNS, KC_TRNS, RESET
    ),
	[3] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PSCR, KC_TRNS,
        KC_TRNS, KC_MPRV, KC_MNXT, KC_VOLU, KC_TRNS, KC_TRNS,             RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI,
        KC_MUTE, KC_MSTP, KC_MPLY, KC_VOLD, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, RGB_RMOD, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD,
                                KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS
    ),
	[4] = LAYOUT(
        KC_ENT, KC_1, KC_2, KC_3, KC_4, KC_5,             KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSLS,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,             KC_Y, KC_U, KC_I, KC_O, KC_P, KC_MINS,
        KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G,             KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_TRNS,         KC_DEL, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
                                KC_RALT, KC_SPC, MO(1),     MO(2), KC_SPC, KC_ENT
    ),
	[5] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_ACL0, KC_ACL1, KC_ACL2, KC_TRNS,             KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_TRNS, KC_TRNS, KC_BTN1, KC_MS_U, KC_BTN3, KC_TRNS,             KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,             KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN2, KC_TRNS, KC_TRNS, KC_NO,         KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                                KC_NO, KC_NO, KC_NO,     KC_NO, KC_NO, KC_NO
    ),
    [_EMOJI] = LAYOUT(
        X(HART2), X(CRY2), X(WEARY), X(EYERT), X(SMIRK), X(TJOY),             X(RECYC), X(UNAMU), X(MUSIC), X(OKHND), X(PENSV), X(PHEW),
        X(THMUP), X(PRAY), X(SMILE), X(SMIL2), X(FLUSH), X(GRIN),             X(HEART), X(BYE), X(KISS), X(CELEB), X(COOL), X(NOEVS),
        X(THMDN), X(SLEEP), X(CLAP), X(CRY), X(VIC), X(BHART),             X(SUN), X(SMEYE), X(WINK), X(MOON), X(CONFU), X(NOEVH),
        X(POO), X(EYES), X(HUNRD), _______, X(SKULL), X(HORNS), X(HALO),         X(FEAR), _______, X(YUMMY), X(DISAP), X(NOEVK), _______, _______,
                                _______, _______, _______,     _______, _______, _______
    ),
};

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//   switch (keycode) {
//     case QWERTY:
//       if (record->event.pressed) {
//         set_single_persistent_default_layer(_QWERTY);
//       }
//       return false;
//       break;
//     case LOWER:
//       if (record->event.pressed) {
//         layer_on(_LOWER);
//         update_tri_layer(_LOWER, _RAISE, _POWER);
//       } else {
//         layer_off(_LOWER);
//         update_tri_layer(_LOWER, _RAISE, _POWER);
//       }
//       return false;
//       break;
//     case RAISE:
//       if (record->event.pressed) {
//         layer_on(_RAISE);
//         update_tri_layer(_LOWER, _RAISE, _POWER);
//       } else {
//         layer_off(_RAISE);
//         update_tri_layer(_LOWER, _RAISE, _POWER);
//       }
//       return false;
//       break;
//     case POWER:
//       if (record->event.pressed) {
//         layer_on(_POWER);
//       } else {
//         layer_off(_POWER);
//       }
//       return false;
//       break;
//   }
//   return true;
// }

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ALT_TAB:
      if (record->event.pressed) {
        if (!is_alt_tab_active) {
          is_alt_tab_active = true;
          register_code(KC_LALT);
        }
        alt_tab_timer = timer_read();
        register_code(KC_TAB);
      } else {
        unregister_code(KC_TAB);
      }
      break;
  }
  return true;
}

// layer_state_t layer_state_set_user(layer_state_t state) {
//     state = update_tri_layer_state(state, _LOWER, _RAISE, _POWER);
//     switch (get_highest_layer(state)) {
//         case _LOWER:
//             rgblight_sethsv_noeeprom(HSV_GREEN);
//             break;
//         case _RAISE:
//             rgblight_sethsv_noeeprom(HSV_AZURE);
//             break;
//         case _POWER:
//             rgblight_sethsv_noeeprom(HSV_RED);
//             break;
//         case _GAME:
//             rgblight_sethsv_noeeprom(HSV_CYAN);
//             break;
//         case _MOUSE:
//             rgblight_sethsv_noeeprom(HSV_YELLOW);
//             break;
//         case _EMOJI:
//             rgblight_sethsv_noeeprom(HSV_ORANGE);
//             break;
//         default: //  for any other layers, or the default layer
//             rgblight_sethsv_noeeprom(HSV_PURPLE);
//             break;
//     }
//     return state;
// }

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _LOWER, _RAISE, _POWER);
    switch (get_highest_layer(state)) {
        case _LOWER:
            rgblight_sethsv_at(HSV_GREEN);
            break;
        case _RAISE:
            rgblight_sethsv_noeeprom(HSV_AZURE);
            break;
        case _POWER:
            rgblight_sethsv_noeeprom(HSV_RED);
            break;
        case _GAME:
            rgblight_sethsv_noeeprom(HSV_CYAN);
            break;
        case _MOUSE:
            rgblight_sethsv_noeeprom(HSV_YELLOW);
            break;
        case _EMOJI:
            rgblight_sethsv_noeeprom(HSV_ORANGE);
            break;
        default: //  for any other layers, or the default layer
            rgblight_sethsv_noeeprom(HSV_PURPLE);
            break;
    }
    return state;
}

void encoder_update_user(uint8_t index, bool clockwise) {
    switch(biton32(layer_state)) {
        case _LOWER:
            if (!clockwise) {
                tap_code(KC_VOLU);
            } else {
                tap_code(KC_VOLD);
            }
            break;
        case _RAISE:
            if (!clockwise) {
                register_code(KC_LCTL);
                tap_code(KC_TAB);
                unregister_code(KC_LCTL);
            } else {
                register_code(KC_LSFT);
                register_code(KC_LCTL);
                tap_code(KC_TAB);
                unregister_code(KC_LSFT);
                unregister_code(KC_LCTL);
            }
            break;
        default:
            if (!clockwise) {
                tap_code(KC_WH_D);
            } else {
                tap_code(KC_WH_U);
            }
            break;
    }
}

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  debug_matrix=true;
  debug_keyboard=true;
  //debug_mouse=true;
  rgblight_sethsv_noeeprom(HSV_PURPLE);
  set_unicode_input_mode(UC_WINC);
}

void matrix_scan_user(void) {
  if (is_alt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > 1000) {
      unregister_code(KC_LALT);
      is_alt_tab_active = false;
    }
  }
}

/* Return an integer that corresponds to what kind of tap dance should be executed.
 *
 * How to figure out tap dance state: interrupted and pressed.
 *
 * Interrupted: If the state of a dance dance is "interrupted", that means that another key has been hit
 *  under the tapping term. This is typically indicitive that you are trying to "tap" the key.
 *
 * Pressed: Whether or not the key is still being pressed. If this value is true, that means the tapping term
 *  has ended, but the key is still being pressed down. This generally means the key is being "held".
 *
 * One thing that is currenlty not possible with qmk software in regards to tap dance is to mimic the "permissive hold"
 *  feature. In general, advanced tap dances do not work well if they are used with commonly typed letters.
 *  For example "A". Tap dances are best used on non-letter keys that are not hit while typing letters.
 *
 * Good places to put an advanced tap dance:
 *  z,q,x,j,k,v,b, any function key, home/end, comma, semi-colon
 *
 * Criteria for "good placement" of a tap dance key:
 *  Not a key that is hit frequently in a sentence
 *  Not a key that is used frequently to double tap, for example 'tab' is often double tapped in a terminal, or
 *    in a web form. So 'tab' would be a poor choice for a tap dance.
 *  Letters used in common words as a double. For example 'p' in 'pepper'. If a tap dance function existed on the
 *    letter 'p', the word 'pepper' would be quite frustating to type.
 *
 * For the third point, there does exist the 'DOUBLE_SINGLE_TAP', however this is not fully tested
 *
 */
int cur_dance (qk_tap_dance_state_t *state) {
  if (state->count == 1) {
    if (state->interrupted || !state->pressed)  return SINGLE_TAP;
    //key has not been interrupted, but they key is still held. Means you want to send a 'HOLD'.
    else return SINGLE_HOLD;
  }
  else if (state->count == 2) {
    /*
     * DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
     * action when hitting 'pp'. Suggested use case for this return value is when you want to send two
     * keystrokes of the key, and not the 'double tap' action/macro.
    */
    if (state->interrupted) return DOUBLE_SINGLE_TAP;
    else if (state->pressed) return DOUBLE_HOLD;
    else return DOUBLE_TAP;
  }
  //Assumes no one is trying to type the same letter three times (at least not quickly).
  //If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
  //an exception here to return a 'TRIPLE_SINGLE_TAP', and define that enum just like 'DOUBLE_SINGLE_TAP'
  if (state->count == 3) {
    if (state->interrupted || !state->pressed)  return TRIPLE_TAP;
    else return TRIPLE_HOLD;
  }
  else return 8; //magic number. At some point this method will expand to work for more presses
}

//instanalize an instance of 'tap' for the 'x' tap dance.
static tap xtap_state = {
  .is_press_action = true,
  .state = 0
};

void x_LSFT_finished (qk_tap_dance_state_t *state, void *user_data) {
  xtap_state.state = cur_dance(state);
  switch (xtap_state.state) {
    case SINGLE_TAP: register_code(KC_LPRN); break;
    case SINGLE_HOLD: register_code(KC_LSFT); break;
    case DOUBLE_TAP: register_code(KC_LBRC); break;
    case DOUBLE_HOLD: break;
    //Last case is for fast typing. Assuming your key is `f`:
    //For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
    //In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
  }
}

void x_LSFT_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (xtap_state.state) {
    case SINGLE_TAP: unregister_code(KC_LPRN); break;
    case SINGLE_HOLD: unregister_code(KC_LSFT); break;
    case DOUBLE_TAP: unregister_code(KC_LBRC); break;
    case DOUBLE_HOLD: break;
  }
  xtap_state.state = 0;
}

void x_RSFT_finished (qk_tap_dance_state_t *state, void *user_data) {
  xtap_state.state = cur_dance(state);
  switch (xtap_state.state) {
    case SINGLE_TAP: register_code(KC_RPRN); break;
    case SINGLE_HOLD: register_code(KC_RSFT); break;
    case DOUBLE_TAP: register_code(KC_RBRC); break;
    case DOUBLE_HOLD: break;
    //Last case is for fast typing. Assuming your key is `f`:
    //For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
    //In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
  }
}

void x_RSFT_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (xtap_state.state) {
    case SINGLE_TAP: unregister_code(KC_RPRN); break;
    case SINGLE_HOLD: unregister_code(KC_RSFT); break;
    case DOUBLE_TAP: unregister_code(KC_RBRC); break;
    case DOUBLE_HOLD: break;
  }
  xtap_state.state = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
  [X_LSFT]     = ACTION_TAP_DANCE_FN_ADVANCED(NULL,x_LSFT_finished, x_LSFT_reset)
  [X_RSFT]     = ACTION_TAP_DANCE_FN_ADVANCED(NULL,x_RSFT_finished, x_RSFT_reset)
};

// TODO
// emoji layer for linux
// lower and raise on far thumb keys?
// tap dance ;; to :?
// Dynamic macro buttons would be interesting for repetitive actions
// modifier (super?) on tab
// https://github.com/qmk/qmk_firmware/blob/master/keyboards/handwired/promethium/keymaps/priyadi/keymap.c
//// the X codes are particularly interesting


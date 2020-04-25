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
  X_LSFT,
  X_RSFT
};

int cur_dance (qk_tap_dance_state_t *state);

//for the x tap dance. Put it here so it can be used in any keymap
void x_LSFT_finished (qk_tap_dance_state_t *state, void *user_data);
void x_LSFT_reset (qk_tap_dance_state_t *state, void *user_data);
void x_RSFT_finished (qk_tap_dance_state_t *state, void *user_data);
void x_RSFT_reset (qk_tap_dance_state_t *state, void *user_data);


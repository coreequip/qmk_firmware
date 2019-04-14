#include QMK_KEYBOARD_H

enum my_keycodes {
  FN_RIGHT = SAFE_RANGE,
  FN_CAPSLCK
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_all(KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_BSPC,
                   KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS,
                   FN_CAPSLCK, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, KC_ENT,
                   KC_LSFT, KC_NO, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_UP, KC_UP, KC_RALT,
                   KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_DEL, FN_RIGHT, KC_LEFT, KC_DOWN, KC_RGHT)
};

// Loop
void matrix_scan_user(void) {
  // Empty
};

bool is_fn_active = false;
bool is_shift_active = false;

void setFnStatus(bool fnStatus) {
  is_fn_active = fnStatus;
};

void setShiftStatus(bool shiftStatus) {
  is_shift_active = shiftStatus;
};

bool processUmlaut(uint16_t keycode, keyrecord_t *record) {
  if (is_fn_active && record->event.pressed) {
    if(keycode == KC_O) {
      if(is_shift_active){
        unregister_code(KC_LSFT);
        SEND_STRING(SS_LALT(SS_TAP(X_KP_1)SS_TAP(X_KP_5)SS_TAP(X_KP_3))); //Uppercase OE
        register_code(KC_LSFT);
        return false;
      } else {
        SEND_STRING(SS_LALT(SS_TAP(X_KP_1)SS_TAP(X_KP_4)SS_TAP(X_KP_8))); //Lowercase OE
        return false;
      }
    } else if(keycode == KC_A) {
      if(is_shift_active){
        unregister_code(KC_LSFT);
        SEND_STRING(SS_LALT(SS_TAP(X_KP_1)SS_TAP(X_KP_4)SS_TAP(X_KP_2))); //Uppercase AE
        register_code(KC_LSFT);
        return false;
      } else {
        SEND_STRING(SS_LALT(SS_TAP(X_KP_1)SS_TAP(X_KP_3)SS_TAP(X_KP_2))); //Lowercase AE
        return false;
      }
    } else if(keycode == KC_U) {
      if(is_shift_active){
        unregister_code(KC_LSFT);
        SEND_STRING(SS_LALT(SS_TAP(X_KP_1)SS_TAP(X_KP_5)SS_TAP(X_KP_4))); //Uppercase UE
        register_code(KC_LSFT);
        return false;
      } else {
        SEND_STRING(SS_LALT(SS_TAP(X_KP_1)SS_TAP(X_KP_2)SS_TAP(X_KP_9))); //Lowercase UE
        return false;
      }
    } else if(keycode == KC_S) {
        SEND_STRING(SS_LALT(SS_TAP(X_KP_2)SS_TAP(X_KP_2)SS_TAP(X_KP_5))); //Scharfes S
        return false;
    }
  }
  return true;
}

bool processArrowFN(uint16_t keycode, keyrecord_t *record) {
  if (!is_fn_active || !record->event.pressed) {
    return true;
  }
  if (keycode == KC_LEFT) {
    SEND_STRING(SS_TAP(X_HOME));
    return false;
  } else if (keycode == KC_RGHT) {
    SEND_STRING(SS_TAP(X_END));
    return false;
  } else if (keycode == KC_UP) {
    SEND_STRING(SS_TAP(X_PGUP));
    return false;
  } else if (keycode == KC_DOWN) {
    SEND_STRING(SS_TAP(X_PGDOWN));
    return false;
  }
  return true;
}

bool processFunctionKeys(uint16_t keycode, keyrecord_t *record) {
  if (!is_fn_active || !record->event.pressed) {
    return true;
  }
  if (keycode == KC_1) {
    SEND_STRING(SS_TAP(X_F1));
    return false;
  } else if (keycode == KC_2) {
    SEND_STRING(SS_TAP(X_F2));
    return false;
  } else if (keycode == KC_3) {
    SEND_STRING(SS_TAP(X_F3));
    return false;
  } else if (keycode == KC_4) {
    SEND_STRING(SS_TAP(X_F4));
    return false;
  } else if (keycode == KC_5) {
    SEND_STRING(SS_TAP(X_F5));
    return false;
  } else if (keycode == KC_6) {
    SEND_STRING(SS_TAP(X_F6));
    return false;
  } else if (keycode == KC_7) {
    SEND_STRING(SS_TAP(X_F7));
    return false;
  } else if (keycode == KC_8) {
    SEND_STRING(SS_TAP(X_F8));
    return false;
  } else if (keycode == KC_9) {
    SEND_STRING(SS_TAP(X_F9));
    return false;
  } else if (keycode == KC_0) {
    SEND_STRING(SS_TAP(X_F10));
    return false;
  } else if (keycode == KC_MINS) {
    SEND_STRING(SS_TAP(X_F11));
    return false;
  } else if (keycode == KC_EQL) {
    SEND_STRING(SS_TAP(X_F12));
    return false;
  }
  return true;
}

bool processInsert(uint16_t keycode, keyrecord_t *record) {
  if (!is_fn_active || !record->event.pressed) {
    return true;
  }
  if (keycode == KC_DEL) {
    SEND_STRING(SS_TAP(X_INSERT));
    return false;
  }
  return true;
}

bool processRightCtrl(uint16_t keycode, keyrecord_t *record) {
  if (!is_fn_active || !record->event.pressed) {
    return true;
  }
  if (keycode == KC_LCTL) {
    SEND_STRING(SS_TAP(X_RCTRL));
    return false;
  }
  return true;
}

bool processGrvTilde(uint16_t keycode, keyrecord_t *record) {
  if (!is_fn_active || !record->event.pressed) {
    return true;
  }
  if (keycode == KC_ESC) {
    SEND_STRING(SS_TAP(X_GRAVE));
    return false;
  }
  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case FN_RIGHT:
      if (record->event.pressed) {
        setFnStatus(true);
      } else {
        setFnStatus(false);
      }
      return false; // Skip all further processing of this key
    case FN_CAPSLCK:
      if (record->event.pressed) {
        setFnStatus(true);
      } else {
        setFnStatus(false);
      }
      return false; // Skip all further processing of this key
    case KC_LSFT:
      if (record->event.pressed) {
        setShiftStatus(true);
      } else {
        setShiftStatus(false);
      }
      return true;
    default:
      if(!processUmlaut(keycode, record)){
        return false;
      }
      if(!processInsert(keycode, record)){
        return false;
      }
      if(!processFunctionKeys(keycode, record)){
        return false;
      }
      if(!processRightCtrl(keycode, record)){
        return false;
      }
      if(!processGrvTilde(keycode, record)){
        return false;
      }
      return processArrowFN(keycode, record);
  }
}

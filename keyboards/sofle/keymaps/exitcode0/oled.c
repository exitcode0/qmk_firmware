#ifdef OLED_ENABLE
    static void print_status_narrow(void) {
        oled_write_ln_P(PSTR("LAYER"), false);  // Print current layer
        switch (get_highest_layer(layer_state)) {
            case _QWERTY:
                oled_write_ln_P(PSTR("Base"), false);
                break;
            case _RAISE:
                oled_write_ln_P(PSTR("Raise"), false);
                break;
            case _LOWER:
                oled_write_ln_P(PSTR("Lower"), false);
                break;
            case _ADJUST:
                oled_write_ln_P(PSTR("Adj"), false);
                break;
            // case _NUMPAD:
            //     oled_write_ln_P(PSTR("Nump"), false);
            //     break;
            // case _SWITCH:
            //     oled_write_ln_P(PSTR("Swit"), false);
            //     break;
            default:
                oled_write_ln_P(PSTR("Undef"), false);
        }
    }
    oled_rotation_t oled_init_user(oled_rotation_t rotation) {
        if (is_keyboard_master()) {
            return OLED_ROTATION_270;
        } else {
            return OLED_ROTATION_270;
        }
        return rotation;
    }
    bool oled_task_user(void) {
        if (is_keyboard_master()) {
            print_status_narrow();
        } else {
            // render_logo();
            print_status_narrow();
        }
        return false;
    }
#endif

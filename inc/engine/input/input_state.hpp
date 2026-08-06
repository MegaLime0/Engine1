#pragma once

namespace Engine {
namespace Input {

struct InputState {
    // used for getting enum element count
    bool FIRST;

    // Keyboard Keys
    bool KB_Q;
    bool KB_W;
    bool KB_E;
    bool KB_R;
    bool KB_T;
    bool KB_Y;
    bool KB_U;
    bool KB_I;
    bool KB_O;
    bool KB_P;
    bool KB_A;
    bool KB_S;
    bool KB_D;
    bool KB_F;
    bool KB_G;
    bool KB_H;
    bool KB_J;
    bool KB_K;
    bool KB_L;
    bool KB_Z;
    bool KB_X;
    bool KB_C;
    bool KB_V;
    bool KB_B;
    bool KB_N;
    bool KB_M;
    bool KB_0;
    bool KB_1;
    bool KB_2;
    bool KB_3;
    bool KB_4;
    bool KB_5;
    bool KB_6;
    bool KB_7;
    bool KB_8;
    bool KB_9;
    bool KB_MINUS;
    bool KB_PLUS;
    bool KB_UP;
    bool KB_DOWN;
    bool KB_LEFT;
    bool KB_RIGHT;
    bool KB_SHIFT;
    bool KB_SPACE;
    bool KB_ENTER;
    bool KB_CONTROL_LEFT;
    bool KB_CONTROL_RIGHT;
    bool KB_ALT_LEFT;
    bool KB_ALT_RIGHT;
    bool KB_BACKSPACE;
    bool KB_DELETE;
    bool KB_TAB;
    bool KB_CAPSLOCK;
    bool KB_ESCAPE;
    bool KB_F1;
    bool KB_F2;
    bool KB_F3;
    bool KB_F4;
    bool KB_F5;
    bool KB_F6;
    bool KB_F7;
    bool KB_F8;
    bool KB_F9;
    bool KB_F10;
    bool KB_F11;
    bool KB_F12;

    // Mouse Buttons
    bool MB_LEFT;
    bool MB_RIGHT;
    bool MB_MIDDLE;
    bool MB_SIDE1;
    bool MB_SIDE2;

    // Controller Buttons
    bool GP_A;
    bool GP_B;
    bool GP_X;
    bool GP_Y;
    bool GP_BUMPER_LEFT;
    bool GP_BUMPER_RIGHT;
    bool GP_HOME_PAD;
    bool GP_PAUSE;
    bool GP_DP_UP;
    bool GP_DP_DOWN;
    bool GP_DP_LEFT;
    bool GP_DP_RIGHT;
    bool GP_STICK_CLICK_LEFT;
    bool GP_STICK_CLICK_RIGHT;
    bool GP_PADDLE1;
    bool GP_PADDLE2;

    // Controller Axies 
    bool GP_STICK_LEFT_X;
    bool GP_STICK_LEFT_Y;
    bool GP_STICK_RIGHT_X;
    bool GP_STICK_RIGHT_Y;
    bool GP_TRIGGER_LEFT;
    bool GP_TRIGGER_RIGHT;

    // Edge case
    bool _INVALID;

    bool __LAST;
};


} // namespace input
} // namespace engine

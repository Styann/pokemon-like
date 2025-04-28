#ifndef SETTINGS_HPP
#define SETTINGS_HPP

#include "raylib.h"

namespace VideoSettings {
    extern unsigned int width;
    extern unsigned int height;
    extern unsigned int targetFPS;
};

namespace KeyboardInput {
    extern KeyboardKey moveUp;
    extern KeyboardKey moveRight;
    extern KeyboardKey moveDown;
    extern KeyboardKey moveLeft;
};

#endif

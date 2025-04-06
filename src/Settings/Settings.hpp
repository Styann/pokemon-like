#ifndef SETTINGS_HPP
#define SETTINGS_HPP

#include "raylib.h"

namespace VideoSettings {
    extern int width;
    extern int height;
    extern int targetFPS;
};

namespace KeyboardInput {
    extern KeyboardKey moveUp;
    extern KeyboardKey moveRight;
    extern KeyboardKey moveDown;
    extern KeyboardKey moveLeft;
}

#endif

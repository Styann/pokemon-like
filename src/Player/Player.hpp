#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "raylib.h"

#include "../SpriteSheet/SpriteSheet.hpp"

class Player {
    public: Vector2 position;
    private: SpriteSheet *spriteSheet;
    public: bool isMoving;

    public: Player(float x, float y);
    public: ~Player(void);

    public: void moveDown(void);

    public: void draw(void);
};

#endif

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "raylib.h"

#include "../SpriteSheet/SpriteSheet.hpp"

class Player {
    private: enum AnimationState {
        IDLE, TURNING, WALKING
    };

    public: enum Direction {
        UP, RIGHT, DOWN, LEFT
    };

    public: Vector2 position;
    private: SpriteSheet *spriteSheet;

    private: Player::AnimationState animationState;
    private: Player::Direction direction;

    public: Player(float x, float y);
    public: ~Player(void);

    private: unsigned int getSpriteRow();
    private: unsigned int getSpriteColumn();

    public: void turn(const Player::Direction direction);
    public: void walk(const Player::Direction direction);

    public: void update(void);

    public: void draw(void);
};

#endif

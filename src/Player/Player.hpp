#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "raylib.h"

#include "../Pokemon/Pokemon.hpp"
#include "../SpriteSheet/SpriteSheet.hpp"
#include "../Direction/Direction.hpp"
#include "../GridMap/GridMap.hpp"

class Pokemon;

class Player {
    private: enum AnimationState {
        IDLE, TURNING, WALKING
    };

    private: GridMap *gridMap;
    private: unsigned int x;
    private: unsigned int y;

    public: Vector2 position;
    private: SpriteSheet *spriteSheet;

    private: Player::AnimationState animationState;
    private: Direction direction;

    public: Player(GridMap *const gridMap, unsigned int x, unsigned int y);
    public: ~Player(void);

    private: unsigned int getSpriteRow();
    private: unsigned int getSpriteColumn();

    private: bool isColliding(const Direction direction);

    public: void turn(const Direction direction);

    private: void updateGridPosition(void);

    public: void walk(const Direction direction);

    public: void update(Pokemon *pokemon);

    public: void draw(void);
};

#endif

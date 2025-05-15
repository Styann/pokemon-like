#ifndef MOVABLE_HPP
#define MOVABLE_HPP

#include "raylib.h"

#include "../GridMap/GridMapObject/GridMapObject.hpp"
#include "../GridMap/GridMapVector/GridMapVector.hpp"
#include "../Direction/Direction.hpp"
#include "../SpriteSheet/SpriteSheet.hpp"

class Movable : public GridMapObject {
    protected: enum AnimationState {
        IDLE, TURNING, WALKING
    };

    protected: Direction direction;
    protected: Movable::AnimationState animationState;

    private: SpriteSheet *spriteSheet;

    public: Movable(const char *spriteSheetPath, GridMap *gridMap, GridMapVector gridMapPosition, Direction direction);
    public: ~Movable(void);

    private: unsigned int getSpriteRow();
    private: unsigned int getSpriteColumn();

    private: bool isColliding(const Direction direction);

    private: Vector2 gridPositionToPosition(void);

    public: void turn(const Direction direction);

    public: void walk(const Direction direction);

    public: void update(void);

    public: void draw(void);
};

#endif

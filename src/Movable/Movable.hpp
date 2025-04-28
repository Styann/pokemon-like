#ifndef MOVABLE_HPP
#define MOVABLE_HPP

#include "raylib.h"

#include "../Direction/Direction.hpp"
#include "../GridMap/GridMap.hpp"

class Movable {
    private: static GridMap &gridMap;

    private: struct { int x; int y; } gridMapPosition;
    private: Vector2 position;
    private: Direction direction;
};

#endif

#ifndef GRID_MAP_OBJECT_HPP
#define GRID_MAP_OBJECT_HPP

#include "raylib.h"

#include "../GridMap.hpp"
#include "../GridMapVector/GridMapVector.hpp"

class GridMap;

class GridMapObject {
    protected: GridMap *gridMap;
    public: GridMapVector gridMapPosition;
    public: Vector2 position;
};

#endif

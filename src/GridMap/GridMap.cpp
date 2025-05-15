#include "GridMap.hpp"
#include <iostream>

GridMap::GridMap(void) {
    this->grid = std::vector<std::vector<GridMapObject *>>(15, std::vector<GridMapObject *>(15, nullptr));
}

unsigned int GridMap::width(void) {
    return this->grid.size();
}

unsigned int GridMap::height(void) {
    return this->grid[0].size();
}

void GridMap::initObjectPosition(GridMapObject &object) {
    if (this->grid[object.gridMapPosition.y][object.gridMapPosition.x]) {
        throw "GridMap::initObjectPosition -> cell is already busy.";
    }
    else {
        this->grid[object.gridMapPosition.y][object.gridMapPosition.x] = &object;
    }
}

void GridMap::updateObjectPosition(GridMapObject &object, Direction direction) {
    GridMapVector targetPosition = object.gridMapPosition;

    switch (direction) {
        case Direction::UP:
            if (targetPosition.y > 0) targetPosition.y--;
            break;
        case Direction::RIGHT:
            if (targetPosition.x < this->width()) targetPosition.x++;
            break;
        case Direction::DOWN:
            if (targetPosition.y < this->height()) targetPosition.y++;
            break;
        case Direction::LEFT:
            if (targetPosition.x > 0) targetPosition.x--;
            break;
    }

    if (!this->grid[targetPosition.y][targetPosition.x]) {
        this->grid[object.gridMapPosition.y][object.gridMapPosition.x] = nullptr;
        this->grid[targetPosition.y][targetPosition.x] = &object;
        object.gridMapPosition = targetPosition;
    }
}

bool GridMap::isColliding(GridMapVector &position, Direction direction) {
    GridMapVector positionCopy = position;

    switch (direction) {
        case Direction::UP:
            if (positionCopy.y > 0) positionCopy.y--;
            break;
        case Direction::RIGHT:
            if (positionCopy.x < this->width()) positionCopy.x++;
            break;
        case Direction::DOWN:
            if (positionCopy.y < this->height()) positionCopy.y++;
            break;
        case Direction::LEFT:
            if (positionCopy.x > 0) positionCopy.x--;
            break;
    }

    return this->grid[positionCopy.y][positionCopy.x];
}

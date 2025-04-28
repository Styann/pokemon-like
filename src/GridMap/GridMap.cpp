#include "GridMap.hpp"
#include <iostream>

GridMap::GridMap(void) {

}

bool GridMap::isColliding(unsigned int x, unsigned int y, Direction direction) {
    unsigned int yy = y;
    unsigned int xx = x;

    switch (direction) {
        case Direction::UP:
            if (yy > 0) {
                yy--;
            }
            else {
                return true;
            }
            break;
        case Direction::RIGHT:
            if (xx < 4) {
                xx++;
            }
            else {
                return true;
            }
            break;
        case Direction::DOWN:
            if (yy < 4) {
                yy++;
            }
            else {
                return true;
            }
            break;
        case Direction::LEFT:
            if (xx > 0) {
                xx--;
            }
            else {
                return true;
            }
    }

    return this->map[yy][xx];
}

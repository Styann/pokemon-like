#ifndef GRIDMAP_HPP
#define GRIDMAP_HPP

#include "../Direction/Direction.hpp"

class GridMap {
    private: bool map[5][5] = {
        { 1, 1, 1, 1, 1 },
        { 1, 0, 0, 0, 1 },
        { 1, 0, 0, 0, 1 },
        { 1, 0, 0, 0, 1 },
        { 1, 1, 1, 1, 1 }
    };

    public: GridMap(void);

    public: bool isColliding(unsigned int x, unsigned int y, Direction direction);
};

#endif

#ifndef GRIDMAP_HPP
#define GRIDMAP_HPP

#include <vector>
#include "../Direction/Direction.hpp"
#include "../GridMap/GridMapVector/GridMapVector.hpp"
#include "../GridMap/GridMapObject/GridMapObject.hpp"

class GridMap {
    public: std::vector<std::vector<GridMapObject *>> grid;

    public: GridMap(void);

    private: unsigned int width(void);
    private: unsigned int height(void);

    public: void initObjectPosition(GridMapObject &object);
    public: void updateObjectPosition(GridMapObject &object, Direction direction);

    public: bool isColliding(GridMapVector &position, Direction direction);
};

#endif

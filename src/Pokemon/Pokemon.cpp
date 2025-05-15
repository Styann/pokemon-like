#include "Pokemon.hpp"

#include <iostream>

#include "../Settings/Settings.hpp"
#include "../Env/Env.hpp"

// Pokemon::Pokemon(const char *spriteSheetPath, GridMap *gridMap, GridMapVector gridMapPosition, Direction direction) : Movable(spriteSheetPath, gridMap, gridMapPosition, direction) {
// }

// bool Pokemon::isFacingPlayer(const Player *const player) {
    // if (this->position.x == player->position.x) {
    //     if (this->position.y < player->position.y) { // pokemon is up to player
    //         return (player->direction == Direction::UP);
    //     }
    //     else if (this->position.y > player->position.y) { // pokemon is down to player
    //         return (player->direction == Direction::DOWN);
    //     }

    //     return false;
    // }
    // else if (this->position.y == player->position.y) {
    //     if (this->position.x < player->position.x) { // pokemon is left to player
    //         return (player->direction == Direction::LEFT);
    //     }
    //     else if (this->position.x < player->position.x) { // pokemon is right to player
    //         return (this->direction == Direction::RIGHT);
    //     }

    //     return false;
    // }

//     return false;
// }

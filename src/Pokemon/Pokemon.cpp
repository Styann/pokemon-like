#include "Pokemon.hpp"

#include <iostream>

#include "../Settings/Settings.hpp"
#include "../Env/Env.hpp"

Pokemon::Pokemon(void) {
    this->spriteSheet = new SpriteSheet((Env::resourcesPath / "pikachu.png").c_str(), 4, 4);
    this->position = (Vector2){ VideoSettings::width / 2.0f - 32.0f, VideoSettings::height / 2.0f };
    // this->direction = Direction::RIGHT;
}

Pokemon::~Pokemon(void) {
    delete this->spriteSheet;
}

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

// void Pokemon::followPlayer(const Player *const player) {

// }

void Pokemon::draw(void) {
    this->spriteSheet->drawSprite(&this->position);
}

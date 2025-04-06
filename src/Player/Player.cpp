#include "Player.hpp"

#include <string>
#include <filesystem>

#include "../Settings/Settings.hpp"

Player::Player(float x, float y) {
    this->position = (Vector2){ x, y };

    // std::string filepath = std::filesystem::current_path();
    this->spriteSheet = new SpriteSheet("./resources/brendan.png", 4, 4);
    this->isMoving = false;
}

Player::~Player(void) {
    delete this->spriteSheet;
}

void Player::moveDown(void) {
    this->spriteSheet->incrementCurrentColumn();
}

void Player::draw(void) {
    this->spriteSheet->drawSprite(&this->position);
}

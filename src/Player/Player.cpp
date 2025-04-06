#include "Player.hpp"

// #include <string>
// #include <filesystem>

#include "../Settings/Settings.hpp"

Player::Player(float x, float y) {
    this->position = (Vector2){ x, y };

    // std::string filepath = std::filesystem::current_path();
    this->spriteSheet = new SpriteSheet("/home/boudiou/Workspace/pokemon-like/resources/brendan.png", 4, 4);
    this->animationState = Player::AnimationState::IDLE;
}

Player::~Player(void) {
    delete this->spriteSheet;
}

unsigned int Player::getSpriteRow(void) {
    switch (this->direction) {
        case Player::Direction::UP:    return 3;
        case Player::Direction::RIGHT: return 2;
        case Player::Direction::DOWN:  return 0;
        case Player::Direction::LEFT:  return 1;
        default: return 3;
    }
}

unsigned int Player::getSpriteColumn(void) {
    return 0;
}

void Player::turn(const Player::Direction direction) {
    this->animationState = Player::AnimationState::TURNING;
    this->direction = direction;
}

void Player::walk(const Player::Direction direction) {
    this->animationState = Player::AnimationState::WALKING;
    this->direction = direction;
}

void Player::update(void) {
    switch (this->animationState) {
        case Player::AnimationState::TURNING:
            this->spriteSheet->selectSprite(0, this->getSpriteRow());
            this->animationState = Player::AnimationState::IDLE;
            break;
        case Player::AnimationState::WALKING:
            this->spriteSheet->selectRow(this->getSpriteRow());

            if ((this->spriteSheet->incrementCurrentColumn() % 2) == 0) {
                this->animationState = Player::AnimationState::IDLE;
            }

            switch (this->direction) {
                case Player::Direction::UP:
                    this->position.y -= 16.0f;
                    break;
                case Player::Direction::RIGHT:
                    this->position.x += 16.0f;
                    break;
                case Player::Direction::DOWN:
                    this->position.y += 16.0f;
                    break;
                case Player::Direction::LEFT:
                    this->position.x -= 16.0f;
                    break;
            }

            break;
    }
}

void Player::draw(void) {
    this->spriteSheet->drawSprite(&this->position);
}

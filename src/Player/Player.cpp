#include "Player.hpp"

#include "../Env/Env.hpp"
#include "../Settings/Settings.hpp"
#include "../Settings/Settings.hpp"

Player::Player(GridMap *const gridMap, unsigned int x, unsigned int y) {
    this->position = (Vector2){ VideoSettings::width / 2.0f, VideoSettings::height / 2.0f };

    // std::string filepath = std::filesystem::current_path();
    this->spriteSheet = new SpriteSheet((Env::resourcesPath / "brendan.png").c_str(), 4, 4);
    this->animationState = Player::AnimationState::IDLE;
    this->direction = Direction::DOWN;

    this->gridMap = gridMap;
    this->x = x;
    this->y = y;
}

Player::~Player(void) {
    delete this->spriteSheet;
}

unsigned int Player::getSpriteRow(void) {
    switch (this->direction) {
        case Direction::UP:    return 3;
        case Direction::RIGHT: return 2;
        case Direction::DOWN:  return 0;
        case Direction::LEFT:  return 1;
        default: return 3;
    }
}

unsigned int Player::getSpriteColumn(void) {
    return 0;
}

bool Player::isColliding(const Direction direction) {
    return this->gridMap->isColliding(this->x, this->y, direction);
}

void Player::turn(const Direction direction) {
    if (this->animationState == Player::AnimationState::IDLE) {
        this->animationState = Player::AnimationState::TURNING;
        this->direction = direction;
    }
}

void Player::walk(const Direction direction) {
    if (this->animationState == Player::AnimationState::IDLE) {
        if (!this->isColliding(direction)) {
            this->animationState = Player::AnimationState::WALKING;
            this->direction = direction;
        }
        else /* if (this->direction != direction) */ {
            this->animationState = Player::AnimationState::TURNING;
            this->direction = direction;
        }
    }
}

void Player::updateGridPosition(void) {
    switch (this->direction) {
        case Direction::UP:
            if (this->y > 0) this->y--;
            break;
        case Direction::RIGHT:
            if (this->x < 4) this->x++;
            break;
        case Direction::DOWN:
            if (this->x < 4) this->y++;
            break;
        case Direction::LEFT:
            if (this->x > 0) this->x--;
    }
}

void Player::update(Pokemon *pokemon) {
    switch (this->animationState) {
        case Player::AnimationState::TURNING:
            this->spriteSheet->selectSprite(0, this->getSpriteRow());
            this->animationState = Player::AnimationState::IDLE;
            break;
        case Player::AnimationState::WALKING:
            this->spriteSheet->selectRow(this->getSpriteRow());

            switch (this->direction) {
                case Direction::UP:
                    this->position.y -= 16.0f;
                    pokemon->position.y -= 16.0f;
                    break;
                case Direction::RIGHT:
                    this->position.x += 16.0f;
                    pokemon->position.x += 16.0f;
                    break;
                case Direction::DOWN:
                    this->position.y += 16.0f;
                    pokemon->position.y += 16.0f;
                    break;
                case Direction::LEFT:
                    this->position.x -= 16.0f;
                    pokemon->position.x -= 16.0f;
                    break;
            }

            if (this->spriteSheet->incrementCurrentColumn() % 2 == 0) {
                this->animationState = Player::AnimationState::IDLE;
                this->updateGridPosition();
            }

            break;
    }
}

void Player::draw(void) {
    this->spriteSheet->drawSprite(&this->position);
}

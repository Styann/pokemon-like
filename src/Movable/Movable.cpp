#include "Movable.hpp"

#include "../Env/Env.hpp"
#include "../Settings/Settings.hpp"

Movable::Movable(const char *spriteSheetPath, GridMap *gridMap, GridMapVector gridMapPosition, Direction direction) {
    this->spriteSheet = new SpriteSheet(spriteSheetPath, 4, 4);
    this->gridMap = gridMap;
    this->gridMapPosition = gridMapPosition;
    this->position = this->gridPositionToPosition();
    this->direction = direction;
    this->animationState = Movable::AnimationState::IDLE;

    this->gridMap->initObjectPosition(*this);
}

Movable::~Movable(void) {
    delete this->spriteSheet;
}

unsigned int Movable::getSpriteRow(void) {
    switch (this->direction) {
        case Direction::UP:    return 3;
        case Direction::RIGHT: return 2;
        case Direction::DOWN:  return 0;
        case Direction::LEFT:  return 1;
        default: return 3;
    }
}

unsigned int Movable::getSpriteColumn(void) {
    return 0;
}

bool Movable::isColliding(const Direction direction) {
    return this->gridMap->isColliding(this->gridMapPosition, direction);
}

Vector2 Movable::gridPositionToPosition(void) {
    return (Vector2){ (this->gridMapPosition.x * 32.0f) + 16.0f, this->gridMapPosition.x * 32.0f };
}

void Movable::turn(const Direction direction) {
    if (this->animationState == Movable::AnimationState::IDLE) {
        this->animationState = Movable::AnimationState::TURNING;
        this->direction = direction;
    }
}

void Movable::walk(const Direction direction) {
    if (this->animationState == Movable::AnimationState::IDLE) {
        if (!this->isColliding(direction)) {
            this->animationState = Movable::AnimationState::WALKING;
            this->direction = direction;
        }
        else /* if (this->direction != direction) */ {
            this->animationState = Movable::AnimationState::TURNING;
            this->direction = direction;
        }
    }
}

void Movable::update(void) {
    switch (this->animationState) {
        case Movable::AnimationState::TURNING:
            this->spriteSheet->selectSprite(0, this->getSpriteRow());
            this->animationState = Movable::AnimationState::IDLE;
            break;
        case Movable::AnimationState::WALKING:
            this->spriteSheet->selectRow(this->getSpriteRow());

            switch (this->direction) {
                case Direction::UP:
                    this->position.y -= 16.0f;
                    break;
                case Direction::RIGHT:
                    this->position.x += 16.0f;
                    break;
                case Direction::DOWN:
                    this->position.y += 16.0f;
                    break;
                case Direction::LEFT:
                    this->position.x -= 16.0f;
                    break;
            }

            if (this->spriteSheet->incrementCurrentColumn() % 2 == 0) {
                this->animationState = Movable::AnimationState::IDLE;
                this->gridMap->updateObjectPosition(this->gridMapPosition, this->direction);
            }

            break;
    }
}

void Movable::draw(void) {
    this->spriteSheet->drawSprite(&this->position);
}

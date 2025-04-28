#include "Movable.hpp"

Movable::Movable(Vector2 position) {
    this->animationState = Movable::AnimationState::IDLE;
    this->direction = Movable::Direction::DOWN;
    this->position = position;
}

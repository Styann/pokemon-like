#ifndef POKEMON_HPP
#define POKEMON_HPP

#include "raylib.h"

#include "../SpriteSheet/SpriteSheet.hpp"
#include "../Player/Player.hpp"

class Pokemon {
    public: Vector2 position;
    public: SpriteSheet *spriteSheet;

    public: Pokemon(void);
    public: ~Pokemon(void);

    // private: bool isFacingPlayer(const Player *const player);

    // public: void followPlayer(const Player *const player);

    public: void draw(void);
};

#endif

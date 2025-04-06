#ifndef SPRITESHEET_HPP
#define SPRITESHEET_HPP

#include "raylib.h"

class SpriteSheet {
    private: Texture2D texture;

    public: unsigned int spriteWidth;
    public: unsigned int spriteHeight;

    public: unsigned int currentColumn;
    public: unsigned int currentRow;

    public: unsigned int columnLength;
    public: unsigned int rowLength;

    public: SpriteSheet(const char filename[], const unsigned int columnLength, const unsigned rowLenght);
    public: ~SpriteSheet(void);

    public: void selectColumn(const unsigned int column);
    public: void selectRow(const unsigned int row);
    public: void selectSprite(const unsigned int column, const unsigned int row);

    public: unsigned int incrementCurrentColumn(void);
    public: unsigned int incrementCurrentRow(void);

    public: void drawSprite(Vector2 *const position);
};

#endif
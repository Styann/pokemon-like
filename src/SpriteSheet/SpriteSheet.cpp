#include "SpriteSheet.hpp"

SpriteSheet::SpriteSheet(const char filename[], const unsigned int columnLength, const unsigned rowLenght) {
    this->texture = LoadTexture(filename);

    this->spriteWidth = this->texture.width / columnLength;
    this->spriteHeight = this->texture.height / rowLenght;

    this->columnLength = columnLength;
    this->rowLength = rowLenght;

    this->selectSprite(0, 0);
}

SpriteSheet::~SpriteSheet(void) {
    UnloadTexture(this->texture);
}

unsigned int SpriteSheet::incrementCurrentColumn(void) {
    this->currentColumn = (this->currentColumn + 1) % this->columnLength;
    return this->currentColumn;
}

unsigned int SpriteSheet::incrementCurrentRow(void) {
    this->currentRow = (this->currentRow + 1) % this->rowLength;
    return this->currentRow;
}

void SpriteSheet::selectColumn(const unsigned int column) {
    this->currentColumn = column;
}

void SpriteSheet::selectRow(const unsigned int row) {
    this->currentRow = row;
}

void SpriteSheet::selectSprite(const unsigned int column, const unsigned int row) {
    this->selectColumn(column);
    this->selectRow(row);
}

void SpriteSheet::drawSprite(const Vector2 *const position){
    // Source rectangle (part of the texture to use for drawing)
    Rectangle sourceRec = {
        .x = (float)this->spriteWidth * this->currentColumn,
        .y = (float)this->spriteHeight * this->currentRow,
        .width = (float)this->spriteWidth,
        .height = (float)this->spriteHeight
    };

    // Destination rectangle (screen rectangle where drawing part of texture)
    Rectangle destRec = {
        .x = position->x,
        .y = position->y,
        .width = (float)this->spriteWidth,
        .height = (float)this->spriteHeight
    };

    Vector2 origin = { (float)this->spriteWidth, (float)this->spriteHeight };

    DrawTexturePro(this->texture, sourceRec, destRec, origin, 0, WHITE);
}

#include <iostream>
#include <cstdint>

#include "raylib.h"
#include "rlgl.h"
#include "raymath.h"

#include "Player/Player.hpp"
#include "SpriteSheet/SpriteSheet.hpp"
#include "Settings/Settings.hpp"

int main(void) {
    // if (__cplusplus == 202302L) std::cout << "C++23";
    // else if (__cplusplus == 202002L) std::cout << "C++20";
    // else if (__cplusplus == 201703L) std::cout << "C++17";
    // else if (__cplusplus == 201402L) std::cout << "C++14";
    // else if (__cplusplus == 201103L) std::cout << "C++11";
    // else if (__cplusplus == 199711L) std::cout << "C++98";
    // else std::cout << "pre-standard C++." << __cplusplus;
    // std::cout << "\n";

    InitWindow(VideoSettings::width, VideoSettings::height, "Grand Theft Auto VI");
    SetTargetFPS(VideoSettings::targetFPS);

    Player *player = new Player(800, 500);
    SpriteSheet *tile = new SpriteSheet("/home/boudiou/Workspace/pokemon-like/resources/tile.png", 1, 1);

    unsigned int frameCounter = 0;
    unsigned int frameSpeed = 10; // sprite ratio : 10fps

    while (!WindowShouldClose()) {
        frameCounter++;

        if (IsKeyPressed(KeyboardInput::moveUp)) {
            player->turn(Player::Direction::UP);

        }
        else if (IsKeyDown(KeyboardInput::moveUp)) {
            player->walk(Player::Direction::UP);
        }

        if (IsKeyPressed(KeyboardInput::moveDown)) {
            player->turn(Player::Direction::DOWN);
        }
        else if (IsKeyDown(KeyboardInput::moveDown)) {
            player->walk(Player::Direction::DOWN);
        }

        if (IsKeyPressed(KeyboardInput::moveRight)) {
            player->turn(Player::Direction::RIGHT);
        }
        else if (IsKeyDown(KeyboardInput::moveRight)) {
            player->walk(Player::Direction::RIGHT);
        }

        if (IsKeyPressed(KeyboardInput::moveLeft)) {
            player->turn(Player::Direction::LEFT);
        }
        else if (IsKeyDown(KeyboardInput::moveLeft)) {
            player->walk(Player::Direction::LEFT);
        }

        if (frameCounter >= (VideoSettings::targetFPS / frameSpeed)) {
            frameCounter = 0;
            player->update();
        }

        // draw
        BeginDrawing();
            ClearBackground(RAYWHITE);
            // BeginMode2D(camera);

            Vector2 tilePosition = (Vector2){ 700, 400 };

            for (int i = 0; i < 10; i++) {
                tile->drawSprite(&tilePosition);
                tilePosition.x += tile->spriteWidth;
            }



            // for (int i = 0; i < 10; i++) {
            //     tilePosition.x += tile->spriteWidth;
            // }

            player->draw();

            // EndMode2D();
        EndDrawing();
    }

    // delete player to unload texture before CloseWindow()
    delete player;
    delete tile;

    CloseWindow();

    return 0;
}

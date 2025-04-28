#include <iostream>
#include <cstdint>
#include <filesystem>
#include <cstring>

#include "raylib.h"
#include "rlgl.h"
#include "raymath.h"

#include "Direction/Direction.hpp"
#include "Env/Env.hpp"
#include "Player/Player.hpp"
#include "Pokemon/Pokemon.hpp"
#include "SpriteSheet/SpriteSheet.hpp"
#include "Settings/Settings.hpp"
#include "GridMap/GridMap.hpp"

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

    GridMap *gridMap = new GridMap();
    Player *player = new Player(gridMap, 2, 2);
    Pokemon *pikachu = new Pokemon();
    SpriteSheet *tile = new SpriteSheet((Env::resourcesPath / "tile.png").c_str(), 1, 1);
    SpriteSheet *redtile = new SpriteSheet((Env::resourcesPath / "redtile.png").c_str(), 1, 1);

    unsigned int frameCounter = 0;
    unsigned int frameSpeed = 15; // sprite ratio : 15fps

    Camera2D camera = { 0 };
    camera.target = player->position;
    camera.offset = (Vector2){ VideoSettings::width / 2.0f, VideoSettings::height / 2.0f };
    camera.rotation = 0;
    camera.zoom = 1.0f;

    while (!WindowShouldClose()) {
        frameCounter++;

        // if (IsKeyPressed(KeyboardInput::moveUp)) {
        //     player->turn(Direction::UP);
        // }
        if (IsKeyDown(KeyboardInput::moveUp)) {
            player->walk(Direction::UP);
        }

        // if (IsKeyPressed(KeyboardInput::moveDown)) {
        //     player->turn(Direction::DOWN);
        // }
        if (IsKeyDown(KeyboardInput::moveDown)) {
            player->walk(Direction::DOWN);
        }

        // if (IsKeyPressed(KeyboardInput::moveRight)) {
        //     player->turn(Direction::RIGHT);
        // }
        if (IsKeyDown(KeyboardInput::moveRight)) {
            player->walk(Direction::RIGHT);
        }

        // if (IsKeyPressed(KeyboardInput::moveLeft)) {
        //     player->turn(Direction::LEFT);
        // }
        if (IsKeyDown(KeyboardInput::moveLeft)) {
            player->walk(Direction::LEFT);
        }

        if (frameCounter >= (VideoSettings::targetFPS / frameSpeed)) {
            frameCounter = 0;
            camera.target = player->position;
        }

        // draw
        BeginDrawing();
        BeginMode2D(camera);

        ClearBackground(RAYWHITE);
        Vector2 tilePosition = (Vector2){ 32, 32 };
        tilePosition.y = 7 * 32;

        for (int y = 0; y < 3; y++) {
            tilePosition.x = 6 * 32;

            for (int x = 0; x < 3; x++) {
                tile->drawSprite(&tilePosition);
                tilePosition.x += tile->spriteWidth;
            }

            tilePosition.y += tile->spriteHeight;
        }

        player->draw();
        pikachu->draw();
        EndMode2D();

        EndDrawing();
    }

    // delete player to unload texture before CloseWindow()
    delete player;
    delete tile;

    CloseWindow();

    return 0;
}

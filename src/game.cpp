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
#include "GridMap/GridMapVector/GridMapVector.hpp"

int main(void) {
    InitWindow(VideoSettings::width, VideoSettings::height, "Grand Theft Auto VI");
    SetTargetFPS(VideoSettings::targetFPS);

    GridMap *gridMap = new GridMap();

    Movable *player = new Movable((Env::resourcesPath / "brendan.png").c_str(), gridMap, { 7, 7 }, Direction::DOWN);
    Movable *pikachu = new Movable((Env::resourcesPath / "pikachu.png").c_str(), gridMap, { 4, 4 }, Direction::DOWN);
    SpriteSheet *tile = new SpriteSheet((Env::resourcesPath / "tile.png").c_str(), 1, 1);
    SpriteSheet *redtile = new SpriteSheet((Env::resourcesPath / "redtile.png").c_str(), 1, 1);

    unsigned int frameCounter = 0;
    unsigned int frameSpeed = 15; // sprite ratio : 15fps

    Camera2D camera = { 0 };
    camera.target = (Vector2){ player->position.x - 32, player->position.y - 16 };
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
            player->update();
            camera.target = (Vector2){ player->position.x - 32, player->position.y - 16 };
        }

        // draw
        BeginDrawing();
        BeginMode2D(camera);

        ClearBackground(RAYWHITE);

        Vector2 pos = { 0, 0 };

        for (int y = 0; y < 15; y++) {
            pos.x = 0.0f;

            for (int x = 0; x < 15; x++) {
                tile->drawSprite(&pos);
                pos.x += 32.0f;
            }

            pos.y += 32.0f;
        }

        player->draw();
        pikachu->draw();

        EndMode2D();
        EndDrawing();
    }

    // delete player to unload texture before CloseWindow()
    delete player;
    // delete pikachu;
    delete tile;

    CloseWindow();

    return 0;
}

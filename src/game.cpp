#include <iostream>
#include <cstdint>

#include "raylib.h"
#include "rlgl.h"
#include "raymath.h"

#include "Player/Player.hpp"
#include "Settings/Settings.hpp"

int main(void) {
    InitWindow(VideoSettings::width, VideoSettings::height, "Grand Theft Auto VI");
    SetTargetFPS(VideoSettings::targetFPS);

    Player *player = new Player(800, 500);

    unsigned int frameCounter = 0;
    unsigned int frameSpeed = 10; // sprite ratio : 10fps

    while (!WindowShouldClose()) {
        frameCounter++;

        bool move = false;

        if (IsKeyDown(KeyboardInput::moveDown)) {
            move = true;
        }

        if (frameCounter >= (VideoSettings::targetFPS / frameSpeed)) {
            frameCounter = 0;

            if (move) player->moveDown();
        }

        // draw
        BeginDrawing();
            ClearBackground(RAYWHITE);
            // BeginMode2D(camera);

            player->draw();

            // EndMode2D();
        EndDrawing();
    }

    // delete player to unload texture before CloseWindow()
    delete player;

    CloseWindow();

    return 0;
}

//
// Created by ozgur on 4/28/2023.
//

#include "GameManager.h"
#include "raylib.h"
#include "Player.h"

GameManager::GameManager() : windowHeight(300), windowWidth(400), gameName("Dapper Dasher 2D")
{
    fps = 60;
    gravity = 1;

    player = new Player();
}

void GameManager::CreateGameWindow() const
{
    InitWindow(windowWidth, windowHeight, gameName);
}

void GameManager::SetGameFPS() const
{
    SetTargetFPS(fps);
}

void GameManager::ApplyGravity(float& speed) const
{
    speed += gravity;
}

void GameManager::Play()
{
    CreateGameWindow();
    SetGameFPS();
    player->SetPlayerTexture();

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        if (!player->CheckIsOnGround())
        {
            ApplyGravity(player->velocity);
        }

        else
        {
            player->UpdateJumpSpeed(0);
        }

        if (IsKeyPressed(KEY_SPACE) && player->CheckIsOnGround())
        {
            player->UpdateJumpSpeed(player->GetJumpSpeed());
        }

        player->Jump();
        player->DrawPlayer();
        EndDrawing();
    }

    UnloadTexture(player->GetScarfy());
    CloseWindow();
}

GameManager::~GameManager()
{
    delete player;
}
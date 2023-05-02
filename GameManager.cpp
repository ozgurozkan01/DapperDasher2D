//
// Created by ozgur on 4/28/2023.
//

#include "GameManager.h"
#include "raylib.h"
#include "Player.h"
#include "Nebula.h"

GameManager::GameManager() : gameName("Dapper Dasher 2D")
{
    fps = 60;
    gravity = 3250;

    player = new Player();
    nebula = new Nebula();
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
    speed += (gravity * GetFrameTime());
}

void GameManager::Play()
{
    CreateGameWindow();
    SetGameFPS();

    player->SetPlayerTexture();
    nebula->SetNebulaTexture();

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

        player->CalculateRunningTime();
        nebula->CalculateRunningTime();

        if (player->CanUpdateAnimate() && player->CheckIsOnGround())
        {
            player->AnimateScarfy();
        }

        if (nebula->CanUpdateAnimate())
        {
            nebula->AnimateNebula();
        }

        player->Jump();
        nebula->Move();

        player->DrawPlayer();
        nebula->DrawNebula();
        EndDrawing();

    }

    UnloadTexture(player->GetScarfy());
    UnloadTexture(nebula->GetNebula());
    CloseWindow();
}

GameManager::~GameManager()
{
    delete player;
}
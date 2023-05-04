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

    player = new Player(1.f / 12.f);
    nebula = new Nebula(1.f / 12.f);
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

    player->LoadActorTexture("textures/scarfy.png");
    player->SetPlayerTexturePosition(6);

    nebula->LoadActorTexture("textures/12_nebula_spritesheet.png");
    nebula->SetMebulaTexturePosition(8);

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
            player->AnimateActor(6);
        }

        if (nebula->CanUpdateAnimate())
        {
            nebula->AnimateActor(8);
        }

        player->Jump();
        nebula->Move();

        player->DrawActor();
        nebula->DrawActor();
        EndDrawing();

    }

    UnloadTexture(player->GetActor());
    UnloadTexture(nebula->GetActor());
    CloseWindow();
}

GameManager::~GameManager()
{
    delete player;
}
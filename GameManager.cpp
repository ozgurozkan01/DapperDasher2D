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

    for (int i = 0; i < nebulaeSize; ++i)
    {
        nebulae[i] = new Nebula;
    }
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

    player->LoadActorTexture();
    player->SetTextureRectangle(0.f,
                                0.f,
                                (float)player->actorTexture.width / (float)player->spriteAmountOneLine,
                                (float)player->actorTexture.height);
    player->SetTexturePosition((windowWidth / 2.f) - player->rectangle.width / 2,
                               windowHeight - player->rectangle.height);

    for (int i = 0; i < nebulaeSize; ++i)
    {
        nebulae[i]->LoadActorTexture();
        nebulae[i]->SetTextureRectangle(0.f,
                                        0.f,
                                        (float)nebulae[i]->actorTexture.width / (float)nebulae[i]->spriteAmountOneLine,
                                        (float)nebulae[i]->actorTexture.height / (float)nebulae[i]->spriteAmountOneLine);
        nebulae[i]->SetTexturePosition((windowWidth - nebulae[i]->rectangle.width) + (nebulae[i]->distanceSpace * i),
                                       windowHeight - nebulae[i]->rectangle.height);
    }


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

        for (int i = 0; i < nebulaeSize; ++i)
        {
            nebulae[i]->CalculateRunningTime();
        }

        if (player->CanUpdateAnimate() && player->CheckIsOnGround())
        {
            player->AnimateActor(6);
        }

        for (int i = 0; i < nebulaeSize; ++i)
        {
            if (nebulae[i]->CanUpdateAnimate())
            {
                nebulae[i]->AnimateActor(8);
            }
        }

        player->Jump();

        for (int i = 0; i < nebulaeSize; ++i)
        {
            nebulae[i]->Move();
        }

        player->DrawActor();

        for (int i = 0; i < nebulaeSize; ++i)
        {
            nebulae[i]->DrawActor();
        }
        EndDrawing();

    }

    UnloadTexture(player->GetActor());

    for (int i = 0; i < nebulaeSize; ++i)
    {
        UnloadTexture(nebulae[i]->GetActor());
    }

    CloseWindow();
}

GameManager::~GameManager()
{
    delete player;
}
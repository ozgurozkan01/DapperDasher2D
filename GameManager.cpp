//
// Created by ozgur on 4/28/2023.
//

#include "GameManager.h"
#include "raylib.h"
#include "Player.h"
#include "Nebula.h"
#include "Background.h"

GameManager::GameManager() : gameName("Dapper Dasher 2D")
{
    fps = 60;
    gravity = 3250;

    player = new Player();

    for (int i = 0; i < nebulaeSize; ++i)
    {
        nebulae[i] = new Nebula;
    }

    lastNebula = nebulae[nebulaeSize-1];

    background = new Background();
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
                                (float)player->actorTexture.height / (float)player->spriteLineAmount);
    player->SetTexturePosition((windowWidth / 2.f) - player->rectangle.width / 2,
                               windowHeight - player->rectangle.height);

    player->LoadHealthTexture();

    for (int i = 0; i < nebulaeSize; ++i)
    {
        nebulae[i]->LoadActorTexture();
        nebulae[i]->SetTextureRectangle(0.f,
                                        0.f,
                                        (float)nebulae[i]->actorTexture.width / (float)nebulae[i]->spriteAmountOneLine,
                                        (float)nebulae[i]->actorTexture.height / (float)nebulae[i]->spriteLineAmount);
        nebulae[i]->SetTexturePosition((windowWidth - nebulae[i]->rectangle.width) + (nebulae[i]->distanceSpace + i * nebulae[i]->distanceSpace),
                                       windowHeight - nebulae[i]->rectangle.height);
    }

    background->LoadBackgroundTextures();


    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        if (player->IsAlive())
        {
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

            background->MoveBackground();
            player->Jump();

            for (int i = 0; i < nebulaeSize; ++i)
            {
                nebulae[i]->Move();
            }

            background->DrawBackGround();
            player->DrawActor();

            for (int i = 0; i < nebulaeSize; ++i)
            {
                nebulae[i]->DrawActor();
            }

            player->DrawHealthTexture();

            for (int i = 0; i < nebulaeSize && !player->isDamageTaken; ++i)
            {
                if (player->IsDamageTaken(nebulae[i]))
                {
                    player->TakeDamage();
                    player->isColorChangable = true;
                    player->isDamageTaken = true;
                    nebulae[i]->UpdateNebulaPositionX(lastNebula);
                    lastNebula = nebulae[i];
                    break;
                }
            }

            player->isDamageTaken = false;

            if (player->isColorChangable)
            {
                player->UpdateColor();
            }

            for (int i = 0; i < nebulaeSize; ++i)
            {

                if (nebulae[i]->position.x < -nebulae[i]->rectangle.width)
                {
                    nebulae[i]->UpdateNebulaPositionX(lastNebula);
                    lastNebula = nebulae[i];
                }
            }
        }

        else
        {
            GameOver();
        }

        EndDrawing();
    }

    UnloadTexture(player->GetActor());

    for (int i = 0; i < nebulaeSize; ++i)
    {
        UnloadTexture(nebulae[i]->GetActor());
    }

    background->UnloadBackgroundTextures();
    UnloadTexture(player->GetHealthTexture());
    CloseWindow();
}

GameManager::~GameManager()
{
    delete player;
}

void GameManager::GameOver()
{
    DrawText("Game Over", windowWidth / 2 - 50, windowHeight / 2, 25, RED);
}
//
// Created by ozgur on 4/28/2023.
//
#include "GameManager.h"
#include "raylib.h"
#include "Player.h"
#include "Nebula.h"
#include "Background.h"
#include "Score.h"

GameManager::GameManager() : gameName("Dapper Dasher 2D")
{
    fps = 60;
    gravity = 3250;

    player = new Player();

    for (auto & nebula : nebulae)
    {
        nebula = new Nebula();
    }

    lastNebula = nebulae[nebulaeSize-1];
    background = new Background();
    score = new Score();
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
                               windowHeight - player->rectangle.height - 15.f);

    player->LoadHealthTexture();

    for (int i = 0; i < nebulaeSize; ++i)
    {
        nebulae[i]->LoadActorTexture();
        nebulae[i]->SetTextureRectangle(0.f,
                                        0.f,
                                        (float)nebulae[i]->actorTexture.width / (float)nebulae[i]->spriteAmountOneLine,
                                        (float)nebulae[i]->actorTexture.height / (float)nebulae[i]->spriteLineAmount);
        nebulae[i]->SetTexturePosition((windowWidth - nebulae[i]->rectangle.width) + (nebulae[i]->distanceSpace + (float)i * nebulae[i]->distanceSpace),
                                       windowHeight - nebulae[i]->rectangle.height - 15.f);

        std::cout << nebulae[i]->actorGroundY << std::endl;
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
                player->UpdateMovementSpeed(0);
            }

            if (IsKeyPressed(KEY_W) && player->CheckIsOnGround())
            {
                player->UpdateMovementSpeed(player->GetMovementSpeed());
            }

            if (IsKeyPressed(KEY_S) && !player->CheckIsOnGround())
            {
                player->UpdateMovementSpeed(-player->GetMovementSpeed());
            }

            player->Move();

            player->CalculateRunningTime();

            for (auto & nebula : nebulae)
            {
                nebula->CalculateRunningTime();
            }

            if (player->CanUpdateAnimate() && player->CheckIsOnGround())
            {
                player->AnimateActor(6);
            }

            for (auto & nebula : nebulae)
            {
                if (nebula->CanUpdateAnimate())
                {
                    nebula->AnimateActor(8);
                }
            }


            background->MoveBackground();

            for (auto & nebula : nebulae)
            {
                nebula->Move();
                nebula->IncreaseNebulaSpeedInTime();
            }

            player->ArrangePlayerGroundPosition();

            background->DrawBackGround();
            player->DrawActor();

            for (auto & nebula : nebulae)
            {
                nebula->DrawActor();
            }

            player->DrawHealthTexture();

            for (int i = 0; i < nebulaeSize && !player->isDamageTaken; ++i)
            {
                if (player->CheckCollision(nebulae[i]))
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

            for (auto & nebula : nebulae)
            {

                if (nebula->position.x < -nebula->rectangle.width)
                {
                    nebula->UpdateNebulaPositionX(lastNebula);
                    lastNebula = nebula;
                }
            }

            score->IncreaseScore();
            score->UpdateScoreMultiplierInTime();
            score->DrawScore();
        }

        else
        {
            GameOver();
        }

        EndDrawing();
    }

    UnloadTexture(player->GetActor());

    for (auto & nebula : nebulae)
    {
        UnloadTexture(nebula->GetActor());
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
    DrawText("Game Over !!", windowWidth / 2 - 60, windowHeight / 2, 25, RED);
    DrawText(TextFormat("Score : %5f",score->GetScore()), windowWidth / 2 - 125, windowHeight / 2 - 50, 35, RED);
}

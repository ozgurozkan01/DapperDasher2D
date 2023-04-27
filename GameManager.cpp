//
// Created by ozgur on 4/28/2023.
//

#include "GameManager.h"
#include "raylib.h"

GameManager::GameManager()
{
    windowHeight = 300;
    windowWidth = 400;
    gameName = "Dapper Dasher 2D";

    fps = 60;
}

void GameManager::CreateGameWindow() const
{
    InitWindow(windowWidth, windowHeight, gameName);
}

void GameManager::SetGameFPS() const
{
    SetTargetFPS(fps);
}


void GameManager::Play()
{
    BeginDrawing();
    ClearBackground(BLACK);
    EndDrawing();
}

GameManager::~GameManager()
{
}


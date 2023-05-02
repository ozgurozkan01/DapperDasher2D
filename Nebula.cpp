//
// Created by ozgur on 5/1/2023.
//

#include "Nebula.h"
#include "raylib.h"
#include "GameManager.h"

Nebula::Nebula()
{
    frameCounterY = 0;
    runningTime = 0;
    animationUpdateTime = 1.f / 24.f;
    nebulaSpeed = -300.f;
}

void Nebula::SetNebulaTexture()
{
    nebula = LoadTexture("textures/12_nebula_spritesheet.png");
    nebulaRectangle = {0.f, 0.f, (float)nebula.width / 8, (float)nebula.height / 8};
    nebulaPosition = {GameManager::windowWidth - nebulaRectangle.width, GameManager::windowHeight - nebulaRectangle.height};
}

void Nebula::DrawNebula()
{
    DrawTextureRec(nebula, nebulaRectangle, nebulaPosition, WHITE);
}

Texture2D Nebula::GetNebula()
{
    return nebula;
}

void Nebula::Move()
{
    float deltaTime = GetFrameTime();
    nebulaPosition.x += (nebulaSpeed * deltaTime);
}

void Nebula::AnimateNebula()
{
    nebulaRectangle.x = frameCounterY * nebulaRectangle.width;
    frameCounterY++;
    runningTime = 0.f;

    if (frameCounterY > 7)
    {
        frameCounterY = 0;
    }

}

void Nebula::CalculateRunningTime()
{
    runningTime += GetFrameTime();
}

bool Nebula::CanUpdateAnimate() const
{
    return runningTime >= animationUpdateTime;
}
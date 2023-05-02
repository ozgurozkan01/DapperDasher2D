//
// Created by ozgur on 5/1/2023.
//

#include "Nebula.h"
#include "raylib.h"
#include <iostream>

Nebula::Nebula()
{
    frameCounterX = 0;
    frameCounterY = 0;
    runningTime = 0;
    animationUpdateTime = 1.f / 24.f;
}

void Nebula::SetNebulaTexture()
{
    nebula = LoadTexture("textures/12_nebula_spritesheet.png");
    nebulaRectangle = {0.f, 0.f, (float)nebula.width / 8, (float)nebula.height / 8};
    nebulaPosition = {400 - nebulaRectangle.width, 300 - nebulaRectangle.height};
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
    nebulaPosition.x -= 1;
}

void Nebula::AnimateNebula()
{
    nebulaRectangle.x = frameCounterY * nebulaRectangle.width;
    frameCounterY++;

    if (frameCounterY > 8)
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
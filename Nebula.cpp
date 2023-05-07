//
// Created by ozgur on 5/1/2023.
//

#include "Nebula.h"
#include "raylib.h"

Nebula::Nebula() : Actor(1.f / 12.f),  nebulaSpeed(-300.f)
{
    distanceSpace = 400.f;
    spriteAmountOneLine = 8;
    spriteLineAmount = 7;
    fileName = "textures/12_nebula_spritesheet.png";
}

void Nebula::Move()
{
    float deltaTime = GetFrameTime();
    position.x += (float)(nebulaSpeed * deltaTime);
}

void Nebula::UpdateNebulaPositionX(Nebula* lastNebula)
{
    position.x = lastNebula->position.x + distanceSpace;
}

void Nebula::IncreaseNebulaSpeedInTime()
{
    float deltaTime = GetFrameTime();
    nebulaSpeed -= deltaTime ;
}

//
// Created by ozgur on 5/1/2023.
//

#include "Nebula.h"
#include "raylib.h"
#include "GameManager.h"

Nebula::Nebula() : Actor(1.f / 12.f), nebulaSpeed(-300.f)
{
    distanceSpace = 300.f;
    spriteAmountOneLine = 8;
    fileName = "textures/12_nebula_spritesheet.png";
}

void Nebula::Move()
{
    float deltaTime = GetFrameTime();
    position.x += (nebulaSpeed * deltaTime);
}

/*
void Nebula::SetTextureProperties(int spriteAmount)
{
    rectangle = {0.f, 0.f, (float)actorTexture.width / spriteAmount,(float)actorTexture.height / spriteAmount};
    position = {(GameManager::windowWidth - rectangle.width) + distanceSpace, GameManager::windowHeight - rectangle.height};
}
*/

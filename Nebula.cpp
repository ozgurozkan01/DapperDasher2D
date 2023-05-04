//
// Created by ozgur on 5/1/2023.
//

#include "Nebula.h"
#include "raylib.h"
#include "GameManager.h"

Nebula::Nebula(float animationUpdateTime) : Actor(animationUpdateTime), nebulaSpeed(-300.f)
{}

void Nebula::Move()
{
    float deltaTime = GetFrameTime();
    position.x += (nebulaSpeed * deltaTime);
}

void Nebula::SetMebulaTexturePosition(int spriteAmount)
{
    rectangle = {0.f, 0.f, (float)actorTexture.width / spriteAmount,(float)actorTexture.height / 8};
    position = {GameManager::windowWidth - rectangle.width, GameManager::windowHeight - rectangle.height};
}

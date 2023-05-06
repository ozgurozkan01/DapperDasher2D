//
// Created by ozgur on 5/4/2023.
//

#include "Actor.h"

Actor::Actor(float animationUpdateTime, int spriteLineAmount)
{
    color = WHITE;
    frame = 0;
    runningTime = 0;
    actorAnimationUpdateTime = animationUpdateTime;
    fileName = "textures/scarfy.png";
    this->spriteLineAmount = spriteLineAmount;
    actorCenter = {0.f, 0.f};
}

void Actor::LoadActorTexture()
{
    actorTexture = LoadTexture(fileName);
}

Texture2D Actor::GetActor()
{
    return actorTexture;
}

void Actor::DrawActor()
{
    DrawTextureRec(actorTexture, rectangle,position, color);
}

void Actor::CalculateRunningTime()
{
    float deltaTime = GetFrameTime();
    runningTime += deltaTime;
}

bool Actor::CanUpdateAnimate() const
{
    return runningTime >= actorAnimationUpdateTime;
}

void Actor::AnimateActor(int spriteAmount)
{
    rectangle.x = frame * rectangle.width;
    frame++;
    runningTime = 0.f;

    if (frame > spriteAmount - 1)
    {
        frame = 0;
    }
}

void Actor::SetTextureRectangle(float recX, float recY, float textureWidth, float textureHeight)
{
    rectangle = {recX, recY, textureWidth,textureHeight};
}

void Actor::SetTexturePosition(float positionX, float positionY)
{
    position = { positionX, positionY};
}
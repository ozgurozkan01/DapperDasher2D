//
// Created by ozgur on 5/4/2023.
//

#include "Actor.h"
#include "GameManager.h"

Actor::Actor(float animationUpdateTime) {
    frame = 0;
    runningTime = 0;
    actorAnimationUpdateTime = animationUpdateTime;
}

void Actor::LoadActorTexture(const char *fileName) {
    actorTexture = LoadTexture(fileName);
}

Texture2D Actor::GetActor() {
    return actorTexture;
}

void Actor::DrawActor() {
    DrawTextureRec(actorTexture, rectangle,position, WHITE);
}

void Actor::CalculateRunningTime() {
    float deltaTime = GetFrameTime();
    runningTime += deltaTime;
}

bool Actor::CanUpdateAnimate() const {
    return runningTime >= actorAnimationUpdateTime;
}

void Actor::AnimateActor(int spriteAmount) {
    rectangle.x = frame * rectangle.width;
    frame++;
    runningTime = 0.f;

    if (frame > spriteAmount - 1)
    {
        frame = 0;
    }
}


//
// Created by ozgur on 5/4/2023.
//

#ifndef MAIN_CPP_ACTOR_H
#define MAIN_CPP_ACTOR_H

#include "raylib.h"
#include "GameManager.h"

class Actor {

protected:

    float frame;
    float runningTime;
    float actorAnimationUpdateTime;
    const char *fileName;
    Color color;


public:

    float actorGroundY;
    Texture2D actorTexture;
    Rectangle rectangle;
    Vector2 position;

    int spriteAmountOneLine;
    int spriteLineAmount;
    explicit Actor(float animationUpdateTime);

    void LoadActorTexture();
    void SetTextureRectangle(float recX, float recY, float textureWidth, float textureHeight);
    void SetTexturePosition(float positionX, float positionY);
    Texture2D GetActor();
    void DrawActor();
    void CalculateRunningTime();
    bool CanUpdateAnimate() const;
    void AnimateActor(int spriteAmount);
};


#endif //MAIN_CPP_ACTOR_H

//
// Created by ozgur on 5/4/2023.
//

#ifndef MAIN_CPP_ACTOR_H
#define MAIN_CPP_ACTOR_H
#include "raylib.h"

class Actor {

protected:

    Vector2 position;
    Rectangle rectangle;
    Texture2D actorTexture;

    float frame;
    float runningTime;
    float actorAnimationUpdateTime;

public:

    explicit Actor(float animationUpdateTime);

    void LoadActorTexture(const char *fileName);
    Texture2D GetActor();
    void DrawActor();
    void CalculateRunningTime();
    bool CanUpdateAnimate() const;
    void AnimateActor(int spriteAmount);
};


#endif //MAIN_CPP_ACTOR_H

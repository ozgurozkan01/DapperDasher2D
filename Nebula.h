//
// Created by ozgur on 5/1/2023.
//

#ifndef MAIN_CPP_NEBULA_H
#define MAIN_CPP_NEBULA_H
#include "raylib.h"


class Nebula {

    Texture2D nebula;
    Vector2 nebulaPosition;
    Rectangle nebulaRectangle;
    float nebulaSpeed;

    int frameCounterY;

    float runningTime;
    float animationUpdateTime;

    

public:

    Nebula();

    Texture2D GetNebula();
    void SetNebulaTexture();
    void DrawNebula();
    void Move();
    void AnimateNebula();
    void CalculateRunningTime();
    bool CanUpdateAnimate() const;
};


#endif //MAIN_CPP_NEBULA_H

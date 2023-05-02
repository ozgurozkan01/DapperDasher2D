//
// Created by ozgur on 4/30/2023.
//

#ifndef MAIN_CPP_PLAYER_H
#define MAIN_CPP_PLAYER_H
#include "raylib.h"
class Player{

private:
    const float jumpSpeed;
    Vector2 scarfyPosition;
    Rectangle scarfyRectangle;
    Texture2D scarfy;
    float frame;

    float runningTime;
    float animationUpdateTime;

public:

    float velocity;

    Player();

    Texture2D GetScarfy() const;
    float GetJumpSpeed() const;
    void SetPlayerTexture();
    void DrawPlayer() const;
    void Jump();
    void UpdateJumpSpeed(float newSpeed);
    bool CheckIsOnGround() const;
    void AnimateScarfy();
    void CalculateRunningTime();
    bool CanUpdateAnimate() const;
};


#endif //MAIN_CPP_PLAYER_H

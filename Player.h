//
// Created by ozgur on 4/30/2023.
//

#ifndef MAIN_CPP_PLAYER_H
#define MAIN_CPP_PLAYER_H
#include "raylib.h"
#include "Actor.h"

class Player : public Actor{

private:
/*    Vector2 scarfyPosition;
    Rectangle scarfyRectangle;
    Texture2D scarfy;
    float frame;

    float runningTime;*/
    const float jumpSpeed;

public:

    float velocity;

    Player(float animationUpdateTime);

    void SetPlayerTexturePosition(int spriteAmount);
    float GetJumpSpeed() const;
    void Jump();
    void UpdateJumpSpeed(float newSpeed);
    bool CheckIsOnGround() const;
};


#endif //MAIN_CPP_PLAYER_H

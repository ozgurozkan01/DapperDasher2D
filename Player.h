//
// Created by ozgur on 4/30/2023.
//

#ifndef MAIN_CPP_PLAYER_H
#define MAIN_CPP_PLAYER_H
#include "raylib.h"
#include "Actor.h"

class Player : public Actor{

private:

    const float jumpSpeed;

    float changingColorFrameCounter;
    float changingColorTimeLimit;
    int colorUpdateAmount;
    int colorUpdateTimeLimit;

    Texture2D healthTexture;

public:

    bool isColorChangable;
    bool isDamageTaken;

    float velocity;
    int health;

    Player();

    float GetJumpSpeed() const;
    void Jump();
    void UpdateJumpSpeed(float newSpeed);
    bool CheckIsOnGround() const;
    Color DetermineColor();
    bool CheckCollision(Actor* nebula);
    void TakeDamage();
    void UpdateColor();
    bool IsAlive();
    void LoadHealthTexture();
    void DrawHealthTexture();
    Texture2D GetHealthTexture();
};


#endif //MAIN_CPP_PLAYER_H

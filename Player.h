//
// Created by ozgur on 4/30/2023.
//

#ifndef MAIN_CPP_PLAYER_H
#define MAIN_CPP_PLAYER_H
#include "raylib.h"
#include "Actor.h"

class Player : public Actor{

private:

    const float movementSpeed;

    float changingColorFrameCounter;
    float changingColorTimeLimit;
    int colorUpdateAmount;
    int colorUpdateTimeLimit;

    Texture2D healthTexture;
    Rectangle healthRectangle;
public:

    bool isColorChangable;
    bool isDamageTaken;

    float velocity;
    int healthAmount;

    Player();

    float GetMovementSpeed() const;
    void Move();
    void UpdateMovementSpeed(float newSpeed);
    bool CheckIsOnGround() const;
    Color DetermineColor();
    bool CheckCollision(Actor* nebula);
    void TakeDamage();
    void UpdateColor();
    bool IsAlive();
    void LoadHealthTexture();
    void DrawHealthTexture();
    Texture2D GetHealthTexture();
    bool CheckPlayerPositionIsCorrect();
    void ArrangePlayerGroundPosition();
};


#endif //MAIN_CPP_PLAYER_H

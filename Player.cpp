//
// Created by ozgur on 4/30/2023.
//

#include "Player.h"
#include <iostream>

Player::Player() : jumpSpeed(-1000)
{
    frame = 0;
    runningTime = 0;
    animationUpdateTime = 1.f / 6.f;
}

void Player::Jump()
{
    scarfyPosition.y += (velocity * GetFrameTime());
}

void Player::DrawPlayer() const
{
    DrawTextureRec(scarfy, scarfyRectangle,scarfyPosition, WHITE);
}

void Player::UpdateJumpSpeed(float newSpeed)
{
    velocity = newSpeed;
}

bool Player::CheckIsOnGround() const
{
    return scarfyPosition.y >= 300 - scarfy.height;
}

Texture2D Player::GetScarfy() const
{
    return scarfy;
}

void Player::SetPlayerTexture()
{
    scarfy = LoadTexture("textures/scarfy.png");
    scarfyRectangle.height = (float)scarfy.height;
    scarfyRectangle.width = (float)scarfy.width / 6;
    scarfyRectangle.x = 0;
    scarfyRectangle.y = 0;

    scarfyPosition.x = 200 - scarfyRectangle.width / 2;
    scarfyPosition.y = 300 - scarfy.height;
}

float Player::GetJumpSpeed() const
{
    return jumpSpeed;
}

void Player::AnimateScarfy()
{
    scarfyRectangle.x = frame * scarfyRectangle.width;
    frame++;
    runningTime = 0.f;

    if (frame > 5)
    {
        frame = 0;
    }
}

bool Player::CanUpdateAnimate() const
{
    return runningTime >= animationUpdateTime;
}

void Player::CalculateRunningTime()
{
    runningTime += GetFrameTime();
}


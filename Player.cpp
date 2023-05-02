//
// Created by ozgur on 4/30/2023.
//

#include "Player.h"
#include "GameManager.h"

Player::Player() : jumpSpeed(-1200)
{
    frame = 0;
    runningTime = 0;
    animationUpdateTime = 1.f / 10.f;
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
    return scarfyPosition.y >= GameManager::windowHeight - scarfy.height;
}

Texture2D Player::GetScarfy() const
{
    return scarfy;
}

void Player::SetPlayerTexture()
{
    scarfy = LoadTexture("textures/scarfy.png");
    scarfyRectangle = {0.f, 0.f, (float)scarfy.width / 6,(float)scarfy.height};
    scarfyPosition = {(GameManager::windowWidth / 2) - scarfyRectangle.width / 2, GameManager::windowHeight - scarfyRectangle.height};
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
    float deltaTime = GetFrameTime();
    runningTime += deltaTime;
}


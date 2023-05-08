//
// Created by ozgur on 4/30/2023.
//

#include "Player.h"
#include "GameManager.h"

Player::Player() : Actor(1.f / 12.f), movementSpeed(-1200)
{
    healthAmount = 5;
    spriteAmountOneLine = 6;
    spriteLineAmount = 1;
    changingColorTimeLimit = 0.3f;
    changingColorFrameCounter = changingColorTimeLimit;
    colorUpdateTimeLimit = 8;
    isDamageTaken = false;
    isColorChangable = false;
}

void Player::Move()
{
    float deltaTime = GetFrameTime();
    position.y += (velocity * deltaTime);
}

void Player::UpdateMovementSpeed(float newSpeed)
{
    velocity = newSpeed;
}

bool Player::CheckIsOnGround() const
{
    return position.y >= actorGroundY;
}

float Player::GetMovementSpeed() const
{
    return movementSpeed;
}

bool Player::CheckCollision(Actor* nebula)
{
    return (abs(nebula->position.x - position.x) <= rectangle.width / 2) && (abs(nebula->position.y - position.y) <= rectangle.height / 2);
}

void Player::TakeDamage()
{
    healthAmount--;
}

Color Player::DetermineColor()
{
    if (colorUpdateAmount % 2 == 0)
    {return RED;}

    return WHITE;
}

void Player::UpdateColor()
{
    if (changingColorFrameCounter >= changingColorTimeLimit)
    {
        color = DetermineColor();
        changingColorFrameCounter = 0;
        colorUpdateAmount++;
    }

    if (colorUpdateAmount == colorUpdateTimeLimit)
    {
        isColorChangable = false;
        colorUpdateAmount = 0;
    }

    float deltaTime = GetFrameTime();
    changingColorFrameCounter += deltaTime;
}

bool Player::IsAlive()
{
    return healthAmount > 0;
}

void Player::LoadHealthTexture()
{
    healthTexture = LoadTexture("textures/heart.png");
}

void Player::DrawHealthTexture()
{
    for (int i = 0; i < healthAmount; ++i)
    {
        DrawTextureEx(healthTexture, {0.F + i * 30.f, 10.F}, 0.F, 0.07f, WHITE);
    }
}

Texture2D Player::GetHealthTexture()
{
    return healthTexture;
}

bool Player::CheckPlayerPositionIsCorrect()
{
    return position.y > actorGroundY;
}

void Player::ArrangePlayerGroundPosition()
{
    if (CheckPlayerPositionIsCorrect())
    {
        position.y = actorGroundY;
    }
}
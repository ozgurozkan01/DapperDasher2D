//
// Created by ozgur on 4/30/2023.
//

#include "Player.h"
#include "GameManager.h"

Player::Player() : Actor(1.f / 12.f, 1), jumpSpeed(-1200)
{
    health = 3;
    spriteAmountOneLine = 6;
    changingColorTimeLimit = 0.3f;
    changingColorFrameCounter = changingColorTimeLimit;
    colorUpdateTimeLimit = 8;
    isDamageTaken = false;
    isColorChangable = false;
}

void Player::Jump()
{
    float deltaTime = GetFrameTime();
    position.y += (velocity * deltaTime);
}

void Player::UpdateJumpSpeed(float newSpeed)
{
    velocity = newSpeed;
}

bool Player::CheckIsOnGround() const
{
    return position.y >= GameManager::windowHeight - actorTexture.height;
}

float Player::GetJumpSpeed() const
{
    return jumpSpeed;
}

bool Player::IsDamageTaken(Actor* nebula)
{
    actorCenter = {position.x + rectangle.width / 2, position.y - rectangle.height / 2};
    nebula->actorCenter = {nebula->position.x + nebula->rectangle.width / 2, nebula->position.y - nebula->rectangle.height / 2};

    return (abs(nebula->actorCenter.x - actorCenter.x) <= rectangle.width / 2) && (abs(nebula->actorCenter.y - actorCenter.y) <= rectangle.height / 2);
}

void Player::TakeDamage()
{
    health--;
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
    return health > 0;
}
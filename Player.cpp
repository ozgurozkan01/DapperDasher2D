//
// Created by ozgur on 4/30/2023.
//

#include "Player.h"
#include "GameManager.h"

Player::Player(float animationUpdateTime) : Actor(animationUpdateTime), jumpSpeed(-1200)
{}

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

void Player::SetPlayerTexturePosition(int spriteAmount)
{
    rectangle = {0.f, 0.f, (float)actorTexture.width / spriteAmount,(float)actorTexture.height};
    position = {((float)GameManager::windowWidth / 2) - rectangle.width / 2, GameManager::windowHeight - rectangle.height};
}



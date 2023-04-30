//
// Created by ozgur on 4/30/2023.
//

#include "Player.h"
#include "raylib.h"
#include "GameManager.h"


Player::Player()
{
    jumpSpeed = 0;
    positionX = 175;
    positionY = 250;
}

void Player::Jump()
{
    positionY += jumpSpeed;
}

void Player::DrawPlayer() const
{
    DrawRectangle(positionX, positionY, 50, 50, RED);
}

void Player::UpdateJumpSpeed(int newSpeed)
{
    jumpSpeed = newSpeed;
}

bool Player::CheckIsOnGround() const
{
    return positionY >= 250;
}
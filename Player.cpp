//
// Created by ozgur on 4/30/2023.
//

#include "Player.h"


Player::Player() : jumpSpeed(-17){}

void Player::Jump()
{
    scarfyPosition.y += velocity;
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

    scarfyPosition.x = 400 / 2;
    scarfyPosition.y = 300 - scarfy.height;
}

float Player::GetJumpSpeed() const
{
    return jumpSpeed;
}


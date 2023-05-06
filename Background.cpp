//
// Created by ozgur on 5/6/2023.
//

#include "Background.h"

void Background::LoadBackgroundTextures()
{
    bottomgroundMovementSpeed = 30.f;
    middlegroundMovementSpeed = 50.f;
    upgroundMovementSpeed = 100.f;

    bottomGround = LoadTexture("textures/far-buildings.png");
    middleGround = LoadTexture("textures/back-buildings.png");
    upGround = LoadTexture("textures/foreground.png");

    bottomgroundPosition = {0.f, 0.f};
    bottomgroundPosition2 = {bottomgroundPosition.x + (float)bottomGround.width * 2, 0.f};

    middleGroundPosition = {0.f, 0.f};
    middleGroundPosition2 = {middleGroundPosition.x + (float)middleGround.width * 2, 0.f};

    upGroundPosition = {0.f, 0.f};
    upGroundPosition2 = {upGroundPosition.x + (float)upGround.width * 2, 0.f};
}

void Background::DrawBackGround()
{
    DrawTextureEx(bottomGround, bottomgroundPosition, 0, 2, WHITE);
    DrawTextureEx(bottomGround, bottomgroundPosition2, 0, 2, WHITE);

    DrawTextureEx(middleGround, middleGroundPosition, 0, 2, WHITE);
    DrawTextureEx(middleGround, middleGroundPosition2, 0, 2, WHITE);

    DrawTextureEx(upGround, upGroundPosition, 0, 2, WHITE);
    DrawTextureEx(upGround, upGroundPosition2, 0, 2, WHITE);
}

void Background::UnloadBackgroundTextures()
{
    UnloadTexture(bottomGround);
    UnloadTexture(bottomGround);

    UnloadTexture(middleGround);
    UnloadTexture(middleGround);

    UnloadTexture(upGround);
    UnloadTexture(upGround);
}

void Background::MoveBackground()
{
    float deltaTime = GetFrameTime();
    bottomgroundPosition.x -= bottomgroundMovementSpeed * deltaTime;
    bottomgroundPosition2.x = bottomgroundPosition.x + bottomGround.width * 2;

    if (bottomgroundPosition.x <= -bottomGround.width * 2)
    {
        bottomgroundPosition.x = 0.f;
    }

    middleGroundPosition.x -= middlegroundMovementSpeed * deltaTime;
    middleGroundPosition2.x = middleGroundPosition.x + middleGround.width * 2;

    if (middleGroundPosition.x <= -middleGround.width * 2)
    {
        middleGroundPosition.x = 0.f;
    }

    upGroundPosition.x -= upgroundMovementSpeed * deltaTime;
    upGroundPosition2.x = upGroundPosition.x + upGround.width * 2;

    if (upGroundPosition.x <= -upGround.width * 2)
    {
        upGroundPosition.x = 0.f;
    }
}

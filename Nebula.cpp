//
// Created by ozgur on 5/1/2023.
//

#include "Nebula.h"
#include "raylib.h"

void Nebula::SetNebulaTexture()
{
    nebula = LoadTexture("textures/12_nebula_spritesheet.png");
    nebulaRectangle.width = nebula.width / 8;
    nebulaRectangle.height = nebula.height / 8;
    nebulaRectangle.x = 0;
    nebulaRectangle.y = 0;

    nebulaPos.x = 400 - nebulaRectangle.width;
    nebulaPos.y = 300 - nebulaRectangle.height;
}

void Nebula::DrawNebula()
{
    DrawTextureRec(nebula, nebulaRectangle, nebulaPos, WHITE);
}

Texture2D Nebula::GetNebula()
{
    return nebula;
}

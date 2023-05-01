//
// Created by ozgur on 5/1/2023.
//

#ifndef MAIN_CPP_NEBULA_H
#define MAIN_CPP_NEBULA_H
#include "raylib.h"


class Nebula {

    Texture2D nebula;
    Vector2 nebulaPos;
    Rectangle nebulaRectangle;

public:

    Texture2D GetNebula();
    void SetNebulaTexture();
    void DrawNebula();
};


#endif //MAIN_CPP_NEBULA_H

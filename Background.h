//
// Created by ozgur on 5/6/2023.
//

#ifndef MAIN_CPP_BACKGROUND_H
#define MAIN_CPP_BACKGROUND_H

#include "raylib.h"

class Background {

private:

    float bottomgroundMovementSpeed;
    float middlegroundMovementSpeed;
    float upgroundMovementSpeed;

    Texture2D bottomGround;
    Texture2D middleGround;
    Texture2D upGround;

    Vector2 bottomgroundPosition;
    Vector2 bottomgroundPosition2;

    Vector2 middleGroundPosition;
    Vector2 middleGroundPosition2;

    Vector2 upGroundPosition;
    Vector2 upGroundPosition2;

public:

    void LoadBackgroundTextures();
    void UnloadBackgroundTextures();
    //void DrawBackGround();
    //void MoveBackground();
};


#endif //MAIN_CPP_BACKGROUND_H

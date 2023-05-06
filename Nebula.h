//
// Created by ozgur on 5/1/2023.
//

#ifndef MAIN_CPP_NEBULA_H
#define MAIN_CPP_NEBULA_H
#include "raylib.h"
#include "Actor.h"

class Nebula : public Actor{

    const float nebulaSpeed;

public:

    float distanceSpace;

    Nebula();
    void UpdateNebulaPositionX(Nebula* lastNebula);
    void Move();
};


#endif //MAIN_CPP_NEBULA_H

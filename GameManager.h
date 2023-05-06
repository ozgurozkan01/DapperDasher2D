//
// Created by ozgur on 4/28/2023.
//

#ifndef MAIN_CPP_GAMEMANAGER_H
#define MAIN_CPP_GAMEMANAGER_H
#include <iostream>

class Player;
class Nebula;
class Background;

class GameManager {

    int fps;
    float gravity;

    Player* player;
    static const int nebulaeSize = 5;
    Nebula* nebulae[nebulaeSize];
    Nebula* lastNebula;
    Background* background;

public:


    const static int windowHeight = 380;
    const static int windowWidth = 512;
    const char* gameName;

    GameManager();
    ~GameManager();

    void ApplyGravity(float& speed) const;
    void CreateGameWindow() const;
    void SetGameFPS() const;
    void Play();
    void GameOver();
};


#endif //MAIN_CPP_GAMEMANAGER_H

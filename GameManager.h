//
// Created by ozgur on 4/28/2023.
//

#ifndef MAIN_CPP_GAMEMANAGER_H
#define MAIN_CPP_GAMEMANAGER_H
#include <iostream>

class Player;

class GameManager {

    int fps;
    int gravity;

    Player* player;

public:

    const int windowHeight;
    const int windowWidth;
    const char* gameName;

    GameManager();
    ~GameManager();

    void ApplyGravity(int& speed) const;
    void CreateGameWindow() const;
    void SetGameFPS() const;
    void Play();
};


#endif //MAIN_CPP_GAMEMANAGER_H

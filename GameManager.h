//
// Created by ozgur on 4/28/2023.
//

#ifndef MAIN_CPP_GAMEMANAGER_H
#define MAIN_CPP_GAMEMANAGER_H


class GameManager {

    // game window properties
    int windowWidth;
    int windowHeight;
    const char* gameName;

    int fps;

public:

    GameManager();
    ~GameManager();

    void CreateGameWindow() const;
    void SetGameFPS() const;
    static void Play();
};


#endif //MAIN_CPP_GAMEMANAGER_H

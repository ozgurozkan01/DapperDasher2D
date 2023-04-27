#include "raylib.h"
#include "GameManager.h"

int main() {

    GameManager* gameManager = new GameManager;

    gameManager->CreateGameWindow();
    gameManager->SetGameFPS();

    while(!WindowShouldClose())
    {
        gameManager->Play();
    }


    return 0;
}

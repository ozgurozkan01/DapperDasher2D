#include "GameManager.h"

int main() {

    GameManager* gameManager = new GameManager;

    gameManager->Play();

    delete gameManager;
    return 0;
}

//
// Created by ozgur on 4/30/2023.
//

#ifndef MAIN_CPP_PLAYER_H
#define MAIN_CPP_PLAYER_H


class Player{

public:

    int positionX;
    int positionY;
    int jumpSpeed;

    Player();

    void DrawPlayer() const;
    void Jump();
    void UpdateJumpSpeed(int newSpeed);
    bool CheckIsOnGround() const;
};


#endif //MAIN_CPP_PLAYER_H

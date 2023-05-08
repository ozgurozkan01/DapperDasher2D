//
// Created by ozgur on 5/8/2023.
//

#ifndef MAIN_CPP_SCORE_H
#define MAIN_CPP_SCORE_H



class Score {

private:
    float score;
    float scoreMultiplier;

public:

    Score();

    float GetScore();
    void IncreaseScore();
    void UpdateScoreMultiplierInTime();
    void DrawScore();
};


#endif //MAIN_CPP_SCORE_H

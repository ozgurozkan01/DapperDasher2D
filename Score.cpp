//
// Created by ozgur on 5/8/2023.
//

#include "Score.h"
#include "raylib.h"

Score::Score()
{
    score = 0;
    scoreMultiplier = 0.1f;
}

void Score::IncreaseScore()
{
    float deltaTime = GetFrameTime();
    score += deltaTime * scoreMultiplier;
}

void Score::DrawScore()
{
    DrawText(TextFormat("Score : %5f",score), 350, 15, 15, RED);

}

float Score::GetScore()
{
    return score;
}

void Score::UpdateScoreMultiplierInTime()
{
    scoreMultiplier += 0.001;
}

#pragma once
#include "Move.h"
class Player
{
    int winCount = 0;
    int loseCount = 0;
    int drawCount = 0;

public:
    void addWin();
    void addLose();
    void addDraw();
    int getWinCount();
    int getLoseCount();
    int getDrawCount();
    virtual Move getMove() = 0;
    virtual ~Player() = default;
};
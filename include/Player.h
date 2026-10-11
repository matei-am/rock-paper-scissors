#pragma once
#include <string>
#include "GameRules.h"
using namespace std;

class Player
{
    int winCount = 0;
    int lossCount = 0;
    int drawCount = 0;

public:
    void addWin();
    void addLoss();
    void addDraw();
    int getWinCount() const;
    int getLossCount() const;
    int getDrawCount() const;
    virtual Move getMove() = 0;
    virtual string getName() const = 0;
    virtual ~Player() = default;
};
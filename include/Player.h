#pragma once
#include <string>
#include "GameRules.h"

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
    virtual Move getMove() const = 0;
    virtual void setName(const std::string &userName) = 0;
    virtual std::string getName() const = 0;
    virtual ~Player() = default;
};
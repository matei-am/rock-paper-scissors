#pragma once
#include <string>
#include "Player.h"

class Human : public Player
{
private:
    string name;

public:
    Move getMove() override;
    string getName() const override;
    void setName(const string &userName);
};
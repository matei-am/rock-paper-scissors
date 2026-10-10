#pragma once
#include <string>
#include "Player.h"

class Human : public Player
{
public:
    Move getMove() override;
    std::string getName() override;
};
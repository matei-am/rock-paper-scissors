#pragma once
#include <string>
#include "Player.h"

class Computer : public Player
{
public:
    Move getMove() override;
    string getName() const override;
};
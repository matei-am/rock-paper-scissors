#pragma once
#include "Player.h"
class Computer : public Player
{
public:
    Move getMove() override;
};
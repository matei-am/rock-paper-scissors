#pragma once
#include <string>
#include "Player.h"

class Computer : public Player
{
public:
    Move getMove() const override;
    std::string getName() const override;
    void setName(const std::string &userName) override;
};
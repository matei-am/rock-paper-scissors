#pragma once
#include <string>
#include "Player.h"

class Human : public Player
{
private:
    std::string name;

public:
    Move getMove() const override;
    std::string getName() const override;
    void setName(const std::string &userName) override;
};
#pragma once
#include <string>
#include "Player.h"

class Human : public Player
{
private:
    std::string name;

public:
    Move getMove() const override;
    std::string getUserName() const override;
    void setUserName(const std::string &userName) override;
};
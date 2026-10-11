#include "Player.h"

class TestComputer : public Player
{
public:
    Move move;
    TestComputer(Move move)
    {
        this->move = move;
    };
    Move getMove() override;
    string getName() const override;
};

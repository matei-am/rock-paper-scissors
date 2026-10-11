#include "Player.h"
class HumanTestPlayer : public Player
{
public:
    string name;
    Move move;
    HumanTestPlayer(const string& name, Move move)
    {
        this->name = name;
        this->move = move;
    }
    Move getMove() override;
    string getName() const override;
};
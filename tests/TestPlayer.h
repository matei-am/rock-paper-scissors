#include "Player.h"
class TestPlayer : public Player
{
public:
    Move getMove() override;
    string getName() const override;
};


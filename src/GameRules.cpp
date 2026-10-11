#include "GameRules.h"
using namespace std;
namespace Rules
{

    outcome determineOutcome(Move player1Move, Move player2Move)
    {
        if (player1Move == player2Move)
        {
            return outcome::DRAW;
        }

        if (
            (player1Move == Move::ROCK &&
             player2Move == Move::SCISSORS) ||
            (player1Move == Move::PAPER &&
             player2Move == Move::ROCK) ||
            (player1Move == Move::SCISSORS &&
             player2Move == Move::PAPER))
        {
            return outcome::WIN;
        }

        return outcome::LOSS;
    }
}



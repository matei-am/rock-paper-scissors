#include <iostream>
#include "GameRules.h"
#include "GameEngine.h"
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

void Game::determineRoundResult(Player &player1, Player &player2)
{
    Move player1Move = player1.getMove();
    Move player2Move = player2.getMove();
    outcome roundResult = Rules::determineOutcome(player1Move, player2Move);
    if (roundResult == outcome::DRAW)
    {
        player1.addDraw();
        player2.addDraw();
        cout << "It's a draw!" << endl;
    }
    else if (roundResult == outcome::WIN)
    {
        player1.addWin();
        player2.addLose();
        cout << "Player 1 wins this round!" << endl;
    }
    else
    {
        player1.addLose();
        player2.addWin();
        cout << "Player 2 wins this round!" << endl;
    }
}

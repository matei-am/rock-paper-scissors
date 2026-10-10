#include <iostream>
#include "Move.h"
#include "Player.h"
#include "GameEngine.h"
using namespace std;


void Game::determineRoundResult(Player& player1, Player& player2, Move player1Move, Move player2Move)
{
    if (player1Move == player2Move)
    {
        player1.addDraw();
        player2.addDraw();
        cout << "It's a draw!" << endl;
    }
    else if ((player1Move == Move::ROCK && player2Move == Move::SCISSORS) ||
             (player1Move == Move::PAPER && player2Move == Move::ROCK) ||
             (player1Move == Move::SCISSORS && player2Move == Move::PAPER))
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

void Player::addWin()
{
    winCount++;
}
void Player::addLose()
{
    loseCount++;
}
void Player::addDraw()
{
    drawCount++;
}
int Player::getWinCount()
{
    return winCount;
}

int Player::getLoseCount()
{
    return loseCount;
}

int Player::getDrawCount()
{
    return drawCount;
}
void Game::displayGameStats(Player& player1, Player& player2)
{   
    cout << "⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇" << endl;
    Player& winner = (player1.getWinCount() > player2.getWinCount()) ? player1 : player2;
    if(player1.getWinCount() == player2.getWinCount())
    {
        cout << "It's a tie!" << endl;
    }
    else
    {
        cout << "Winner: " << ((&winner == &player1) ? "Player 1" : "Player 2") << endl;
    }
    cout << "---------------------------------" << endl;
    cout<< "out of " << (player1.getWinCount() + player1.getLoseCount() + player1.getDrawCount()) << " rounds:" << endl;
    cout << "Player 1 has " << player1.getWinCount() << " Wins" << endl;
    cout << "Player 1 has " << player1.getLoseCount() << " Losses" << endl;
    cout << "Player 1 has " << player1.getDrawCount() << " Draws" << endl;
    cout << "Player 2 has " << player2.getWinCount() << " Wins" << endl;
    cout << "Player 2 has " << player2.getLoseCount() << " Losses" << endl;
    cout << "Player 2 has " << player2.getDrawCount() << " Draws" << endl;
    cout << "---------------------------------" << endl;
}


void Game::displayRoundResult(outcome roundResult)
{
    if (roundResult == outcome::WIN)
    {
        cout << "You win!" << endl;
    }
    else if (roundResult == outcome::LOSE)
    {
        cout << "You lose!" << endl;
    }
    else
        cout << "It's a draw!" << endl;
}

#include <iostream>
#include "GameEngine.h"
#include "Move.h"
#include "Player.h"
#include "Human.h"
#include "Computer.h"
using namespace std;

void Game::startGame(Player& player1, Player& player2)
{
    cout << "Welcome to Rock, Paper, Scissors!" << endl;
    cout << "How many rounds would you like to play? ";
    cin >> rounds;
    while (rounds <= 0)
    {
        cout << "Number of rounds must be greater than 0. Please enter again: ";
        cin >> rounds;
    }
    if(!cin)
    {
        cout << "Invalid input. Please enter an integer value for rounds: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> rounds;
    }
}
void Game::playRound(Player& player1, Player& player2)
{
    Move player1Move = player1.getMove();
    Move player2Move = player2.getMove();
    this->determineRoundResult(player1, player2, player1Move, player2Move);
}

void Game::playGame(Player& player1, Player& player2)
{
    while (rounds)
    {
        playRound(player1, player2);
        rounds--;
    }
    this->displayGameStats(player1, player2);
}

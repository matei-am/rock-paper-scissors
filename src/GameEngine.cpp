#include <iostream>
#include <sstream>
#include <string>
#include "GameEngine.h"
#include "Move.h"
#include "Player.h"
#include "Human.h"
#include "Computer.h"
using namespace std;

void Game::startGame(Player &player1, Player &player2)
{
    cout << "Welcome to Rock, Paper, Scissors!" << endl;
    cout << "How many rounds would you like to play? ";
    string input;

    while (true)
    {
        cout << "Enter rounds: ";
        getline(cin, input);

        stringstream ss(input);
        char extra;

        if (ss >> rounds && !(ss >> extra) && rounds > 0)
            break;

        cout << "Invalid input. Enter a positive integer.\n";
    }
}
void Game::playRound(Player &player1, Player &player2)
{
    Move player1Move = player1.getMove();
    Move player2Move = player2.getMove();
    this->determineRoundResult(player1, player2, player1Move, player2Move);
}

void Game::playGame(Player &player1, Player &player2)
{
    while (rounds)
    {
        playRound(player1, player2);
        rounds--;
    }
    this->displayGameStats(player1, player2);
}

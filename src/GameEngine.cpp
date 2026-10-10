#include <iostream>
#include <sstream>
#include <string>
#include "GameEngine.h"
#include "GameRules.h"
#include "Player.h"
#include "Human.h"
#include "Computer.h"
using namespace std;

void Game::displayRoundResult(outcome roundResult)
{
    if (roundResult == outcome::WIN)
    {
        cout << "You win!" << endl;
    }
    else if (roundResult == outcome::LOSS)
    {
        cout << "You lose!" << endl;
    }
    else
        cout << "It's a draw!" << endl;
}

void Game::displayGameStats(Player &player1, Player &player2)
{
    string player1Name = player1.getName();
    string player2Name = player2.getName();
    cout << "---------------------------------" << endl;
    Player &winner = (player1.getWinCount() > player2.getWinCount()) ? player1 : player2;
    if (player1.getWinCount() == player2.getWinCount())
    {
        cout << "It's a tie!" << endl;
    }
    else
    {
        cout << "Winner: " << ((&winner == &player1) ? player1Name : player2Name) << endl;
    }
    cout << "---------------------------------" << endl;
    cout << "Out of " << (player1.getWinCount() + player1.getLoseCount() + player1.getDrawCount()) << " rounds:" << endl;
    cout << player1Name << " has " << player1.getWinCount() << " Wins" << endl;
    cout << player1Name << " has " << player1.getLoseCount() << " Losses" << endl;
    cout << player1Name << " has " << player1.getDrawCount() << " Draws" << endl;
    cout << player2Name << " has " << player2.getWinCount() << " Wins" << endl;
    cout << player2Name << " has " << player2.getLoseCount() << " Losses" << endl;
    cout << player2Name << " has " << player2.getDrawCount() << " Draws" << endl;
    cout << "---------------------------------" << endl;
}

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
    this->determineRoundResult(player1, player2);
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

#include <iostream>
#include <sstream>
#include <string>
#include "GameEngine.h"
#include "GameRules.h"
#include "Player.h"
using namespace std;

void Game::startGame()
{
    cout << "Welcome to Rock, Paper, Scissors!" << endl;
    string input;

    while (true)
    {
        cout << "Enter the number of rounds you would like to play: ";
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
    outcome roundResult = Rules::determineOutcome(player1Move, player2Move);
    if (roundResult == outcome::DRAW)
    {
        player1.addDraw();
        player2.addDraw();
    }
    else if (roundResult == outcome::WIN)
    {
        player1.addWin();
        player2.addLoss();
    }
    else
    {
        player1.addLoss();
        player2.addWin();
    }
    displayRoundResult(roundResult, player1, player2);
}

void Game::playGame(Player &player1, Player &player2)
{
    for (int round = 0; round < rounds; ++round)
    {
        playRound(player1, player2);
    }
    this->displayGameStats(player1, player2);
}


void Game::displayRoundResult(outcome roundResult, Player &player1, Player &player2)
{
    if (roundResult == outcome::DRAW)
    {
        cout << endl;
        cout << "It's a draw!" << endl;
        cout << endl;
    }
    else if (roundResult == outcome::WIN)
    {
        cout << endl;
        cout << player1.getName() << " wins this round!" << endl;
        cout << endl;
    }
    else
    {
        cout << endl;
        cout << player2.getName() << " wins this round!" << endl;
        cout << endl;
    }
}

void Game::displayGameStats(Player &player1, Player &player2)
{
    string player1Name = player1.getName();
    string player2Name = player2.getName();
    cout << "---------------------------------" << endl;
    if (player1.getWinCount() == player2.getWinCount())
    {
        cout << "It's a tie!" << endl;
    }
    else
    {
        Player &winner = (player1.getWinCount() > player2.getWinCount()) ? player1 : player2;
        cout << "Winner: " << ((&winner == &player1) ? player1Name : player2Name) << endl;
    }
    cout << "---------------------------------" << endl;
    cout << "Out of " << (player1.getWinCount() + player1.getLossCount() + player1.getDrawCount()) << " rounds:" << endl;
    cout << player1Name << " has " << player1.getWinCount() << " Wins" << endl;
    cout << player1Name << " has " << player1.getLossCount() << " Losses" << endl;
    cout << player1Name << " has " << player1.getDrawCount() << " Draws" << endl;
    cout << player2Name << " has " << player2.getWinCount() << " Wins" << endl;
    cout << player2Name << " has " << player2.getLossCount() << " Losses" << endl;
    cout << player2Name << " has " << player2.getDrawCount() << " Draws" << endl;
    cout << "---------------------------------" << endl;
}
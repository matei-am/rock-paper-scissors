#include <iostream>
#include "GameEngine.h"
#include "Move.h"
#include "Player.h"
using namespace std;

Player player;
Player computer;
Result result;

void Game::startGame()
{
    cout << "Welcome to Rock, Paper, Scissors!" << endl;
    cout << "How many rounds would you like to play? ";
    cin >> rounds;
    player.ResetStats();
}
void Game::playRound()
{
    Move playerMove = player.getPlayerMove();
    Move computerMove = player.getComputerMove();
    outcome gameResult = result.determineResult(playerMove, computerMove);
    if (gameResult == outcome::WIN)
    {
        player.addWin();
    }
    else if (gameResult == outcome::LOSE)
    {
        player.addLose();
    }
    else
    {
        player.addDraw();
    }
    result.displayResult(gameResult);
}

void Game::playGame()
{
    while (rounds)
    {
        playRound();
        rounds--;
    }
    player.displayStats();
}

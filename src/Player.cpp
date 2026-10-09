#include <iostream>
#include "Move.h"
#include "Player.h"
#include "GameEngine.h"
using namespace std;

Move Player::getPlayerMove()
{
    string input;
    cout << "Please enter your move (rock, paper, or scissors): ";
    cin >> input;

    if (input == "rock")
    {
        return Move::ROCK;
    }
    else if (input == "paper")
    {
        return Move::PAPER;
    }
    else if (input == "scissors")
    {
        return Move::SCISSORS;
    }
    else
    {
        cout << "Invalid move. Please try again." << endl;
        return getPlayerMove();
    }
}

Move Player::getComputerMove()
{
    int randomNum = rand() % 3;
    if (randomNum == 0)
    {
        cout<< "Computer chose ROCK"<<endl;
        return Move::ROCK;
    }
    else if (randomNum == 1)
    {
        cout << "Computer chose PAPER" << endl;
        return Move::PAPER;
    }
    else
    {
        cout << "Computer chose SCISSORS" << endl;
        return Move::SCISSORS;
    }
}

outcome Result::determineResult(Move playerMove, Move computerMove)
{
    if (playerMove == computerMove)
    {
        return outcome::DRAW;
    }
    else if ((playerMove == Move::ROCK && computerMove == Move::SCISSORS) ||
             (playerMove == Move::PAPER && computerMove == Move::ROCK) ||
             (playerMove == Move::SCISSORS && computerMove == Move::PAPER))
    {
        return outcome::WIN;
    }
    else
    {
        return outcome::LOSE;
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
void Player::displayStats()
{
    cout << "You have " << winCount << " Wins" << endl;
    cout << "You have " << loseCount << " Losses" << endl;
    cout << "You have " << drawCount << " Draws" << endl;
}
void Player::ResetStats()
{
    winCount = 0;
    loseCount = 0;
    drawCount = 0;
}

void Result::displayResult(outcome gameResult)
{
    if (gameResult == outcome::WIN)
    {
        cout << "You win!" << endl;
    }
    else if (gameResult == outcome::LOSE)
    {
        cout << "You lose!" << endl;
    }
    else
        cout << "It's a draw!" << endl;
}

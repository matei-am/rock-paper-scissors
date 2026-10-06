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

result Result::determineResult(Move playerMove, Move computerMove)
{
    if (playerMove == computerMove)
    {
        return result::DRAW;
    }
    else if ((playerMove == Move::ROCK && computerMove == Move::SCISSORS) ||
             (playerMove == Move::PAPER && computerMove == Move::ROCK) ||
             (playerMove == Move::SCISSORS && computerMove == Move::PAPER))
    {
        return result::WIN;
    }
    else
    {
        return result::LOSE;
    }
}
void Result::displayResult(result gameResult)
{
    if (gameResult == result::WIN)
    {
        cout << "You win!" << endl;
    }
    else if (gameResult == result::LOSE)
    {
        cout << "You lose!" << endl;
    }
    else
        cout << "It's a draw!" << endl;
}

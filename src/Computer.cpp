#include "Computer.h"
#include "Player.h"
#include <iostream>
using namespace std;

Move Computer::getMove()
{
    int randomNum = rand() % 3;
    if (randomNum == 0)
    {
        cout << "Computer chose ROCK" << endl;
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
};
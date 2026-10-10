#include "Computer.h"
#include "Player.h"
#include <iostream>
using namespace std;

Move Computer::getMove() const
{
    int randomNum = rand() % 3;
    if (randomNum == 0)
    {
        cout << endl;
        cout << "Computer chose ROCK" << endl;
        return Move::ROCK;
    }
    else if (randomNum == 1)
    {
        cout << endl;
        cout << "Computer chose PAPER" << endl;
        return Move::PAPER;
    }
    else
    {
        cout << endl;
        cout << "Computer chose SCISSORS" << endl;
        return Move::SCISSORS;
    }
}
void Computer::setName(const std::string &userName)
{
    string name;
    name = "Computer";
}
string Computer::getName() const
{
    return "Computer";
}

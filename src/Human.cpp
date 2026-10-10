#include "Human.h"
#include "Player.h"
#include <iostream>
#include <string>
using namespace std;

Move Human::getMove() const
{
    string input;
    while (true)
    {
        cout << "Please enter your move (rock, paper, or scissors): ";
        cin >> input;

        if (input == "rock")
            return Move::ROCK;
        if (input == "paper")
            return Move::PAPER;
        if (input == "scissors")
            return Move::SCISSORS;

        cout << "Invalid move. Please try again." << endl;
    }
}
void Human::setUserName(const string &userName)
{
    name = userName;
}

string Human::getUserName() const
{
    return name;
}
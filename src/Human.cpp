#include "Human.h"
#include <iostream>
#include <string>
using namespace std;

Move Human::getMove()
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

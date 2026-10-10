#include "Human.h"
#include "Player.h"
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

string Human::getName()
{
    string name;
    cout << "Please enter your name: ";
    cin >> name;
    return name;
}
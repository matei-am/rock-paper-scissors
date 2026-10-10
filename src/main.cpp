#include <iostream>
#include <limits>
#include "GameRules.h"
#include "GameEngine.h"
#include "Player.h"
#include "Human.h"
#include "Computer.h"

using namespace std;

int main() {
    Human human;
    Computer computer;
    Player& player1 = human;
    Player& player2 = computer;
    Game game;
    string userName;
    cout << "Please enter your name: ";
    cin >> userName;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    human.setName(userName);
    game.startGame(player1, player2);
    game.playGame(player1, player2);

    return 0;
}
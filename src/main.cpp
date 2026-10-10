#include "GameRules.h"
#include "GameEngine.h"
#include "Player.h"
#include "Human.h"
#include "Computer.h"

int main() {
    Human human;
    Computer computer;
    Player& player1 = human;
    Player& player2 = computer;
    Game game;
    game.startGame(player1, player2);
    game.playGame(player1, player2);

    return 0;
}
#pragma once
#include "Player.h"
class Game
{
    int rounds = 0;

public:
    void startGame();
    void playRound(Player &player1, Player &player2);
    void playGame(Player &player1, Player &player2);
    void determineRoundResult(Player &player1, Player &player2);
    void displayRoundResult(outcome roundResult, Player &player1, Player &player2);
    void displayGameStats(Player &player1, Player &player2);
};
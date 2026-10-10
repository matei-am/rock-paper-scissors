#pragma once
#include "Player.h"
class Game{
    int rounds;
    public:
    void startGame(Player& player1, Player& player2);
    void playRound(Player& player1, Player& player2);
    void playGame(Player& player1, Player& player2);
    void determineRoundResult(Player& player1, Player& player2);
    void displayRoundResult(outcome roundResult, Player& player1, Player& player2);
    void displayGameStats(Player& player1, Player& player2);
    

};
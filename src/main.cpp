#include <iostream>
#include "Move.h"
#include "GameEngine.h"
#include "Player.h"
using namespace std;

int main() {
    Player player;
    Player computer;

    Move playerMove = player.getPlayerMove();
    Move computerMove = player.getComputerMove();

    Result resultObj;
    result gameResult = resultObj.determineResult(playerMove, computerMove);
    resultObj.displayResult(gameResult);

    return 0;
}
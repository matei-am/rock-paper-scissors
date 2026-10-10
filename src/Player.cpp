#include <iostream>
#include "GameRules.h"
#include "Player.h"
#include "GameEngine.h"
using namespace std;




void Player::addWin()
{
    winCount++;
}
void Player::addLose()
{
    loseCount++;
}
void Player::addDraw()
{
    drawCount++;
}
int Player::getWinCount()
{
    return winCount;
}

int Player::getLoseCount()
{
    return loseCount;
}

int Player::getDrawCount()
{
    return drawCount;
}


#include "Player.h"
using namespace std;




void Player::addWin()
{
    winCount++;
}
void Player::addLoss()
{
    lossCount++;
}
void Player::addDraw()
{
    drawCount++;
}
int Player::getWinCount() const
{
    return winCount;
}

int Player::getLossCount() const
{
    return lossCount;
}

int Player::getDrawCount() const
{
    return drawCount;
}


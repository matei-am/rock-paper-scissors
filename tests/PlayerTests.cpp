#include <gtest/gtest.h>
#include "Player.h"
using namespace std;

class TestPlayer : public Player
{
public:
    Move getMove() override
    {
        return Move::ROCK;
    }
    string getName() const override
    {
        return "Test Player";
    }
};
class AnotherTestPlayer : public Player
{
public:
    Move getMove() override
    {
        return Move::PAPER;
    }
    string getName() const override
    {
        return "Test Player 2";
    }
};

TEST(PlayerTests, ScoreStartsAtZero)
{
    TestPlayer player;
    EXPECT_EQ(player.getWinCount(), 0);
    EXPECT_EQ(player.getLossCount(), 0);
    EXPECT_EQ(player.getDrawCount(), 0);
}

TEST(PlayerTests, CanIncrementWinCount)
{
    TestPlayer player;
    player.addWin();
    EXPECT_EQ(player.getWinCount(), 1);
    EXPECT_EQ(player.getLossCount(), 0);
    EXPECT_EQ(player.getDrawCount(), 0);
}

TEST(PlayerTests, CanIncrementLossCount)
{
    TestPlayer player;
    player.addLoss();
    EXPECT_EQ(player.getWinCount(), 0);
    EXPECT_EQ(player.getLossCount(), 1);
    EXPECT_EQ(player.getDrawCount(), 0);
}

TEST(PlayerTests, CanIncrementDrawCount)
{
    TestPlayer player;
    player.addDraw();
    EXPECT_EQ(player.getWinCount(), 0);
    EXPECT_EQ(player.getLossCount(), 0);
    EXPECT_EQ(player.getDrawCount(), 1);
}

TEST(PlayerTests, CanIncrementAllCounts)
{
    TestPlayer player;
    player.addWin();
    player.addLoss();
    player.addDraw();
    EXPECT_EQ(player.getWinCount(), 1);
    EXPECT_EQ(player.getLossCount(), 1);
    EXPECT_EQ(player.getDrawCount(), 1);
}

TEST(PlayerTests, DifferentPlayersHaveDifferentScores)
{
    TestPlayer player1;
    TestPlayer player2;
    player1.addWin();
    player2.addLoss();
    EXPECT_EQ(player1.getWinCount(), 1);
    EXPECT_EQ(player2.getWinCount(), 0);
    EXPECT_EQ(player1.getLossCount(), 0);
    EXPECT_EQ(player2.getLossCount(), 1);
}

TEST(PlayerTests, GetNameReturnsCorrectName)
{
    TestPlayer player;
    EXPECT_EQ(player.getName(), "Test Player");
}

TEST(PlayerTests, DifferentPlayersHaveDifferentNames)
{
    TestPlayer player1;
    AnotherTestPlayer player2;
    EXPECT_EQ(player1.getName(), "Test Player");
    EXPECT_EQ(player2.getName(), "Test Player 2");
}
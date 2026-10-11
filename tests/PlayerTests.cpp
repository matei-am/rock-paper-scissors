#include <gtest/gtest.h>
#include "Player.h"
#include "TestPlayer.h"
#include "TestComputer.h"
#include "Computer.h"
#include "HumanTestPlayer.h"
#include "Human.h"
using namespace std;


Move TestPlayer::getMove()
{
    return Move::ROCK;
}
string TestPlayer::getName() const
{
    return "Test Player";
}
Move TestComputer::getMove()
{
    return move;
}
string TestComputer::getName() const
{
    return "Computer";
}
Move HumanTestPlayer::getMove()
{
    return move;
}
string HumanTestPlayer::getName() const
{
    return name;
}


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
    HumanTestPlayer player1("Test Player", Move::ROCK);
    HumanTestPlayer player2("Test Player 2", Move::PAPER);
    EXPECT_EQ(player1.getName(), "Test Player");
    EXPECT_EQ(player2.getName(), "Test Player 2");
}

TEST(PlayerTests, ComputerPlayerReturnsRandomMove)
{
    Computer computer;

    Move move = computer.getMove();

    EXPECT_TRUE(
        move == Move::ROCK ||
        move == Move::PAPER ||
        move == Move::SCISSORS
    );
}

TEST(PlayerTests, OutputMatchesReturnedMove)
{
    Computer computer;

    testing::internal::CaptureStdout();

    Move move = computer.getMove();

    string output = testing::internal::GetCapturedStdout();

    if (move == Move::ROCK)
    {
        EXPECT_NE(output.find("Computer chose ROCK"), string::npos);
    }
    else if (move == Move::PAPER)
    {
        EXPECT_NE(output.find("Computer chose PAPER"), string::npos);
    }
    else if (move == Move::SCISSORS)
    {
        EXPECT_NE(output.find("Computer chose SCISSORS"), string::npos);
    }
}

TEST(PlayerTests, ComputerPlayerReturnsCorrectName)
{
    Computer computer;
    EXPECT_EQ(computer.getName(), "Computer");
}

TEST(PlayerTests, HumanSetsNameCorrectly)
{
    Human human;
    human.setName("Test Human");
    EXPECT_EQ(human.getName(), "Test Human");
}

TEST(HumanTest, ReturnsRock)
{
    Human human;

    istringstream input("rock\n");
    streambuf* originalInput = cin.rdbuf(input.rdbuf());

    Move move = human.getMove();

    cin.rdbuf(originalInput);

    EXPECT_EQ(move, Move::ROCK);
}

TEST(HumanTest, ReturnsPaper)
{
    Human human;

    istringstream input("paper\n");
    streambuf* originalInput = cin.rdbuf(input.rdbuf());

    Move move = human.getMove();

    cin.rdbuf(originalInput);

    EXPECT_EQ(move, Move::PAPER);
}

TEST(HumanTest, ReturnsScissors)
{
    Human human;

    istringstream input("scissors\n");
    streambuf* originalInput = cin.rdbuf(input.rdbuf());

    Move move = human.getMove();

    cin.rdbuf(originalInput);

    EXPECT_EQ(move, Move::SCISSORS);
}
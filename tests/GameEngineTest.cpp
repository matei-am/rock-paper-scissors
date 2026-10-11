#include <gtest/gtest.h>

#include "RunGame.h"
#include "Human.h"
#include "Computer.h"
#include "GameEngine.h"
#include "TestPlayer.h"
#include "TestComputer.h"
#include "HumanTestPlayer.h"

#include <iostream>
#include <sstream>
#include <string>
using namespace std;
TEST(GameEngineTests, RoundWinUpdatesBothPlayersScores)
{
    Game game;
    HumanTestPlayer human("Human", Move::PAPER);
    TestComputer computer(Move::ROCK);

    game.playRound(human, computer);

    EXPECT_EQ(human.getWinCount(), 1);
    EXPECT_EQ(computer.getLossCount(), 1);
    EXPECT_EQ(human.getLossCount(), 0);
    EXPECT_EQ(computer.getWinCount(), 0);
}

TEST(GameEngineTests, RoundLoseUpdatesBothPlayersScores)
{
    Game game;
    HumanTestPlayer human("Human", Move::SCISSORS);
    TestComputer computer(Move::ROCK);

    game.playRound(human, computer);

    EXPECT_EQ(human.getDrawCount(), 0);
    EXPECT_EQ(computer.getDrawCount(), 0);
    EXPECT_EQ(human.getWinCount(), 0);
    EXPECT_EQ(computer.getWinCount(), 1);
    EXPECT_EQ(human.getLossCount(), 1);
    EXPECT_EQ(computer.getLossCount(), 0);
}

TEST(GameEngineTests, RoundDrawUpdatesBothPlayersScores)
{
    Game game;
    HumanTestPlayer human("Human", Move::ROCK);
    TestComputer computer(Move::ROCK);

    game.playRound(human, computer);

    EXPECT_EQ(human.getDrawCount(), 1);
    EXPECT_EQ(computer.getDrawCount(), 1);
    EXPECT_EQ(human.getWinCount(), 0);
    EXPECT_EQ(computer.getWinCount(), 0);
    EXPECT_EQ(human.getLossCount(), 0);
    EXPECT_EQ(computer.getLossCount(), 0);
}

TEST(GameEngineTests, DisplayRoundResultWin)
{
    Game game;
    HumanTestPlayer human("Human", Move::ROCK);
    TestComputer computer(Move::SCISSORS);
    outcome roundResult = outcome::WIN;
    testing::internal::CaptureStdout();
    game.displayRoundResult(roundResult, human, computer);
    string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("\nHuman wins this round!\n"), string::npos);
}

TEST(GameEngineTests, DisplayRoundResultLose)
{
    Game game;
    HumanTestPlayer human("Human", Move::ROCK);
    TestComputer computer(Move::PAPER);
    outcome roundResult = outcome::LOSS;
    testing::internal::CaptureStdout();
    game.displayRoundResult(roundResult, human, computer);
    string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("\nComputer wins this round!\n"), string::npos);
}

TEST(GameEngineTests, DisplayRoundResultDraw)
{
    Game game;
    HumanTestPlayer human("Human", Move::ROCK);
    TestComputer computer(Move::ROCK);
    outcome roundResult = outcome::DRAW;
    testing::internal::CaptureStdout();
    game.displayRoundResult(roundResult, human, computer);
    string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("\nIt's a draw!\n"), string::npos);
}

TEST(GameEngineTests, GameStatsDisplayCorrectly)
{
    Game game;
    HumanTestPlayer human("Human", Move::ROCK);
    TestComputer computer(Move::SCISSORS);

    game.playRound(human, computer);

    testing::internal::CaptureStdout();
    game.displayGameStats(human, computer);
    string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("---------------------------------\n"), string::npos);
    EXPECT_NE(output.find("Winner: Human\n"), string::npos);
    EXPECT_NE(output.find("---------------------------------\n"), string::npos);
    EXPECT_NE(output.find("Human has 1 Wins\nHuman has 0 Losses\nHuman has 0 Draws\n"), string::npos);
    EXPECT_NE(output.find("Computer has 0 Wins\nComputer has 1 Losses\nComputer has 0 Draws\n"), string::npos);
}

TEST(GameEngineTests, PromptsForUserName)
{
    istringstream input("John\n1\nrock\n");
    streambuf *originalInput = cin.rdbuf(input.rdbuf());
    testing::internal::CaptureStdout();

    int result = runGame();

    string output = testing::internal::GetCapturedStdout();
    cin.rdbuf(originalInput);

    EXPECT_NE(output.find("Please enter your name: "), string::npos);
    EXPECT_EQ(result, 0);
}
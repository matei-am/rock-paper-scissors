/*
#include <gtest/gtest.h>
#include "GameEngine.h"
#include "Player.h"
#include "Move.h"
#include "Human.h"
#include "Computer.h"
using namespace std;

TEST(PlayerTest, AddWinIncrementsWinCount)
{
    Human human;
    human.addWin();
    EXPECT_EQ(human.getWinCount(), 1);
}

TEST(PlayerTest, AddLoseIncrementsLoseCount)
{
    Human human;
    human.addLose();
    EXPECT_EQ(human.getLoseCount(), 1);
}

TEST(PlayerTest, AddDrawIncrementsDrawCount)
{
    Human human;
    human.addDraw();
    EXPECT_EQ(human.getDrawCount(), 1);
}

TEST(PlayerTest, CheckStatsDisplay)
{
    Human human;
    human.addWin();
    human.addLose();
    human.addDraw();
    testing::internal::CaptureStdout();
    human.displayStats();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "You have 1 Wins\nYou have 1 Losses\nYou have 1 Draws\n");
}

TEST(PlayerTest, InitialWinCountIsZero)
{
    Human human;
    EXPECT_EQ(human.getWinCount(), 0);
}

TEST(PlayerTest, InitialLoseCountIsZero)
{
    Human human;
    EXPECT_EQ(human.getLoseCount(), 0);
}

TEST(PlayerTest, InitialDrawCountIsZero)
{
    Human human;
    EXPECT_EQ(human.getDrawCount(), 0);
}

TEST(PlayerTest, ComputerMoveIsSetCorrectly)
{
    Computer computer;
    Move computerMove = computer.getMove();
    EXPECT_TRUE(computerMove == Move::ROCK || computerMove == Move::PAPER || computerMove == Move::SCISSORS);
}


TEST(PlayerTest, StatsAreDisplayedCorrectly)
{
    Player player;
    player.addWin();
    player.addLose();
    player.addDraw();
    testing::internal::CaptureStdout();
    player.displayStats();
    string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "You have 1 Wins\nYou have 1 Losses\nYou have 1 Draws\n");
}

TEST(ResultTest, ResultIsCorrect)
{
    Move move1 = Move::ROCK;
    Move move2 = Move::SCISSORS;
    Result gameResult;
    outcome result = gameResult.determineResult(move1, move2);
    EXPECT_EQ(result, outcome::WIN);
}

TEST(ResultTest, ResultIsCorrect2)
{
    Move move1 = Move::PAPER;
    Move move2 = Move::SCISSORS;
    Result gameResult;
    outcome result = gameResult.determineResult(move1, move2);
    EXPECT_EQ(result, outcome::LOSE);
}

TEST(ResultTest, ResultIsCorrect3)
{
    Move move1 = Move::ROCK;
    Move move2 = Move::PAPER;
    Result gameResult;
    outcome result = gameResult.determineResult(move1, move2);
    EXPECT_EQ(result, outcome::LOSE);
}

TEST(ResultTest, IsDraw)
{
    int randomMove = rand() % 3;
    Move move1;
    if (randomMove == 1)
    {
        move1 = Move::ROCK;
    }
    else if (randomMove == 2)
    {
        move1 = Move::SCISSORS;
    }
    else
        move1 = Move::PAPER;
    {
        Move move2 = move1;
        Result gameResult;
        outcome result = gameResult.determineResult(move1, move2);
        EXPECT_EQ(result, outcome::DRAW);
    }
}

TEST(ResultTest, DisplayResultWin)
{
    Move move1 = Move::ROCK;
    Move move2 = Move::SCISSORS;
    Result gameResult;
    outcome result = gameResult.determineResult(move1, move2);
    testing::internal::CaptureStdout();
    gameResult.displayResult(result);
    string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "You win!\n");
}

TEST(ResultTest, DisplayResultLose)
{
    Move move1 = Move::ROCK;
    Move move2 = Move::PAPER;
    Result gameResult;
    outcome result = gameResult.determineResult(move1, move2);
    testing::internal::CaptureStdout();
    gameResult.displayResult(result);
    string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "You lose!\n");
}

TEST(ResultTest, DisplayResultDraw)
{
    Move move1 = Move::ROCK;
    Move move2 = Move::ROCK;
    Result gameResult;
    outcome result = gameResult.determineResult(move1, move2);
    testing::internal::CaptureStdout();
    gameResult.displayResult(result);
    string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "It's a draw!\n");
}

TEST(GameEngineTest, CanStartGame)
{
    Game game;
    std::istringstream input("1\n");
    std::streambuf* originalInput = std::cin.rdbuf(input.rdbuf());

    testing::internal::CaptureStdout();
    game.startGame();
    std::string output = testing::internal::GetCapturedStdout();

    std::cin.rdbuf(originalInput);

    EXPECT_EQ(
        output,
        "Welcome to Rock, Paper, Scissors!\n"
        "How many rounds would you like to play? ");
}

TEST(GameTest, CanPlayRound)
{
    Game game;
    std::istringstream input("rock\n");
    std::streambuf* originalInput = std::cin.rdbuf(input.rdbuf());

    testing::internal::CaptureStdout();
    game.playRound();
    std::string output = testing::internal::GetCapturedStdout();

    std::cin.rdbuf(originalInput);

    EXPECT_NE(output.find("Please enter your move"), std::string::npos);
    EXPECT_NE(output.find("Computer chose"), std::string::npos);

    const bool hasResult =
        output.find("You win!") != std::string::npos ||
        output.find("You lose!") != std::string::npos ||
        output.find("It's a draw!") != std::string::npos;

    EXPECT_TRUE(hasResult);
}

TEST(GameTest, CanPlayGameWithZeroRoundsDisplaysEmptyStats)
{
    Game game;
    std::istringstream input("0\n");
    std::streambuf* originalInput = std::cin.rdbuf(input.rdbuf());

    testing::internal::CaptureStdout();
    game.startGame();
    game.playGame();
    std::string output = testing::internal::GetCapturedStdout();

    std::cin.rdbuf(originalInput);

    EXPECT_EQ(
        output,
        "Welcome to Rock, Paper, Scissors!\n"
        "How many rounds would you like to play? "
        "You have 0 Wins\n"
        "You have 0 Losses\n"
        "You have 0 Draws\n");
}

TEST(GameTest, CanPlayGamePlaysRequestedRoundAndDisplaysStats)
{
    Game game;
    std::istringstream input("1\nrock\n");
    std::streambuf* originalInput = std::cin.rdbuf(input.rdbuf());

    testing::internal::CaptureStdout();
    game.startGame();
    game.playGame();
    std::string output = testing::internal::GetCapturedStdout();

    std::cin.rdbuf(originalInput);

    EXPECT_NE(output.find("Please enter your move"), std::string::npos);
    EXPECT_NE(output.find("Computer chose"), std::string::npos);

    EXPECT_NE(output.find("You have "), std::string::npos);
    EXPECT_NE(output.find(" Wins\n"), std::string::npos);
    EXPECT_NE(output.find(" Losses\n"), std::string::npos);
    EXPECT_NE(output.find(" Draws\n"), std::string::npos);
}
    */
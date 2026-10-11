#include <gtest/gtest.h>
#include "GameRules.h"

TEST(GameRulesTests, RockBeatsScissors)
{
    EXPECT_EQ(
        Rules::determineOutcome(Move::ROCK, Move::SCISSORS),
        outcome::WIN
    );
}

TEST(GameRulesTests, RockLosesToPaper)
{
    EXPECT_EQ(
        Rules::determineOutcome(Move::ROCK, Move::PAPER),
        outcome::LOSS
    );
}

TEST(GameRulesTests, RockAgainstRockIsDraw)
{
    EXPECT_EQ(
        Rules::determineOutcome(Move::ROCK, Move::ROCK),
        outcome::DRAW
    );
}

TEST(GameRulesTests, PaperBeatsRock)
{
    EXPECT_EQ(
        Rules::determineOutcome(Move::PAPER, Move::ROCK),
        outcome::WIN
    );
}

TEST(GameRulesTests, PaperLosesToScissors)
{
    EXPECT_EQ(
        Rules::determineOutcome(Move::PAPER, Move::SCISSORS),
        outcome::LOSS
    );
}

TEST(GameRulesTests, PaperAgainstPaperIsDraw)
{
    EXPECT_EQ(
        Rules::determineOutcome(Move::PAPER, Move::PAPER),
        outcome::DRAW
    );
}

TEST(GameRulesTests, ScissorsBeatsPaper)
{
    EXPECT_EQ(
        Rules::determineOutcome(Move::SCISSORS, Move::PAPER),
        outcome::WIN
    );
}

TEST(GameRulesTests, ScissorsLosesToRock)
{
    EXPECT_EQ(
        Rules::determineOutcome(Move::SCISSORS, Move::ROCK),
        outcome::LOSS
    );
}

TEST(GameRulesTests, ScissorsAgainstScissorsIsDraw)
{
    EXPECT_EQ(
        Rules::determineOutcome(Move::SCISSORS, Move::SCISSORS),
        outcome::DRAW
    );
}
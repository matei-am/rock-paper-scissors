#include <gtest/gtest.h>
#include "GameEngine.h"
#include "Player.h"
#include "Move.h"

TEST(PlayerTest, AddWinIncrementsWinCount) {
    Player player;
    player.addWin();
    EXPECT_EQ(player.getWinCount(), 1);
    
}
TEST(PlayerTest, AddLoseIncrementsLoseCount) {
    Player player;
    player.addLose();
    EXPECT_EQ(player.getLoseCount(), 1);
}
TEST(PlayerTest, AddDrawIncrementsDrawCount){
    Player player;
    player.addDraw();
    EXPECT_EQ(player.getDrawCount(),1);
}

TEST(PlayerTest, CheckStatsDisplay){
    Player player;
    player.addWin();
    player.addLose();
    player.addDraw();
    testing::internal::CaptureStdout();
    player.displayStats();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "You have 1 Wins\nYou have 1 Losses\nYou have 1 Draws\n");
}
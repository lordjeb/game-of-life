#include "pch.h"
#include <GameOfLife.h>

class GameOfLifeTests : public ::testing::Test
{
protected:
    GameOfLife game{ 300, 200 };
};

TEST_F(GameOfLifeTests, Retains_constructed_size)
{
    ASSERT_THAT(game.GetHeight(), ::testing::Eq(300));
    ASSERT_THAT(game.GetWidth(), ::testing::Eq(200));
}

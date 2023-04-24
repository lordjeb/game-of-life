#include "pch.h"
#include <GameOfLife.h>

class GameOfLifeTests : public ::testing::Test
{
protected:
    GameOfLife game;
};

TEST_F(GameOfLifeTests, MyTest)
{
    ASSERT_THAT(true, ::testing::IsTrue());
}

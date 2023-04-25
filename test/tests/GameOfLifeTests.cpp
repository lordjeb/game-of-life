#include "pch.h"
#include <GameOfLife.h>

constexpr const int GAME_HEIGHT = 10;
constexpr const int GAME_WIDTH = 10;

class GameOfLifeTests : public ::testing::Test
{
public:
    GameOfLifeTests() = default;
    ~GameOfLifeTests() = default;

protected:
    GameOfLife game{ GAME_WIDTH, GAME_HEIGHT };
};

TEST_F(GameOfLifeTests, Retains_constructed_size)
{
    ASSERT_THAT(game.GetHeight(), ::testing::Eq(GAME_HEIGHT));
    ASSERT_THAT(game.GetWidth(), ::testing::Eq(GAME_WIDTH));
}

//TEST_F(GameOfLifeTests, Retains_constructed_size)
//{
//    ASSERT_THAT(game.GetHeight(), ::testing::Eq(GAME_HEIGHT));
//    ASSERT_THAT(game.GetWidth(), ::testing::Eq(GAME_WIDTH));
//}

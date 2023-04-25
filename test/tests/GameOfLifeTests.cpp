#include "pch.h"
#include <GameOfLife.h>

constexpr const int GAME_HEIGHT = 10;
constexpr const int GAME_WIDTH = 10;

using ::testing::Eq;

class GameOfLifeTests : public ::testing::Test
{
protected:
    GameOfLife game{ GAME_WIDTH, GAME_HEIGHT };
};

TEST_F(GameOfLifeTests, Ctor_retains_size)
{
    ASSERT_THAT(game.GetHeight(), Eq(GAME_HEIGHT));
    ASSERT_THAT(game.GetWidth(), Eq(GAME_WIDTH));
}

TEST_F(GameOfLifeTests, GetGeneration_starts_at_zero)
{
    ASSERT_THAT(game.GetGeneration(), Eq(0));
}

TEST_F(GameOfLifeTests, Generate_increases_generation)
{
    game.Generate();
    ASSERT_THAT(game.GetGeneration(), Eq(1));
}

TEST_F(GameOfLifeTests, Generate_living_cell_with_no_neighbors_dies)
{
    game.SetCell(5, 5, true);
    game.Generate();
    ASSERT_THAT(game.GetCell(5, 5), Eq(false));
}

TEST_F(GameOfLifeTests, Generate_living_cell_with_one_neighbor_dies)
{
    game.SetCell(4, 4, true);
    game.SetCell(5, 5, true);
    game.Generate();
    ASSERT_THAT(game.GetCell(5, 5), Eq(false));
}

 TEST_F(GameOfLifeTests, Generate_living_cell_with_two_neighbors_lives)
{
     game.SetCell(4, 4, true);
     game.SetCell(4, 5, true);
     game.SetCell(5, 5, true);
     game.Generate();
     ASSERT_THAT(game.GetCell(5, 5), Eq(true));
 }

TEST_F(GameOfLifeTests, Generate_block_is_still_life)
{
     game.SetCell(4, 4, true);
     game.SetCell(4, 5, true);
     game.SetCell(5, 4, true);
     game.SetCell(5, 5, true);
     game.Generate();
     ASSERT_THAT(game.GetCell(4, 4), Eq(true));
     ASSERT_THAT(game.GetCell(4, 5), Eq(true));
     ASSERT_THAT(game.GetCell(5, 4), Eq(true));
     ASSERT_THAT(game.GetCell(5, 5), Eq(true));
}

TEST_F(GameOfLifeTests, Generate_blinker_is_oscillator)
{
     game.SetCell(5, 4, true);
     game.SetCell(5, 5, true);
     game.SetCell(5, 6, true);

     game.Generate();
     ASSERT_THAT(game.GetCell(4, 5), Eq(true));
     ASSERT_THAT(game.GetCell(5, 5), Eq(true));
     ASSERT_THAT(game.GetCell(6, 5), Eq(true));

     game.Generate();
     ASSERT_THAT(game.GetCell(5, 4), Eq(true));
     ASSERT_THAT(game.GetCell(5, 5), Eq(true));
     ASSERT_THAT(game.GetCell(5, 6), Eq(true));
}

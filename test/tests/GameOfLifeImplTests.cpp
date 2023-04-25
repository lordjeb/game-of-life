#include "pch.h"
#include <GameOfLifeImpl.h>

constexpr const int GAME_HEIGHT = 10;
constexpr const int GAME_WIDTH = 10;

using ::testing::Eq;

class GameOfLifeImplTests : public ::testing::Test
{
protected:
    // clang-format off
    std::vector<std::vector<bool>> cells{
    // y =  0      1      2      3      4      5      6      7      8      9
        { true,  true,  false, false, false, false, false, false, false, true  },  // x = 0
        { true,  true,  false, false, false, false, false, false, false, true  },  // x = 1
        { false, false, false, false, false, false, false, false, false, true  },  // x = 2
        { false, false, false, false, false, false, false, false, false, false },  // x = 3
        { false, false, false, false, true,  true,  true,  false, false, false },  // x = 4
        { false, false, false, false, true,  true,  true,  false, false, false },  // x = 5
        { false, false, false, false, true,  true,  true,  false, false, false },  // x = 6
        { false, false, true,  false, false, false, false, false, false, false },  // x = 7
        { false, false, false, false, false, false, false, false, true,  true  },  // x = 8
        { true,  true,  true,  false, false, false, false, false, true,  true  }   // x = 9
    };
    // clang-format on
};

TEST_F(GameOfLifeImplTests, CountLivingNeighbors_does_not_count_self)
{
    ASSERT_THAT(GameOfLifeImpl::CountLivingNeighbors(cells, 7, 2), Eq(0));
}

TEST_F(GameOfLifeImplTests, CountLivingNeighbors_counts_all_neighbors)
{
    ASSERT_THAT(GameOfLifeImpl::CountLivingNeighbors(cells, 5, 5), Eq(8));
}

TEST_F(GameOfLifeImplTests, CountLivingNeighbors_honors_lower_edges)
{
    ASSERT_THAT(GameOfLifeImpl::CountLivingNeighbors(cells, 0, 0), Eq(3));
}

TEST_F(GameOfLifeImplTests, CountLivingNeighbors_honors_upper_edges)
{
    ASSERT_THAT(GameOfLifeImpl::CountLivingNeighbors(cells, 9, 9), Eq(3));
}

TEST_F(GameOfLifeImplTests, CountLivingNeighbors_honors_upper_x_dimension)
{
    ASSERT_THAT(GameOfLifeImpl::CountLivingNeighbors(cells, 9, 1), Eq(2));
}

TEST_F(GameOfLifeImplTests, CountLivingNeighbors_honors_upper_y_dimension)
{
    ASSERT_THAT(GameOfLifeImpl::CountLivingNeighbors(cells, 1, 9), Eq(2));
}

TEST_F(GameOfLifeImplTests, GetFateOfCell_alive_with_two_neighbors_lives)
{
    ASSERT_THAT(GameOfLifeImpl::GetFateOfCell(cells, 9, 1), Eq(true));
    ASSERT_THAT(GameOfLifeImpl::GetFateOfCell(cells, 1, 9), Eq(true));
}

TEST_F(GameOfLifeImplTests, GetFateOfCell_alive_with_three_neighbors_lives)
{
    ASSERT_THAT(GameOfLifeImpl::GetFateOfCell(cells, 0, 0), Eq(true));
}

TEST_F(GameOfLifeImplTests, GetFateOfCell_alive_with_more_than_three_neighbors_dies)
{
    ASSERT_THAT(GameOfLifeImpl::GetFateOfCell(cells, 5, 5), Eq(false));
}

TEST_F(GameOfLifeImplTests, GetFateOfCell_alive_with_zero_neighbors_dies)
{
    ASSERT_THAT(GameOfLifeImpl::GetFateOfCell(cells, 7, 2), Eq(false));
}

TEST_F(GameOfLifeImplTests, GetFateOfCell_dead_with_three_neighbors_lives)
{
    ASSERT_THAT(GameOfLifeImpl::GetFateOfCell(cells, 5, 3), Eq(true));
}

TEST_F(GameOfLifeImplTests, GetFateOfCell_dead_with_two_neighbors_dies)
{
    ASSERT_THAT(GameOfLifeImpl::GetFateOfCell(cells, 9, 7), Eq(false));
}

TEST_F(GameOfLifeImplTests, GetFateOfCell_dead_with_no_neighbors_dies)
{
    ASSERT_THAT(GameOfLifeImpl::GetFateOfCell(cells, 0, 4), Eq(false));
}

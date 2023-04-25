#include "pch.h"
#include "GameOfLifeImpl.h"
#include <iterator>
#include <algorithm>

int GameOfLifeImpl::CountLivingNeighbors(const std::vector<std::vector<bool>>& cells, const int x, const int y)
{
    int neighbors{ 0 };
    for (int i = std::max(0, x - 1); i < std::min(static_cast<int>(cells.size()), x + 2); i++)
    {
        for (int j = std::max(0, y - 1); j < std::min(static_cast<int>(cells[i].size()), y + 2); j++)
        {
            if ((i != x || j != y) && cells[i][j])
            {
                neighbors++;
            }
        }
    }
    return neighbors;
}

bool GameOfLifeImpl::GetFateOfCell(const std::vector<std::vector<bool>>& cells, const int x, const int y)
{
    auto neighbors = CountLivingNeighbors(cells, x, y);
    auto alive = cells[x][y];

    if (alive && (neighbors == 2 || neighbors == 3))
    {
        return true;
    }
    else if (!alive && neighbors == 3)
    {
        return true;
    }

    return false;
}

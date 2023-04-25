#pragma once
#include <vector>

class GameOfLifeImpl
{
public:
    static int CountLivingNeighbors(const std::vector<std::vector<bool>>& cells, const int x, const int y);
    static bool GetFateOfCell(const std::vector<std::vector<bool>>& cells, const int x, const int y);
};

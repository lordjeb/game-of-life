#include "pch.h"
#include "GameOfLife.h"
#include <iterator>
#include <algorithm>

GameOfLife::GameOfLife(int width, int height) : cells_(width, std::vector(height, false)), height_{ height }, width_{ width }
{
}

void GameOfLife::Generate()
{
    // TODO: Actually generate the next generation following the rules...
    // 
    //std::vector<std::vector<bool>> next_generation(width_, std::vector(height_, false));

    // Make a copy and then move it back to simulate
    generation_++;
    auto next_generation = cells_;
    cells_ = std::move(next_generation);
}

bool GameOfLife::GetCell([[maybe_unused]] int x, [[maybe_unused]] int y) const
{
    return cells_[x][y];
}

int GameOfLife::GetGeneration() const
{
    return generation_;
}

int GameOfLife::GetHeight() const
{
    return height_;
}

int GameOfLife::GetWidth() const
{
    return width_;
}

void GameOfLife::SetCell(int x, int y, bool alive)
{
    cells_[x][y] = alive;
}

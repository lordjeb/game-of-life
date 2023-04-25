#include "pch.h"
#include "GameOfLife.h"
#include "GameOfLifeImpl.h"
#include <algorithm>
#include <iterator>

GameOfLife::GameOfLife(int width, int height)
    : cells_(width, std::vector(height, false)), height_{ height }, width_{ width }
{
}

void GameOfLife::Clear()
{
    cells_ = std::move(std::vector<std::vector<bool>>(width_, std::vector(height_, false)));
}

void GameOfLife::Generate()
{
    generation_++;

    std::vector<std::vector<bool>> next_generation(width_, std::vector(height_, false));

    for (int x = 0; x < width_; x++)
    {
        for (int y = 0; y < height_; y++)
        {
            next_generation[x][y] = GameOfLifeImpl::GetFateOfCell(cells_, x, y);
        }
    }

    cells_ = std::move(next_generation);
}

bool GameOfLife::GetCell(int x, int y) const
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

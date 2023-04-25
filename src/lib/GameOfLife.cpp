#include "pch.h"
#include "GameOfLife.h"

GameOfLife::GameOfLife(int height, int width) : height_{ height }, width_{ width }
{
}

int GameOfLife::GetHeight() const
{
    return height_;
}

int GameOfLife::GetWidth() const
{
    return width_;
}

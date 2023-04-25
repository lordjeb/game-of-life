#pragma once

class GameOfLife
{
public:
    GameOfLife(int height, int width);

    int GetHeight() const;
    int GetWidth() const;

protected:
    const int height_;
    const int width_;
};
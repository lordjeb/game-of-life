#pragma once
#include <vector>

class GameOfLife
{
public:
    GameOfLife(int height, int width);
    ~GameOfLife() = default;

    void Generate();
    bool GetCell(int x, int y) const;
    int GetGeneration() const;
    int GetHeight() const;
    int GetWidth() const;
    void SetCell(int x, int y, bool alive);

protected:
    std::vector<std::vector<bool>> cells_;
    int generation_{ 0 };
    const int height_;
    const int width_;
};
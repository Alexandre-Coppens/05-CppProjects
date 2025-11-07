#pragma once
#include <vector>
#include "Vec2i.h"

class Grid
{
private:
    int m_w, m_h;
    std::vector<bool> m_cells;

public:
    Grid(int w, int h);
    bool InBounds(Vec2i c) const;
    bool Walkable(Vec2i c) const;
    void RandomObstacles(unsigned int seed, float density);
    void Draw(int cellSize) const;

    int W() const { return m_w; }
    int H() const { return m_h; }
};

#include "Grid.h"
#include "raylib.h"
#include <cstdlib>

Grid::Grid(int w, int h) :m_w(w), m_h(h), m_cells(w* h, true) {}

bool Grid::InBounds(Vec2i c) const { return c.x >= 0 && c.y >= 0 && c.x < m_w && c.y < m_h; }
bool Grid::Walkable(Vec2i c) const { return InBounds(c) && m_cells[c.y * m_w + c.x]; }

void Grid::RandomObstacles(unsigned int seed, float density)
{
    srand(seed);
    for (int y = 0; y < m_h; y++)
        for (int x = 0; x < m_w; x++)
            if ((float)rand() / RAND_MAX < density)
                m_cells[y * m_w + x] = false;
}

void Grid::Draw(int s) const
{
    for (int y = 0; y < m_h; y++)
    {
        for (int x = 0; x < m_w; x++)
        {
            Vec2i c{ x, y };

            // Walkable cell = light gray
            if (Walkable(c))
            {
                DrawRectangle(x * s, y * s, s, s, Color{ 80,80,80,255 });
            }
            else
            {
                // Blocked cell = dark red
                DrawRectangle(x * s, y * s, s, s, Color{ 120,30,30,255 });
            }

            // Grid line
            DrawRectangleLines(x * s, y * s, s, s, Color{ 40,40,40,255 });
        }
    }
}

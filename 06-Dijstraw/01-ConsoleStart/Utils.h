#pragma once
#include "raylib.h"
#include <cmath>
#include <algorithm>

inline float HeuristicManhattan(Vector2 a, Vector2 b) 
{
    return std::fabs(a.x - b.x) + std::fabs(a.y - b.y);
}
inline float HeuristicEuclidean(Vector2 a, Vector2 b) 
{
    float dx = a.x - b.x, dy = a.y - b.y;
    return std::sqrt(dx * dx + dy * dy);
}
inline float HeuristicDiagonal(Vector2 a, Vector2 b)
{
    // Chebyshev distance (8-voisins)
    return std::max(std::fabs(a.x - b.x), std::fabs(a.y - b.y));
}

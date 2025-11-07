#pragma once
#include <vector>
#include "raylib.h"
#include "Tile.h"

enum class HeuristicType 
{
};

struct PFSettings 
{
};

std::vector<Vector2> ComputePath(std::vector<std::vector<Tile*>>* grid, Tile* startTile);
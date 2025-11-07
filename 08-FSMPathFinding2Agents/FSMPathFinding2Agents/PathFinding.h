#pragma once
#include <vector>
#include "Vec2i.h"
#include "Grid.h"

std::vector<Vec2i> AStar(const Grid& g, Vec2i start, Vec2i goal, bool diag);

#include "Pathfinder.h"
#include "Utils.h"
#include <algorithm>
#include <limits>

std::vector<Vector2> ComputePath(std::vector<std::vector<Tile*>>* grid, Tile* startTile)
{
	std::vector<Tile*> openList;
	std::vector<Tile*> closedList;
	std::vector<Vector2> returnList;
	int nextTile;

	openList.push_back(startTile);

	while (!openList.empty())
	{
		nextTile = 0;
		for (int i = 0; i < openList.size(); i++)
		{
			if (openList[i]->f < openList[nextTile]->f) nextTile = i;
		}

		closedList.push_back(openList[nextTile]);
		openList.erase(openList.begin() + nextTile);

		if (closedList[closedList.size() - 1]->isEnd)
		{
			while(std::count(returnList.begin(), returnList.end(), startTile->position) > -1)
		}
	}

	return std::vector<Vector2>();
}
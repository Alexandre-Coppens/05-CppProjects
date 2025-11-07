#include "PatrolState.h"
#include "MoveState.h"
#include "PathFinding.h"
#include "Grid.h"

void PatrolState::Enter(Agent& a)
{
	a.SetColor(PURPLE);
}

void PatrolState::Update(Agent& a, float dt)
{
	//Try until a walkable cell is obtained
	const Grid* grid = a.GetGrid();
	Vec2i targetCell = a.GetCell();
	while (!grid->Walkable(targetCell) || (a.GetCell().x == targetCell.x && a.GetCell().y == targetCell.y))
	{
		targetCell.x = GetRandomValue(0, grid->W());
		targetCell.y = GetRandomValue(0, grid->H());
	}
	std::vector<Vec2i> path = AStar(*grid, a.GetCell(), targetCell, false);
	//Invert the vector
	std::reverse(path.begin(), path.end());
	a.FSM().ChangeState(a, new MoveState(path));
}

void PatrolState::Exit(Agent& a)
{
}

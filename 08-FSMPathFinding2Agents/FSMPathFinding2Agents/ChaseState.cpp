#include "ChaseState.h"
#include "IdleState.h"

void ChaseState::Enter(Agent& a)
{
	a.SetColor(RED);
}

void ChaseState::Update(Agent& a, float dt)
{
	//Move to the point
	a.SetCell(path[path.size() - 1]);
	path.pop_back();
	if (path.size() == 0)
	{
		a.FSM().ChangeState(a, new IdleState());
	}
}

void ChaseState::Exit(Agent& a)
{
}

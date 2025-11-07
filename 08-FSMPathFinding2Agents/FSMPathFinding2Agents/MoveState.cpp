#include "MoveState.h"
#include "IdleState.h"
#include "SoundAgent.h"
#include <iostream>

void MoveState::Enter(Agent& a)
{
	a.SetColor(GREEN);
}

void MoveState::Update(Agent& a, float dt)
{
	//Move to the point
	a.SetCell(path[path.size()-1]);
	path.pop_back();

	//If it's the sound agent and is moving more than 1 sec -> MakeNoise
	timer -= dt;
	std::cout << timer << " \n";
	if (timer <= 0)
	{
		std::cout << "Finished \n";
		timer = 0.25f;
		SoundAgent* sA = dynamic_cast<SoundAgent*>(&a);
		if (sA != nullptr)
		{
			sA->EmitSound();
		}
	}

	if (path.size() == 0)
	{
		a.FSM().ChangeState(a, new IdleState());
	}
}

void MoveState::Exit(Agent& a)
{
}

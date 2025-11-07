#pragma once

#include "IState.h"
#include <memory>

class StateMachine
{
private:
	std::unique_ptr<IState> currentState;

public:
	void Update(float dt);

	template<typename T>
	void ChangeState(Agent* agent, std::unique_ptr<T> newState)
	{
		if (newState == nullptr) return;
		if (currentState != nullptr)
		{
			currentState->Exit();
		}
		currentState = std::move(newState);
		currentState->SetAgent(agent);
		currentState->Enter();
	}

	std::unique_ptr<IState> GetState();
};
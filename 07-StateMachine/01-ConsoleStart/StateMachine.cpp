#include "StateMachine.h"
#include <iostream>

void StateMachine::Update(float dt)
{
	if (currentState == nullptr) return;
	currentState->Update(dt);
}

std::unique_ptr<IState> StateMachine::GetState()
{
	if (currentState == nullptr) return nullptr;
	return std::move(currentState);
}

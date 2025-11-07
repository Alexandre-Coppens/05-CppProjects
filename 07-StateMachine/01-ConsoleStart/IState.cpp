#include "IState.h"
#include <memory>

void IState::Enter()
{
	return;
}

void IState::Update(float dt)
{
	return;
}

void IState::Exit()
{
	return;
}

void IState::SetAgent(Agent* _agent)
{
	agent = _agent;
}

#pragma once

#include "raylib.h"

#include <vector>

class Agent;

class IState
{
protected:
	Agent* agent;

public:
	virtual ~IState() = default;
	virtual void Enter();
	virtual void Update(float dt);
	virtual void Exit();

	void SetAgent(Agent* _agent);
};


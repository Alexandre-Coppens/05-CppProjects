#pragma once

#include "IState.h"
#include <raymath.h>

class IdleState;
class PatrolState;
class ChaseState;
class AttackState;
class FleeState;

class IdleState : public IState
{
public:
	IdleState() {};
	void Enter() override
	{
		agent->SetColor(BLUE);
	}

	void Update(float dt) override
	{
		if (IsKeyPressed(KEY_P)) agent->ChangeState(std::make_unique<PatrolState>());
		return;
	}

	void Exit() override
	{
		return;
	}
};

class PatrolState : public IState
{
public:
	PatrolState() {};
	void Enter() override
	{
		agent->SetColor(DARKGREEN);
	}

	void Update(float dt) override
	{
		if (IsKeyPressed(KEY_C)) agent->ChangeState(std::make_unique<ChaseState>());
		Vector2 pos = agent->GetPosition();
		agent->SetPosition(Vector2Add(pos, Vector2(sin(GetTime() * 2) * 150 * dt, cos(GetTime() * 2) * 150 * dt)));
	}

	void Exit() override
	{
		return;
	}
};

class ChaseState : public IState
{
public:
	ChaseState() {};
	void Enter() override
	{
		agent->SetColor(ORANGE);
	}

	void Update(float dt) override
	{
		if (IsMouseButtonPressed(0)) agent->ChangeState(std::make_unique<AttackState>());
		Vector2 pos = agent->GetPosition();
		agent->SetPosition(Vector2MoveTowards(pos, GetMousePosition(), 200 * dt));
	}

	void Exit() override
	{
		return;
	}
};

class AttackState : public IState
{
public:
	AttackState() {};
	void Enter() override
	{
		agent->SetColor(RED);
	}

	void Update(float dt) override
	{
		if (IsKeyPressed(KEY_F)) agent->ChangeState(std::make_unique<FleeState>());
		agent->SetColor(ColorLerp(RED, MAROON, (cos(GetTime() * 5 * dt) + 1) * 0.5f));
	}

	void Exit() override
	{
		return;
	}
};

class FleeState : public IState
{
public:
	FleeState() {};
	void Enter() override
	{
		agent->SetColor(GRAY);
	}

	void Update(float dt) override
	{
		if (IsKeyPressed(KEY_I)) agent->ChangeState(std::make_unique<IdleState>());
		Vector2 pos = agent->GetPosition();
		agent->SetPosition(Vector2Add(pos, Vector2Normalize(Vector2(pos.x - GetMousePosition().x, (pos.y - GetMousePosition().y)) * dt * 20)));
	}

	void Exit() override
	{
		return;
	}
};
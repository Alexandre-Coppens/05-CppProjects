#include "Agent.h"

void Agent::Update(float dt)
{
	currenstateMachine.Update(dt);
}

void Agent::Draw()
{
	Rectangle square = Rectangle(position.x, position.y, size.x, size.y);
	DrawRectanglePro(square, Vector2(square.width * 0.5f, square.height * 0.5f), 0, color);
}
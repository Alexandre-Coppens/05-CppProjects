#pragma once

#include "StateMachine.h"
#include <memory>

class Agent
{
private:
	StateMachine currenstateMachine;
	Vector2 position;
	Color color;
	Vector2 size;

public:
	Agent(Vector2 _position, Color _color, Vector2 _size)	:
		position(_position), color(_color), size(_size) {}	;
		
	void Update(float dt);
	void Draw();
	template<typename T>
	void ChangeState(std::unique_ptr<T> state)
	{
		IState* check = dynamic_cast<IState*>(state.get());
		if (check == nullptr) return;
		
		currenstateMachine.ChangeState(this, std::move(state));
	}

	Vector2 GetPosition() { return position; };
	void SetPosition(Vector2 p) { position = p; };

	Vector2 GetSize() { return size; };
	void SetSize(Vector2 s) { size = s; };

	Color GetColor() { return color; };
	void SetColor(Color c) { color = c; };
};
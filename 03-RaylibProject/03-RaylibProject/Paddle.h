#pragma once
#include "raylib.h"
#include "GameObject.h"
#include <string>

using std::string;

class Paddle : public GameObject {
private:
	bool isPlayer;

	Vector2 size;

	float speed;
	Color color;

	KeyboardKey keyUp;
	KeyboardKey keyDown;

public:
	Paddle();
	Paddle(Vector2 _position, Vector2 _size, float _speed, Color _color);
	void AssignKeys(KeyboardKey _keyUp, KeyboardKey _keyDown);

	const inline void SetPlayer() { isPlayer = true; }
	void Update(vector<GameObject*>* objectList) override;
	void Draw() override;

	int KeyHold();
};
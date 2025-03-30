#pragma once
#include "GameObject.h"
#include <string>

using std::string;

class Paddle : public GameObject {
private:
	bool isPlayer;

	Vector2 size;

	float speed;

	KeyboardKey keyUp;
	KeyboardKey keyDown;

	GameObject* ball;

	Texture2D* texture;
	Color color;

public:
	Paddle();
	Paddle(Vector2 _position, Vector2 _size, float _speed, Texture2D* _texture, Color _color);
	void AssignKeys(KeyboardKey _keyUp, KeyboardKey _keyDown);
	void  AssignBall(GameObject* _ball);

	const inline void SetPlayer() { isPlayer = true; }
	const inline void AddSpeed() { speed += 2; }
	void Update(vector<GameObject*>* objectList) override;
	void Draw() override;

	int KeyHold();
};
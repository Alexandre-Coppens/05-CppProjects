#pragma once
#include "GameObject.h"
#include <string>

using std::string;

class Ball : public GameObject{
private:
	float radius;

	Vector2 velocity;
	Color color;

public:
	Ball();
	Ball(Vector2 _position, float _radius, Vector2 _velocity, Color _color);
	~Ball();

	void Update(vector<GameObject*>* objectList) override;
	void Draw() override;

	void CheckCollision(vector<GameObject*>* objectList);
};


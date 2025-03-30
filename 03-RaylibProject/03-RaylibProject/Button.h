#pragma once
#include "GameObject.h"
#include <string>

using std::string;

class Button : public GameObject {
private:
	Vector2 size;

	Color color;

public:
	Button();
	Button(Vector2 _position, Vector2 _size, Color _color);

	void Update(vector<GameObject*>* objectList) override;
	void Draw() override;
};
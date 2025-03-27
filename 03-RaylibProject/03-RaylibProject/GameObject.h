#pragma once
#include "raylib.h"
#include <vector>

using std::vector;

class GameObject {
protected:
	enum class ColliderType {
		Square,
		Circle,
	};

	struct Collider { //SizeX is also used as the radius.
		ColliderType type;
		float sizeX;
		float sizeY;
	};

	Vector2 position;
	Collider collider;

public:
	GameObject();

	virtual void Update(vector<GameObject*>* objectList);
	virtual void Draw();

	const inline Vector2 GetPosition() { return position; }
	const inline Collider GetCollider() { return collider; }
};


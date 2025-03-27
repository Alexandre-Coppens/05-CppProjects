#include "Ball.h"
#include <vector>

using std::vector;

Ball::Ball(){
}

Ball::Ball(Vector2 _position, float _radius, Vector2 _velocity, Color _color){
	position = _position;
	radius = _radius;
	velocity = _velocity;
	color = _color;

	collider = { ColliderType::Circle, radius, 0 };
}

Ball::~Ball(){
}

void Ball::Update(vector<GameObject*>* objectList){
	CheckCollision(objectList);
	position.x += velocity.x;
	position.y += velocity.y;
	return;
}

void Ball::Draw(){
	DrawCircle(position.x, position.y, radius, color);
}

void Ball::CheckCollision(vector<GameObject*>* objectList){
	if (position.x - radius <= 0 || position.x + radius >= GetScreenWidth()) {
		velocity.x = -velocity.x;
	}
	if (position.y - radius <= 0 || position.y + radius >= GetScreenHeight()) {
		velocity.y = -velocity.y;
	}
	for (GameObject* object : *objectList) {
		Collider collider = object->GetCollider();
		switch (collider.type)
		{
		case ColliderType::Square:
			if (position.x + radius > object->GetPosition().x - collider.sizeX * 0.5f &&
				position.x < object->GetPosition().x + collider.sizeX * 1.5 &&
				position.y + radius > object->GetPosition().y - collider.sizeY * 0.5f &&
				position.y < object->GetPosition().y + collider.sizeY * 0.5f) {
				if (position.x + radius > object->GetPosition().x - collider.sizeX * 0.5f && position.x - radius < object->GetPosition().x + collider.sizeX * 0.5f) {
					velocity.x = -velocity.x;
				}
				else
				{
					velocity.y = -velocity.y;
				}
			}
			break;

		default:
			break;
		}
	}
}

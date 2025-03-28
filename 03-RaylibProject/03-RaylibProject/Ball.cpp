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

void Ball::SetScore(Score* _pScore, Score* _eScore){
	pScore = _pScore;
	eScore = _eScore;
}

void Ball::Update(vector<GameObject*>* objectList){
	CheckCollision(objectList);
	position.x += velocity.x * GetFrameTime() * 20;
	position.y += velocity.y * GetFrameTime() * 20;
	return;
}

void Ball::Draw(){
	DrawCircle(position.x, position.y, radius, color);
}

void Ball::CheckCollision(vector<GameObject*>* objectList){
	if (position.x - radius <= 0 ){
		eScore->AddScore();
		Restart();
	}
	if (position.x + radius >= GetScreenWidth()) {
		pScore->AddScore();
		Restart();
	}
	if (position.y - radius <= 0 || position.y + radius >= GetScreenHeight()) {
		velocity.y = -velocity.y;
	}
	for (GameObject* object : *objectList) {
		Collider collider = object->GetCollider();
		switch (collider.type)
		{
		case ColliderType::Square:
			if (position.x + radius > object->GetPosition().x &&
				position.x - radius < object->GetPosition().x + collider.sizeX &&
				position.y + radius > object->GetPosition().y &&
				position.y - radius < object->GetPosition().y + collider.sizeY) {
				if (position.y > object->GetPosition().y && position.y < object->GetPosition().y + collider.sizeY) {
					velocity.x = -velocity.x;
					velocity = Vector2{ velocity.x * 1.15f, velocity.y * 1.15f};
				}
				else if(position.x > object->GetPosition().x && position.x < object->GetPosition().x + collider.sizeX) {
					velocity.y = -velocity.y;
					velocity = Vector2{ velocity.x * 1.15f, velocity.y * 1.15f};
				}
			}
			
			break;

		default:
			break;
		}
	}
}

void Ball::Restart() {
	position = Vector2{ GetScreenWidth() * 0.5f, GetScreenHeight() * 0.5f };
	velocity = Vector2{ -5.0f, (rand() % 5) - 2.5f };
}

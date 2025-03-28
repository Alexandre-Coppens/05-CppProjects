#pragma once
#include "GameObject.h"
#include "Score.h"
#include <string>

using std::string;

class Ball : public GameObject{
private:
	float radius;

	Vector2 velocity;
	Color color;

	Score* pScore;
	Score* eScore;

public:
	Ball();
	Ball(Vector2 _position, float _radius, Vector2 _velocity, Color _color);
	~Ball();

	void SetScore(Score* _pScore, Score* _eScore);

	void Update(vector<GameObject*>* objectList) override;
	void Draw() override;

	void Restart();
	void CheckCollision(vector<GameObject*>* objectList);
};


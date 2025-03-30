#pragma once
#include "raylib.h"
#include "GameObject.h"
#include "Score.h"
#include "Paddle.h"
#include <string>
#include <vector>

using std::string;
using std::vector;

class Ball : public GameObject{
private:
	float radius;

	Vector2 velocity;
	Texture2D* texture;

	Color color;

	Paddle* ePaddle;

	Score* pScore;
	Score* eScore;

public:
	Ball();
	Ball(Vector2 _position, float _radius, Vector2 _velocity, Texture2D* _texture);
	~Ball();

	void SetScore(Score* _pScore, Score* _eScore);
	const inline void  ChangeColor() { color = ColorFromHSV(rand() % 255, rand() % 255, rand() % 255); }
	const inline void   SetPaddle(Paddle * _paddle) { ePaddle = _paddle; }

	void Update(vector<GameObject*>* objectList) override;
	void Draw() override;

	void Restart();
	void CheckCollision(vector<GameObject*>* objectList);
};


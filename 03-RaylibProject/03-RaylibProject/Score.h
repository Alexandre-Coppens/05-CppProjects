#pragma once
#include "GameObject.h"
#include "Score.h"
#include "Paddle.h"

class Score : public GameObject {
private:
	int score;
	int size;

	Font* font;

	Paddle* paddle;

	Color color;

public:
	Score();
	Score(Vector2 _position, int _size, Font* font, Color _color, Paddle* _paddle);
	~Score();

	void Update(vector<GameObject*>* objectList) override;
	void Draw() override;

	void AddScore();
};


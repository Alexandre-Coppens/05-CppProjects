#pragma once
#include "GameObject.h"
#include "Score.h"

class Score : public GameObject {
private:
	int score;
	int size;

	Font* font;

	Color color;

public:
	Score();
	Score(Vector2 _position, int _size, Font* font, Color _color);
	~Score();

	void Update(vector<GameObject*>* objectList) override;
	void Draw() override;

	const inline void AddScore() { score ++; }
};


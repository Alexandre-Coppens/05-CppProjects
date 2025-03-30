#include "Score.h"

Score::Score(){
	position = Vector2{ 0,0 };
	size = 0;
	color = WHITE;
	score = 0;
	font = NULL;
}

Score::Score(Vector2 _position, int _size, Font* _font,Color _color){
	position = _position;
	size = _size;
	color = _color;
	score = 0;
	font = _font;
}

Score::~Score(){
}

void Score::Update(vector<GameObject*>* objectList){
	return;
}

void Score::Draw(){
	DrawTextEx(*font, TextFormat("%i", score), position, static_cast<int>(size), 0, color);
}

void Score::AddScore(){
	score++;
}

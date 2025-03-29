#include "Score.h"

Score::Score(){
}

Score::Score(Vector2 _position, int _size, Font* _font,Color _color, Paddle* _paddle){
	position = _position;
	size = _size;
	color = _color;
	score = 0;
	font = _font;
	paddle = _paddle;
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
	if(paddle)paddle->AddSpeed();
}

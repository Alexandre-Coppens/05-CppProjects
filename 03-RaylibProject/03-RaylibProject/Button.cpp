#include "Button.h"

Button::Button(){
}

Button::Button(Vector2 _position, Vector2 _size, Color _color){
	position = _position;
	size = _size;
	color = _color;
}

void Button::Update(vector<GameObject*>* objectList){
	if (IsMouseButtonPressed(0)) return;
}

void Button::Draw(){
	Vector3 darker = ColorToHSV(color);
	darker.z += 50;
	DrawRectangleV(position, size, ColorFromHSV(darker.x, darker.y, darker.z));
	DrawRectangleV(position, size, color);
}

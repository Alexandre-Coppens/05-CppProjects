#include <iostream>
#include "Paddle.h"

using std::cout;

Paddle::Paddle(){
}

Paddle::Paddle(Vector2 _position, Vector2 _size, float _speed, Color _color){
    position = _position;
    size = _size;
    speed = _speed;
    color = _color;

    collider = { ColliderType::Square, size.x, size.y };
}

void Paddle::AssignKeys(KeyboardKey _keyUp, KeyboardKey _keyDown){
    keyUp = _keyUp;
    keyDown = _keyDown;
}

void Paddle::Update(vector<GameObject*>* objectList){
    int addYPos = 0;
    if (isPlayer) {
        addYPos = KeyHold();
    }
    if (addYPos < 0 && position.y - (size.y * 0.5f) <= 0) {
        addYPos = 0;
    }
    if (addYPos > 0 && position.y + (size.y * 0.5f) >= GetScreenHeight()) {
        addYPos = 0;
    }

    position.y += addYPos * speed;
	return;
}

void Paddle::Draw(){
    Vector2 newPos{ position.x,position.y - size.y * 0.5f };
    DrawRectangleV(newPos, size, color);
}

int Paddle::KeyHold(){
    int y = 0;
    if (IsKeyDown(keyUp)) y-= 1;
    if (IsKeyDown(keyDown)) y += 1;
    return y;
}

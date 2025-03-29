#include <iostream>
#include <vector>
#include "Paddle.h"

using std::vector;

Paddle::Paddle(){
    isPlayer = false;
    size = Vector2{ 0,0 };
    speed = 0;
    color = WHITE;
    keyUp = KEY_NULL;
    keyDown = KEY_NULL;
    ball = NULL;
}

Paddle::Paddle(Vector2 _position, Vector2 _size, float _speed, Color _color){
    position = _position;
    size = _size;
    speed = _speed;
    color = _color;

    isPlayer = false;
    collider = { ColliderType::Square, size.x, size.y };

    keyUp = KEY_NULL;
    keyDown = KEY_NULL;
    ball = NULL;
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
    else{
        if (ball->GetPosition().y > position.y + (size.y * 0.5f)) {
            addYPos++;
        }
        else{
            addYPos--;
        }
    }
    if (addYPos < 0 && position.y <= 0) {
        addYPos = 0;
    }
    if (addYPos > 0 && position.y + size.y >= GetScreenHeight()) {
        addYPos = 0;
    }

    position.y += addYPos * speed * GetFrameTime() * 20;
	return;
}

void Paddle::Draw(){
    Vector2 newPos{ position.x,position.y};
    DrawRectangleV(newPos, size, color);
}

int Paddle::KeyHold(){
    int y = 0;
    if (IsKeyDown(keyUp)) y-= 1;
    if (IsKeyDown(keyDown)) y += 1;
    return y;
}

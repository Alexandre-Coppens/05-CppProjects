#include "FlyingNumber.h"

using std::to_string;

FlyingNumber::FlyingNumber(Vector2 _pos, int _value){
	enabled = true;
	position = _pos;
	velocity.x = std::rand() % 10 - 5;
	velocity.y = std::rand() % 10 * -1;
	if (-_value > 0) value = "+" + to_string(abs(_value));
	else value = "-" + to_string(abs(_value));
	timer = 2;
	speed = 5;
}

FlyingNumber::~FlyingNumber(){
	GameObjectList.erase(name);
}

void FlyingNumber::Update() {
	position.x += velocity.x * GetFrameTime() * speed;
	velocity.y += GetFrameTime() * 9.8f;
	if (value[0] == '+') position.y -= velocity.y * GetFrameTime() * speed;
	else position.y += velocity.y * GetFrameTime() * speed;
	timer -= GetFrameTime();
	if (timer <= 0) delete this;
}

void FlyingNumber::Draw(){
	if (value[0] == '+') DrawTextPro(AssetList::textFont["Setback"], value.c_str(), position, Vector2{ 0,0 }, 0, 20, 5, GREEN);
	else DrawTextPro(AssetList::textFont["Setback"], value.c_str(), position, Vector2{ 0,0 }, 0, 20, 5, RED);
}

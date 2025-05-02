#include "Button.h"
#include "AssetsList.h"

Button::Button() : GameObject() {
	value = 0;
	text = "";
	type = GameObjectType::None;
}

Button::Button(bool _enabled, Vector2 _pos, Vector2 _size, Texture2D* _sprite, int _value) : GameObject() {
	enabled = _enabled;
	position = _pos;
	size = _size;
	sprite = _sprite;
	type = GameObjectType::Button;

	value = _value;
	text = "";

	CreateRect();
}

Button::~Button(){
}

void Button::Draw(){
	GameObject::Draw();
	Vector2 textAdd = MeasureTextEx(AssetList::textFont["Romulus"], text.c_str(), 20, 5);
	DrawTextPro(AssetList::textFont["Romulus"], text.c_str(), Vector2{ position.x + (size.x - textAdd.x) * 0.5f, position.y + (size.y - textAdd.y) * 0.5f }, Vector2{0,0}, 0, 20, 5, BLACK);
}

int Button::Clicked() {
	return value;
}
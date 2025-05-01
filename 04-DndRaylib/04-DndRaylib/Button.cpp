#include "Button.h"
#include "AssetsList.h"

Button::Button() {
	enabled = false;
	name = "";
	position = Vector2{ 0,0 };
	size = Vector2{ 0,0 };
	sprite = nullptr;
	value = 0;
	text = "";
	type = GameObjectType::None;
}

Button::Button(bool _enabled, Vector2 _pos, Vector2 _size, Texture2D* _sprite, int _value){
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
	DrawTextPro(AssetList::textFont, text.c_str(), position, Vector2{ 0,0 }, 0, 20, 5, BLACK);
}
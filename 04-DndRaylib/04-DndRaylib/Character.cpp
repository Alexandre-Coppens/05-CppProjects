#include <iostream>
#include "Character.h"

Character::Character(Texture2D* _sprite, Vector2 _pos, vector<DamageTypes> _types, vector<AttackName> _attacks, float _speed, float _health) : GameObject() {
	enabled = false;
	position = _pos;
	size = Vector2{ 150,150 };
	type = GameObjectType::Character;

	sprite = _sprite;
	elementalTypes.assign(_types.begin(), _types.end());
	attacks.assign(_attacks.begin(), _attacks.end());
	speed = _speed;
	maxHealth = _health;
	health = _health;
	currentStatus = {};

	CreateRect();
}

Character::~Character(){
}

void Character::Draw() {
	GameObject::Draw();
	DrawTextEx(AssetList::textFont["Alagard"], name.c_str(), Vector2{position.x, position.y - 40}, 20, 3, WHITE);
	DrawRectangle((int)position.x, (int)position.y - 15, 150, 10, BLACK);
	DrawRectangle((int)position.x, (int)position.y - 15, (int)((health * 150) / maxHealth), 10, WHITE);
	for (Status status : currentStatus) {
		switch (status)
		{
		case Status::Poisoned:
			DrawTextureV(AssetList::SpriteList["Poison"], position, WHITE);
			break;
		case Status::Frost:
			DrawTextureV(AssetList::SpriteList["Iced"], position, WHITE);
			break;
		case Status::Burn:
			DrawTextureV(AssetList::SpriteList["Flames"], position, WHITE);
			break;
		case Status::Electric:
			DrawTextureV(AssetList::SpriteList["Paralysis"], position, WHITE);
			break;
		case Status::Heal:
			DrawTextureV(AssetList::SpriteList["Heal"], position, WHITE);
			break;
		case Status::None:
			DrawTextureV(AssetList::SpriteList["Unknown"], position, WHITE);
			break;
		default:
			break;
		}
	}
}

void Character::GetDamage(int damages) {
	health -= damages;
}
#include <iostream>
#include "Character.h"

Character::Character(string _name, Texture2D* _sprite, vector<DamageTypes> _types, vector<AttackName> _attacks, float _speed, float _health) {
	enabled = false;
	position = Vector2{ 0,0 };
	size = Vector2{ 0,0 };
	type = GameObjectType::Character;

	name = _name;
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

void Character::GetDamage(int damages) {
	health -= damages;
}
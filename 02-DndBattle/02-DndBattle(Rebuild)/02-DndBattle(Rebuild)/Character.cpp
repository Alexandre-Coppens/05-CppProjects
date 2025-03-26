#include <iostream>
#include <string>
#include <vector>
#include "Character.h"

using std::cout;
using std::string;
using std::vector;

Character::Character(string _name, vector<string>* _sprite, vector<DamageTypes> _types, AttackName _attacks[4], float _speed, float _health) {
	name = _name;
	sprite = _sprite;
	elementalTypes.assign(_types.begin(), _types.end());
	attacks[0] = _attacks[0];
	attacks[1] = _attacks[1];
	attacks[2] = _attacks[2];
	attacks[3] = _attacks[3];
	speed = _speed;
	maxHealth = _health;
	health = _health;
	currentStatus = Status::None;
}

void Character::GetDamage(int damages) {
	health -= damages;
}
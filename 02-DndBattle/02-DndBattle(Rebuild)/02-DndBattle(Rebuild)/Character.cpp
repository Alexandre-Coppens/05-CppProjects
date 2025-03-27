#include <iostream>
#include <string>
#include <vector>
#include "Character.h"

using std::cout;
using std::string;
using std::vector;

Character::Character(string _name, vector<string>* _sprite, vector<DamageTypes> _types, vector<AttackName> _attacks, float _speed, float _health) {
	name = _name;
	sprite = _sprite;
	elementalTypes.assign(_types.begin(), _types.end());
	attacks.assign(_attacks.begin(), _attacks.end());
	speed = _speed;
	maxHealth = _health;
	health = _health;
	currentStatus = {};
}

void Character::GetDamage(int damages) {
	health -= damages;
}
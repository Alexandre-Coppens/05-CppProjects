#include <iostream>
#include <string>
#include <vector>
#include "Character.h"

using std::cout;
using std::string;
using std::vector;

Character::Character(string _name, vector<string>* _sprite, DamageTypes _types[2], AttackName _attacks[4], float _speed, float _health) {
	name = _name;
	sprite = _sprite;
	damageTypes[0] = _types[0];
	damageTypes[1] = _types[1];
	attacks[0] = _attacks[0];
	attacks[1] = _attacks[1];
	attacks[2] = _attacks[2];
	attacks[3] = _attacks[3];
	speed = _speed;
	maxHealth = _health;
	health = _health;
	currentStatus = Status::None;
}

void Character::GetDamage(int damages){
	health -= damages;
}


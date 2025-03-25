#include <iostream>
#include <string>
#include <vector>
#include "Character.h"

using std::cout;
using std::string;
using std::vector;

Character::Character(string _name, vector<string>* _sprite, DamageTypes _types[2], float _speed, float _health) {
	name = _name;
	sprite = _sprite;
	damageTypes[0] = _types[0];
	damageTypes[1] = _types[1];
	speed = _speed;
	maxHealth = _health;
	health = _health;
	currentStatus = Status::None;
}

void Character::GetDamage(int damages){
	health -= damages;
}


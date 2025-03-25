#pragma once

#include <string>
#include <vector>
#include "Elements.h"

using std::string;
using std::vector;

class Character {
public:
	string name;
	vector<string>* sprite;
	DamageTypes damageTypes[2];
	DamageTypes damageTypes[2];

	float speed;
	float health;
	float maxHealth;
	Status currentStatus;

	Character(string _name, vector<string>* _sprite, DamageTypes _types[2], float _speed, float _health);
	void GetDamage(int damages);
};
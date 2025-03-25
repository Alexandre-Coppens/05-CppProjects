#pragma once

#include <string>
#include <vector>
#include "Elements.h"

using std::string;
using std::vector;

class Character {
public:
	string name = "None";
	vector<string>* sprite;
	DamageTypes damageTypes[2]{ DamageTypes::Normal, DamageTypes::Normal };

	float speed;
	float health;
	float maxHealth;
	Status currentStatus = Status::None;

	Character(string _name, vector<string>* _sprite, DamageTypes _types[2], float _speed, float _health);
	void GetDamage(int damages);
};
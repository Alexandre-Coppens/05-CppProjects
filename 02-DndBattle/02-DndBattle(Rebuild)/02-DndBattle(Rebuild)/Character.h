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
	vector<DamageTypes> elementalTypes;
	AttackName attacks[4];

	float speed;
	float health;
	float maxHealth;
	vector<Status> currentStatus;

public:
	Character(string _name, vector<string>* _sprite, vector<DamageTypes> _types, AttackName _attacks[4], float _speed, float _health);
	void GetDamage(int damages);
};
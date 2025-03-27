#pragma once

#include <string>
#include <vector>
#include "Elements.h"

using std::string;
using std::vector;

class Character {
public:
	vector<Status> currentStatus;

private:
	string name;
	vector<string>* sprite;
	vector<DamageTypes> elementalTypes;
	vector<AttackName> attacks;

	float speed;
	float health;
	float maxHealth;

public:

	Character(string _name, vector<string>* _sprite, vector<DamageTypes> _types, vector<AttackName> _attacks, float _speed, float _health);
	void GetDamage(int damages);

	const inline string GetName() { return name; }
	const inline vector<string>* GetSprite() { return sprite; }
	const inline vector<AttackName> GetAttacks() { return attacks; }
	const inline vector<DamageTypes> GetElements() { return elementalTypes; }
	
};
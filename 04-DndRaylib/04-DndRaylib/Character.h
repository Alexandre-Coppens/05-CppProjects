#pragma once

#include <string>
#include <vector>
#include "GameObject.h"
#include "Elements.h"
#include "Raylib.h"

class Character : public GameObject {
public:
	vector<Status> currentStatus;
	vector<DamageTypes> elementalTypes;
	vector<AttackName> attacks;

	float speed;
	float health;
	float maxHealth;

public:
	Character(Texture2D* _sprite, Vector2 _pos, vector<DamageTypes> _types, vector<AttackName> _attacks, float _speed, float _health);
	virtual ~Character();
	void Draw();
	void GetDamage(int damages);

	const inline string GetName() { return name; }
	const inline Texture2D* GetSprite() { return sprite; }
	const inline vector<AttackName> GetAttacks() { return attacks; }
	const inline vector<DamageTypes> GetElements() { return elementalTypes; }
	
};
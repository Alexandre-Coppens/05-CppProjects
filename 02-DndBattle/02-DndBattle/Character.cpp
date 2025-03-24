#include <iostream>
#include <string>
#include <vector>
#include "Characters.h"

using std::cout;
using std::string;
using std::vector;

Character::Character() {

}

void Character::Start(string _name, vector<string>* _sprite, DamageTypes _types[2], float _speed, float _health) {
	name = _name;
	sprite = _sprite;
	damageTypes[0] = _types[0];
	damageTypes[1] = _types[1];
	speed = _speed;
	health = _health;
	currentStatus = Status::None;
}

void Character::ShowSprite(int spaces) {
	cout << name << "\n";
	cout << sprite << "\n";
	cout << PrintDamageType(damageTypes[0]) << " : " << PrintDamageType(damageTypes[1]) << "\n";
	cout << speed << "\n";
	cout << health << "\n";
	cout << health << "\n";
}
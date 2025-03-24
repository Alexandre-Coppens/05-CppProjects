#pragma once
#include <map>

using std::map;
using std::string;

enum class Status {		//Each turn 
	Poisoned,	//Make 5% Damage per turn
	Frost,		//Slow enemy by 10
	Burn,		//Make 5% Damage per turn
	Electric,	//Chance for the enemy to not make move 25%
	None,		
};

enum class DamageTypes {
	Cold,		// +: Piercing	++: Necrotic
	Fire,		// +: Cold		++: Slashing
	Lighting,	// +: Slashing	++: Piercing
	Piercing,	// +: Fire		++: Lighting
	Slashing,	// +: Necrotic	++: Cold
	Necrotic,	// +: Lighting	++: Fire
	Normal,		//None
};

map<DamageTypes, string> objects{
		{DamageTypes::Cold, "Cold"},
		{DamageTypes::Fire, "Fire"},
		{DamageTypes::Lighting, "Lighting"},
		{DamageTypes::Piercing, "Piercing"},
		{DamageTypes::Slashing, "Slashing"},
		{DamageTypes::Necrotic, "Necrotic"}
};

string PrintDamageType(DamageTypes damageType) {
	return objects[damageType];
}
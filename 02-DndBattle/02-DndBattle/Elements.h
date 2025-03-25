#pragma once

#include <map>
#include <string>

using std::map;
using std::string;

static enum class Status {		//Each turn 
	Poisoned,	//Make 5% Damage per turn
	Frost,		//Slow enemy by 10
	Burn,		//Make 5% Damage per turn
	Electric,	//Chance for the enemy to not make move 25%
	None,		
};

static enum class DamageTypes {
	Cold,		// +: Piercing	++: Necrotic
	Fire,		// +: Cold		++: Slashing
	Lighting,	// +: Slashing	++: Piercing
	Piercing,	// +: Fire		++: Lighting
	Slashing,	// +: Necrotic	++: Cold
	Necrotic,	// +: Lighting	++: Fire
	Normal,		//None
};

static map<DamageTypes, string> objects{
		{DamageTypes::Cold, "Cold"},
		{DamageTypes::Fire, "Fire"},
		{DamageTypes::Lighting, "Lighting"},
		{DamageTypes::Piercing, "Piercing"},
		{DamageTypes::Slashing, "Slashing"},
		{DamageTypes::Necrotic, "Necrotic"}
};
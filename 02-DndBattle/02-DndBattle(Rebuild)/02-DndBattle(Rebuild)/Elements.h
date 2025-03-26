#pragma once

#include <map>
#include <string>
#include <vector>

using std::map;
using std::string;
using std::vector;

enum class Status {		//Each turn at start of attack have 33% chance to lose the status
	Poisoned,	//Make 5% Damage per turn
	Frost,		//Slow enemy by 10
	Burn,		//Make 5% Damage per turn
	Electric,	//Chance for the enemy to not make move 25%
	Heal,		//heal 5% of health 33% chance 
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

enum class AttackName {
	Heal,
	Slash,
	FireSword,
	Smite,
	PiercingDagger,
	ShadowDagger,
	Poison,
	Fireball,
	Lightning,
	Curse,
	Bludgeon,
	FireAxe,
	IceAxe,
	HeadSmasher,
	Triped,
	Zap,
	ShortCircuit,
	Dive,
	IceBreath,
	Stun,
	Chomp,
	ThrowRock,
	Slam,
	OldMagic,
	MoltenBreath,
	LightningCall,
	MightyDive
};

static map<DamageTypes, string> damageTypeNames{
		{DamageTypes::Cold, "Cold"},
		{DamageTypes::Fire, "Fire"},
		{DamageTypes::Lighting, "Lighting"},
		{DamageTypes::Piercing, "Piercing"},
		{DamageTypes::Slashing, "Slashing"},
		{DamageTypes::Necrotic, "Necrotic"}
};

static map<Status, string> statusNames{
		{Status::Burn, "Burn"},
		{Status::Frost, "Frost"},
		{Status::Poisoned, "Poison"},
		{Status::Electric, "Paralysis"},
		{Status::Heal, "Healing on you"},
		{Status::None, "Nothing"}
};

struct AttackInfo {
	DamageTypes damageType;
	int damage;
	Status status;
	string name;
};

static map<AttackName, AttackInfo> attackInfos{
		{AttackName::Heal,				{DamageTypes::Normal,	0,	Status::Heal,		"Heal"}},
		{AttackName::Slash,				{DamageTypes::Slashing, 10, Status::None,		"Slash"}},
		{AttackName::Smite,				{DamageTypes::Lighting, 10, Status::None,		"Smite"}},
		{AttackName::FireSword,			{DamageTypes::Fire,		5,	Status::Burn,		"FireSword"}},
		{AttackName::PiercingDagger,	{DamageTypes::Piercing, 10, Status::None,		"Piercing Dagger"}},
		{AttackName::ShadowDagger,		{DamageTypes::Cold,		10, Status::None,		"Shadow Dagger"}},
		{AttackName::Poison,			{DamageTypes::Necrotic, 0,	Status::Poisoned,	"Poison"}},
		{AttackName::Fireball,			{DamageTypes::Fire,		10, Status::Burn,		"Fireball"}},
		{AttackName::Lightning,			{DamageTypes::Lighting, 10, Status::Electric,	"Ligthning"}},
		{AttackName::Bludgeon,			{DamageTypes::Slashing, 15, Status::None,		"Bludgeon"}},
		{AttackName::FireAxe,			{DamageTypes::Fire,		10, Status::Burn,		"FireAxe"}},
		{AttackName::IceAxe,			{DamageTypes::Cold,		10, Status::Frost,		"IceAxe"}},
		{AttackName::HeadSmasher,		{DamageTypes::Slashing,	10,	Status::Electric,	"HeadSmasher"}},
		{AttackName::Triped,			{DamageTypes::Normal,	0,	Status::None,		"Triped"}},
		{AttackName::Zap,				{DamageTypes::Lighting,	8,	Status::None,		"Zap"}},
		{AttackName::ShortCircuit,		{DamageTypes::Lighting,	5,	Status::Electric,	"ShortCircuit"}},
		{AttackName::Dive,				{DamageTypes::Piercing,	7,	Status::None,		"Dive"}},
		{AttackName::IceBreath,			{DamageTypes::Cold,		5,	Status::Frost,		"IceBreath"}},
		{AttackName::Stun,				{DamageTypes::Normal,	0,	Status::Electric,	"Stun"}},
		{AttackName::Chomp,				{DamageTypes::Slashing,	10,	Status::None,		"Chomp"}},
		{AttackName::ThrowRock,			{DamageTypes::Piercing,	10,	Status::None,		"Throw Rock"}},
		{AttackName::Slam,				{DamageTypes::Slashing,	10,	Status::None,		"Slam"}},
		{AttackName::OldMagic,			{DamageTypes::Normal,	0,	Status::Heal,		"OldMagic"}},
		{AttackName::MoltenBreath,		{DamageTypes::Fire,		12,	Status::Burn,		"MoltenBreath"}},
		{AttackName::LightningCall,		{DamageTypes::Lighting,	10,	Status::Electric,	"LightningCall"}},
		{AttackName::MightyDive,		{DamageTypes::Piercing,	17,	Status::None,		"MightyDive"}}
};

static float GetWeaknessMult(DamageTypes attackType, DamageTypes enemy) {
	switch (attackType)
	{
	case DamageTypes::Cold:
		if (enemy == DamageTypes::Piercing) return 1.25f;
		if (enemy == DamageTypes::Necrotic) return 1.5f;
		return 1;

	case DamageTypes::Fire:
		if (enemy == DamageTypes::Cold) return 1.25f;
		if (enemy == DamageTypes::Slashing) return 1.5f;
		return 1;

	case DamageTypes::Lighting:
		if (enemy == DamageTypes::Slashing) return 1.25f;
		if (enemy == DamageTypes::Piercing) return 1.5f;
		return 1;

	case DamageTypes::Piercing:
		if (enemy == DamageTypes::Fire) return 1.25f;
		if (enemy == DamageTypes::Lighting) return 1.5f;
		return 1;

	case DamageTypes::Slashing:
		if (enemy == DamageTypes::Necrotic) return 1.25f;
		if (enemy == DamageTypes::Cold) return 1.5f;
		return 1;

	case DamageTypes::Necrotic:
		if (enemy == DamageTypes::Lighting) return 1.25f;
		if (enemy == DamageTypes::Fire) return 1.5f;
		return 1;

	default:
		return 1;
	}
}

static float GetWeakness(DamageTypes attackType, vector<DamageTypes> enemyType) {
	float ret = 1;
	float newret;
	for (DamageTypes enemy : enemyType) {
		newret = GetWeaknessMult(attackType, enemy);
		if (newret > ret) ret = newret;
	}
	return ret;
}
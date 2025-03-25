#pragma once

#include <map>
#include <string>

using std::map;
using std::string;

static enum class Status {		//Each turn at start of attack have 33% chance to lose the status
	Poisoned,	//Make 5% Damage per turn
	Frost,		//Slow enemy by 10
	Burn,		//Make 5% Damage per turn
	Electric,	//Chance for the enemy to not make move 25%
	Heal,		//heal 5% of health 33% chance 
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

static enum class AttackName {
	Heal,
	Slash,
	FireSword,
	Smite,
	PiercingDagger,
	ShadowDagger,
	Poison,
	Fireball,
	Ligthning,
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

static map<DamageTypes, string> objects{
		{DamageTypes::Cold, "Cold"},
		{DamageTypes::Fire, "Fire"},
		{DamageTypes::Lighting, "Lighting"},
		{DamageTypes::Piercing, "Piercing"},
		{DamageTypes::Slashing, "Slashing"},
		{DamageTypes::Necrotic, "Necrotic"}
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
		{AttackName::FireSword,			{DamageTypes::Fire,		5,	Status::Burn,		"Piercing Dagger"}},
		{AttackName::PiercingDagger,	{DamageTypes::Piercing, 10, Status::None,		"Piercing Dagger"}},
		{AttackName::ShadowDagger,		{DamageTypes::Cold,		10, Status::None,		"Shadow Dagger"}},
		{AttackName::Poison,			{DamageTypes::Necrotic, 0,	Status::Poisoned,	"Poison"}},
		{AttackName::Fireball,			{DamageTypes::Fire,		10, Status::Burn,		"Fireball"}},
		{AttackName::Ligthning,			{DamageTypes::Lighting, 10, Status::Electric,	"Ligthning"}},
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
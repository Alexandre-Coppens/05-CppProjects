// 02-DndBattle.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include "Character.h"
#include "CharacterTypes.h"
#include "ScreenPrint.h"

using std::string;
using std::vector;

void Start() {
	CharacterType characterCreator;

	DamageTypes dragonTypes[2]{ DamageTypes::Lighting, DamageTypes::Normal };
	AttackName dragonAttacks[4]{ AttackName::MoltenBreath, AttackName::LightningCall, AttackName::MightyDive, AttackName::OldMagic };
	Character dragon("DRAGON", characterCreator.GetSprite(CharacterTypes::Dragon), dragonTypes, dragonAttacks, 1000, 1000);
	dragon.GetDamage(100);

	DamageTypes lichTypes[2]{ DamageTypes::Necrotic, DamageTypes::Normal };
	AttackName lichAttacks[4]{ AttackName::Fireball, AttackName::Poison, AttackName::Lightning, AttackName::OldMagic };
	Character lich("LICH", characterCreator.GetSprite(CharacterTypes::Lich), lichTypes, lichAttacks, 356, 356);
	lich.GetDamage(100);

	DamageTypes golemTypes[2]{ DamageTypes::Normal, DamageTypes::Normal };
	AttackName golemAttacks[4]{ AttackName::ThrowRock, AttackName::Slam, AttackName::HeadSmasher, AttackName::OldMagic };
	Character golem("GOLEM", characterCreator.GetSprite(CharacterTypes::Golem), golemTypes, golemAttacks, 500, 500);
	golem.GetDamage(100);

	DamageTypes beholderTypes[2]{ DamageTypes::Fire, DamageTypes::Cold };
	AttackName beholderAttacks[4]{ AttackName::IceBreath, AttackName::Stun, AttackName::Chomp, AttackName::Fireball };
	Character beholder("BEHOLDER", characterCreator.GetSprite(CharacterTypes::Beholder), beholderTypes, beholderAttacks, 500, 250);
	beholder.GetDamage(100);

	DamageTypes mimicTypes[2]{ DamageTypes::Lighting, DamageTypes::Piercing };
	AttackName mimicAttacks[4]{ AttackName::Zap, AttackName::ShortCircuit, AttackName::Dive, AttackName::Triped };
	Character mimic("MIMIC", characterCreator.GetSprite(CharacterTypes::Mimic), mimicTypes, mimicAttacks, 500, 150);
	mimic.GetDamage(100);

	DamageTypes skeletonTypes[2]{ DamageTypes::Necrotic, DamageTypes::Slashing };
	AttackName skeletonAttacks[4]{ AttackName::Slash, AttackName::Poison, AttackName::Triped, AttackName::Triped };
	Character skeleton("SKELETON", characterCreator.GetSprite(CharacterTypes::Skeleton), skeletonTypes, skeletonAttacks, 500, 75);
	skeleton.GetDamage(100);
	



	DamageTypes knightTypes[2]{ DamageTypes::Slashing, DamageTypes::Fire };
	AttackName knightAttacks[4]{ AttackName::Slash, AttackName::FireSword, AttackName::Smite, AttackName::Heal };
	Character knight("KNIGHT", characterCreator.GetSprite(CharacterTypes::Knight), knightTypes, knightAttacks, 500, 500);
	knight.GetDamage(100); 

	DamageTypes rogueTypes[2]{ DamageTypes::Piercing, DamageTypes::Necrotic };
	AttackName rogueAttacks[4]{ AttackName::PiercingDagger, AttackName::ShadowDagger, AttackName::Poison, AttackName::Heal };
	Character rogue("ROGUE", characterCreator.GetSprite(CharacterTypes::Rogue), rogueTypes, rogueAttacks, 500, 300);
	rogue.GetDamage(100); 

	DamageTypes wizardTypes[2]{ DamageTypes::Lighting, DamageTypes::Fire };
	AttackName wizardAttacks[4]{ AttackName::Fireball, AttackName::Lightning, AttackName::Poison, AttackName::Heal };
	Character wizard("WIZARD", characterCreator.GetSprite(CharacterTypes::Wizard), wizardTypes, wizardAttacks, 500, 250);
	wizard.GetDamage(100); 

	DamageTypes barbarianTypes[2]{ DamageTypes::Fire, DamageTypes::Cold };
	AttackName barbarianAttacks[4]{ AttackName::Bludgeon, AttackName::HeadSmasher, AttackName::FireAxe, AttackName::IceAxe };
	Character barbarian("BARBARIAN", characterCreator.GetSprite(CharacterTypes::Barbarian), barbarianTypes, barbarianAttacks, 500, 450);
	barbarian.GetDamage(100);

	PrintScreen(&beholder, &barbarian);
}

int main()
{
	Start();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

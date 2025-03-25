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
	Character dragon("DRAGON", characterCreator.GetSprite(CharacterTypes::Dragon), dragonTypes, 1000, 1000);
	dragon.GetDamage(100);

	DamageTypes lichTypes[2]{ DamageTypes::Necrotic, DamageTypes::Normal };
	Character lich("LICH", characterCreator.GetSprite(CharacterTypes::Lich), lichTypes, 356, 356);
	lich.GetDamage(100);

	DamageTypes golemTypes[2]{ DamageTypes::Normal, DamageTypes::Normal };
	Character golem("GOLEM", characterCreator.GetSprite(CharacterTypes::Golem), golemTypes, 500, 500);
	golem.GetDamage(100);

	DamageTypes beholderTypes[2]{ DamageTypes::Fire, DamageTypes::Cold };
	Character beholder("BEHOLDER", characterCreator.GetSprite(CharacterTypes::Beholder), beholderTypes, 500, 250);
	beholder.GetDamage(100);

	DamageTypes mimicTypes[2]{ DamageTypes::Lighting, DamageTypes::Piercing };
	Character mimic("MIMIC", characterCreator.GetSprite(CharacterTypes::Mimic), mimicTypes, 500, 150);
	mimic.GetDamage(100);

	DamageTypes skeletonTypes[2]{ DamageTypes::Necrotic, DamageTypes::Slashing };
	Character skeleton("SKELETON", characterCreator.GetSprite(CharacterTypes::Skeleton), skeletonTypes, 500, 75);
	skeleton.GetDamage(100);
	



	DamageTypes knightTypes[2]{ DamageTypes::Slashing, DamageTypes::Fire };
	Character knight("KNIGHT", characterCreator.GetSprite(CharacterTypes::Knight), knightTypes, 500, 500);
	knight.GetDamage(100); 

	DamageTypes rogueTypes[2]{ DamageTypes::Piercing, DamageTypes::Necrotic };
	Character rogue("ROGUE", characterCreator.GetSprite(CharacterTypes::Rogue), rogueTypes, 500, 300);
	rogue.GetDamage(100); 

	DamageTypes wizardTypes[2]{ DamageTypes::Lighting, DamageTypes::Fire };
	Character wizard("WIZARD", characterCreator.GetSprite(CharacterTypes::Wizard), wizardTypes, 500, 250);
	wizard.GetDamage(100); 

	DamageTypes barbarianTypes[2]{ DamageTypes::Fire, DamageTypes::Cold };
	Character barbarian("BARBARIAN", characterCreator.GetSprite(CharacterTypes::Barbarian), barbarianTypes, 500, 450);
	barbarian.GetDamage(100);

	PrintScreen(&knight, &beholder);
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

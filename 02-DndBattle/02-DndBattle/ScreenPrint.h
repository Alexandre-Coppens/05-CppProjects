#pragma once

#include <iostream>
#include <string>
#include "Character.h"

using std::cout;
using std::cin;
using std::string;

static enum class CurrentBattlePhase {	
	ChooseAttack,	
	ConfirmAttack,		
	AttackPlayer,		
	AttackEnemy,	
	None,
};

static string PrintDamageType(DamageTypes damageType) {
	return objects[damageType];
}

string GetStrHealth(Character* character) {
	string cHealth;
	for (int i = 0; i < 20; i++) {
		if (i < 20 * character->health / character->maxHealth) {
			cHealth += "°";
		}
		else {
			cHealth += " ";
		}
	}
	cHealth += "|\n";
	return cHealth;
}

void PrintCharacters(Character* character, string spaces) {
	cout << spaces << character->name << "\n";
	cout << spaces << GetStrHealth(character);
	for (string line : *character->sprite) {
		cout << spaces << line;
	}
}

void PrintText(Character* character) {
	string firstSpaces(30, ' ');
	string attackName = attackInfos[character->attacks[0]].name;
	cout << firstSpaces << "1." << attackName;
	string secondSpaces(30 - int(attackName.length()), ' ');
	cout << secondSpaces << "2." << attackInfos[character->attacks[1]].name << "\n";

	attackName = attackInfos[character->attacks[2]].name;
	cout << firstSpaces << "3." << attackName;
	string thirdSpaces(30 - int(attackName.length()), ' ');
	cout << secondSpaces << "4." << attackInfos[character->attacks[3]].name << "\n";
	cin >> thirdSpaces; //Just for tests purposes
}

void PrintScreen(Character* playerCharacter, Character* enemyCharacter) {
	string playerSpaces(20, ' ');
	playerSpaces += "| ";
	string enemySpaces(50, ' ');
	enemySpaces = playerSpaces + enemySpaces;
	string container(73, '-');

	cout << playerSpaces.substr(0, 20) << " " << container << "\n";

	PrintCharacters(enemyCharacter, enemySpaces);
	cout << playerSpaces <<"\n";
	PrintCharacters(playerCharacter, playerSpaces);
	cout << playerSpaces << "\n";

	cout << playerSpaces.substr(0, 20) << " " << container << "\n";

	string separator(120, '-');
	cout << separator << "\n\n";

	PrintText(playerCharacter);
}
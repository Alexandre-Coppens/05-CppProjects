#pragma once

#include <iostream>
#include <string>
#include "Character.h"

using std::cout;
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

}
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
	cout << "\n";

	int spaceCount = 70;
	string spaces;
	for (int i = 0; i < spaceCount; i++) {
		spaces += " ";
	}

	int pspaceCount = 20; //Chercher un algo pour faire ca
	string pspaces;
	for (int i = 0; i < pspaceCount; i++) {
		pspaces += " ";
	}

	PrintCharacters(enemyCharacter, spaces);
	cout << "\n";
	PrintCharacters(playerCharacter, pspaces);
	cout << "\n";
}
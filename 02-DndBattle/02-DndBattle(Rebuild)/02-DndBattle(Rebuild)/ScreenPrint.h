#pragma once

#include <iostream>
#include <string>
#include "Character.h"

using std::cout;
using std::cin;
using std::string;

enum class CurrentBattlePhase {
	ChooseAttack,
	ConfirmAttack,
	AttackPlayer,
	AttackEnemy,
	Paralysed,
	None,
};

static void PrintAttacksChoice(Character* character);
static void PrintCharacters(Character* character, string spaces);
static void PrintConfirmAttacks(Character* character, short playerChoice);
static void PrintAttack(Character* attacker, Character* defender, short attackChoice);
static void PrintScreen(Character* playerCharacter, Character* enemyCharacter, CurrentBattlePhase phase, short playerChoice);
static string GetStrHealth(Character* character);
static string DamageType(DamageTypes damageType);

static string DamageType(DamageTypes damageType) {
	return damageTypeNames[damageType];
}

static void PrintAttacksChoice(Character* character) {
	string firstSpaces(30, ' ');
	string attackName = attackInfos[character->attacks[0]].name;
	cout << firstSpaces << "1." << attackName;
	string secondSpaces(30 - int(attackName.length()), ' ');
	cout << secondSpaces << "2." << attackInfos[character->attacks[1]].name << "\n";

	attackName = attackInfos[character->attacks[2]].name;
	cout << firstSpaces << "3." << attackName;
	string thirdSpaces(30 - int(attackName.length()), ' ');
	cout << secondSpaces << "4." << attackInfos[character->attacks[3]].name << "\n";
}


static void PrintConfirmAttacks(Character* character, short playerChoice) {
	AttackInfo* info = &attackInfos[character->attacks[playerChoice]];
	string firstSpaces(30, ' ');
	string attackName = attackInfos[character->attacks[playerChoice]].name;
	cout << firstSpaces << "Your Attack: " << attackName << " !\n";
	cout << firstSpaces << "Damages: " << info->damage
		<< " Type: " << damageTypeNames[info->damageType]
		<< " Inflict: " << statusNames[info->status] << "\n";

	cout << firstSpaces << "1. Confirm Attack		2.Return \n";
}

static void PrintAttack(Character* attacker, Character* defender, short attackChoice) {
	AttackInfo* info = &attackInfos[attacker->attacks[attackChoice]];
	string firstSpaces(30, ' ');
	cout << firstSpaces << attacker->name << " used " << info->name << " on " << defender->name << " !\n";
	cout << firstSpaces << defender->name << " took " << info->damage * GetWeakness(info->damageType, defender->elementalTypes)
		<< " and " << statusNames[info->status] << " !\n";
}

static void PrintParalysed(Character* attacker) {
	string firstSpaces(30, ' ');
	cout << "\n";
	cout << firstSpaces << attacker->name << " is Paralysed, he will need time to recover!\n";
}

static string GetStrHealth(Character* character) {
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

static void PrintCharacters(Character* character, string spaces) {
	string cHealth = GetStrHealth(character);
	cout << spaces << character->name << "\n";
	cout << spaces << cHealth;
	for (string line : *character->sprite) {
		cout << spaces << line;
	}
}

static void PrintScreen(Character* playerCharacter, Character* enemyCharacter, CurrentBattlePhase phase, short playerChoice) {
	system("cls");

	string playerSpaces(20, ' ');
	playerSpaces += "| ";
	string enemySpaces(50, ' ');
	enemySpaces = playerSpaces + enemySpaces;
	string container(73, '-');

	cout << playerSpaces.substr(0, 20) << " " << container << "\n";

	PrintCharacters(enemyCharacter, enemySpaces);
	cout << playerSpaces << "\n";
	PrintCharacters(playerCharacter, playerSpaces);
	cout << playerSpaces << "\n";

	cout << playerSpaces.substr(0, 20) << " " << container << "\n";

	string separator(120, '-');
	cout << separator << "\n\n";

	switch (phase) {
	case CurrentBattlePhase::ChooseAttack:
		PrintAttacksChoice(playerCharacter);
		break;
	case CurrentBattlePhase::ConfirmAttack:
		PrintConfirmAttacks(playerCharacter, playerChoice);
		break;
	case CurrentBattlePhase::AttackEnemy:
		PrintAttack(enemyCharacter, playerCharacter, playerChoice);
		break;
	case CurrentBattlePhase::AttackPlayer:
		PrintAttack(playerCharacter, enemyCharacter, playerChoice);
		break;
	case CurrentBattlePhase::Paralysed:
		if(playerChoice == 0) PrintParalysed(playerCharacter);
		if(playerChoice == 1) PrintParalysed(enemyCharacter);
		break;
	}
}
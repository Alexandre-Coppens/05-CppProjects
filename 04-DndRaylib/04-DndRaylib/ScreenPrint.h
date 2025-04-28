#pragma once

#include <iostream>
#include <string>
#include "Raylib.h"
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
	Burned,
	Poisoned,
	Healed,
	Died,
	None,
};

static void PrintAttacksChoice(Character* character);
static void DrawCharacters(Character* character, string spaces);
static void PrintConfirmAttacks(Character* character, short playerChoice);
static void PrintAttack(Character* attacker, Character* defender, short attackChoice);
static void PrintScreen(Character* playerCharacter, Character* enemyCharacter, CurrentBattlePhase phase, short playerChoice);
static string GetStrHealth(Character* character);
static string DamageType(DamageTypes damageType);

static Vector2 enemyPos { 600, 50 };
static Vector2 playerPos { 50, 400 };

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

static void PrintHeal(Character* attacker) {
	string firstSpaces(30, ' ');
	cout << "\n";
	cout << firstSpaces << attacker->name << " is Healing, he regain some portion of it's health!\n";
}

static void PrintBurn(Character* attacker) {
	string firstSpaces(30, ' ');
	cout << "\n";
	cout << firstSpaces << attacker->name << " is burning, he is taking some damages!\n";
}

static void PrintPoisoned(Character* attacker) {
	string firstSpaces(30, ' ');
	cout << "\n";
	cout << firstSpaces << attacker->name << " is poisoned, he is taking some damages!\n";
}

static void PrintDied(Character* deadCharacter) {
	string firstSpaces(30, ' ');
	cout << "\n";
	cout << firstSpaces << deadCharacter->name << " is dead.. Changing to next character..\n";
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

static void DrawCharacters(Character* character, Vector2 position) {
	DrawText(character->name.c_str(), position.x, position.y - 40, 20, WHITE);
	DrawRectangle( position.x, position.y - 15, (character->health * 150)/character->maxHealth, 10, WHITE);
	for (Status status : character->currentStatus){
		switch (status)
		{
		case Status::Poisoned:
			DrawTextureV(*character->sprite, position, WHIE);
			break;
		case Status::Frost:
			break;
		case Status::Burn:
			break;
		case Status::Electric:
			break;
		case Status::Heal:
			break;
		case Status::None:
			break;
		default:
			break;
		}
	}
	DrawTextureV(*character->sprite, position, WHITE);
}

static void PrintScreen(Character* playerCharacter, Character* enemyCharacter, CurrentBattlePhase phase, short playerChoice) {
	BeginDrawing();
	ClearBackground(BLACK);

	DrawCharacters(enemyCharacter, Vector2{600, 50});
	DrawCharacters(playerCharacter, Vector2{50, 400});

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
	case CurrentBattlePhase::Healed:
		if (playerChoice == 0) PrintHeal(playerCharacter);
		if (playerChoice == 1) PrintHeal(enemyCharacter);
		break;
	case CurrentBattlePhase::Burned:
		if (playerChoice == 0) PrintBurn(playerCharacter);
		if (playerChoice == 1) PrintBurn(enemyCharacter);
		break;
	case CurrentBattlePhase::Poisoned:
		if (playerChoice == 0) PrintPoisoned(playerCharacter);
		if (playerChoice == 1) PrintPoisoned(enemyCharacter);
		break;
	case CurrentBattlePhase::Died:
		if (playerChoice == 1) PrintDied(playerCharacter);
		if (playerChoice == 0) PrintDied(enemyCharacter);
		break;
	}

	
	if (currentScene == Scenes::Game)DrawTextureEx(background, Vector2{ 0,0 }, 0, 0.55f, WHITE);

	for (GameObject* object : gameObjectList) {
		object->Draw();
	}

	EndDrawing();
}
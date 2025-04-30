#pragma once

#include <iostream>
#include <string>
#include "Raylib.h"
#include "Character.h"
#include "AssetsList.h"

using std::string;

AssetList* assets;

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
static void DrawScreen(Character* playerCharacter, Character* enemyCharacter, CurrentBattlePhase phase, short playerChoice);
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
	string secondSpaces(30 - int(attackName.length()), ' ');

	attackName = attackInfos[character->attacks[2]].name;
	string thirdSpaces(30 - int(attackName.length()), ' ');
}


static void PrintConfirmAttacks(Character* character, short playerChoice) {
	AttackInfo* info = &attackInfos[character->attacks[playerChoice]];
}

static void PrintAttack(Character* attacker, Character* defender, short attackChoice) {
	AttackInfo* info = &attackInfos[attacker->attacks[attackChoice]];
}

static void PrintDied(Character* deadCharacter) {
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
	if (assets == nullptr) assets = AssetList::GetInstance();
	DrawTextEx(assets->textFont,character->name.c_str(), Vector2{position.x, position.y - 40}, 20, 3, WHITE);
	DrawRectangle((int)position.x, (int)position.y - 15, (int)((character->health * 150)/character->maxHealth), 10, WHITE);
	for (Status status : character->currentStatus){
		switch (status)
		{
		case Status::Poisoned:
			DrawTextureV(assets->SpriteList["Poison"], position, WHITE);
			break;
		case Status::Frost:
			DrawTextureV(assets->SpriteList["Iced"], position, WHITE);
			break;
		case Status::Burn:
			DrawTextureV(assets->SpriteList["Flames"], position, WHITE);
			break;
		case Status::Electric:
			DrawTextureV(assets->SpriteList["Paralysis"], position, WHITE);
			break;
		case Status::Heal:
			DrawTextureV(assets->SpriteList["Heal"], position, WHITE);
			break;
		case Status::None:
			DrawTextureV(assets->SpriteList["Unknown"], position, WHITE);
			break;
		default:
			break;
		}
	}
	DrawTextureV(*character->sprite, position, WHITE);
}

static void DrawScreen(Character* playerCharacter, Character* enemyCharacter, CurrentBattlePhase phase, short playerChoice) {
	ClearBackground(GRAY);

	DrawCharacters(enemyCharacter, Vector2{350, 100});
	DrawCharacters(playerCharacter, Vector2{50, 100});

	switch (phase) {
	case CurrentBattlePhase::ChooseAttack:
		break;
	case CurrentBattlePhase::ConfirmAttack:
		break;
	case CurrentBattlePhase::AttackEnemy:
		break;
	case CurrentBattlePhase::AttackPlayer:
		break;
	case CurrentBattlePhase::Paralysed:
		break;
	case CurrentBattlePhase::Healed:
		break;
	case CurrentBattlePhase::Burned:
		break;
	case CurrentBattlePhase::Poisoned:
		//Print Damages + Color
		break;
	case CurrentBattlePhase::Died:
		break;
	}
}
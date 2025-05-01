#pragma once

#include <string>
#include <vector>
#include "Character.h"
#include "AssetsList.h"

using std::string;
using std::vector;

class Engine {
private:
	vector<Character> playerCharacters;
	vector<Character> enemyCharacters;

	AssetList* assets;

	short pattack;
	short eattack;
	short input;

	vector<short> currentActors{ 0,0 };

public:
	Engine();
	void Start();
	void Update();
	void Draw();

private:
	int UserInput();
	void PrintCurrentPhase(int choice);
	int WaitForPlayerInput();
	bool EffectsAfterAttack(Character* defender, bool isPlayer);
	void Heal(Character* attacker, bool isPlayer);
	void CheckDeath();
	void DamageCharacter(Character* defender, AttackInfo attack);
	bool EffectsBeforeAttack(Character* attacker, bool isPlayer);
	void AttackCharacter(Character* attacker, Character* defender, short attackChoice);
};
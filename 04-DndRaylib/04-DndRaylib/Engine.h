#pragma once

#include <string>
#include <vector>
#include "Character.h"

using std::string;
using std::vector;

class Engine {
private:
	vector<Character> playerCharacters;
	vector<Character> enemyCharacters;

	short pattack;
	short eattack;
	short input;

	vector<short> currentActors{ 0,0 };

public:
	Engine();
	void Start();
	void Update();

private:
	int UserInput();
	void PrintCurrentPhase(int choice);
	bool EffectsAfterAttack(Character* defender, bool isPlayer);
	void Heal(Character* attacker, bool isPlayer);
	void CheckDeath();
	void DamageCharacter(Character* defender, AttackInfo attack);
	bool EffectsBeforeAttack(Character* attacker, bool isPlayer);
	void AttackCharacter(Character* attacker, Character* defender, short attackChoice);
};
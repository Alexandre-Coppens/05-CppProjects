#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Character.h"
#include "CharacterTypes.h"
#include "ScreenPrint.h"

using std::string;
using std::vector;

class Engine {
private:
	vector<Character*> playerCharacters;
	vector<Character*> enemyCharacters;

	CurrentBattlePhase currentPhase;
	short pattack;
	short eattack;
	short input;

	vector<short> currentActors{ 0,0 };

public:
	Engine();
	void Update();

private:
	int UserInput();
	void PrintCurrentPhase(int choice);
	void AttackCharacter(Character* attacker, Character* defender, short attackChoice);
};
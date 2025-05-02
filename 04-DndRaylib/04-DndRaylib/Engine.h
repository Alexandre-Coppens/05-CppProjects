#pragma once

#include <string>
#include <vector>
#include "Character.h"
#include "AssetsList.h"

using std::string;
using std::vector;

class Engine {
private:
	vector<Character*> playerCharacters;
	vector<Character*> enemyCharacters;

	AssetList* assets;

	short pAttack;
	short eAttack;

	short input;
	short lastPlayed;

	string attackEvent;
	float attackEventTime;

	vector<short> currentActors{ 0,0 };

	struct AttackEvent {
		float time;
		string code;
		string text;
		AttackInfo attack;
	};
	vector<AttackEvent> events;

public:
	Engine();
	void Start();
	void Update();
	void Draw();

private:
	int UserInput();
	void ChangeButtonDispositions();
	void NextEvent();
	void AttackTurn();
	void PrintCurrentPhase(int choice);
	int WaitForPlayerInput();
	bool EffectsAfterAttack(Character* defender, bool isPlayer);
	void Heal(Character* attacker, bool isPlayer);
	void CheckDeath();
	void DamageCharacter(Character* defender, AttackInfo attack);
	bool EffectsBeforeAttack(Character* attacker);
	void AttackCharacter(Character* attacker, Character* defender, short attackChoice);
};
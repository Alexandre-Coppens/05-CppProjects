#include <iostream>
#include "Character.h"
#include "ScreenPrint.h"
#include "Engine.h"
#include "Elements.h"

using std::cin;
using std::cout;

CurrentBattlePhase currentPhase;

Engine::Engine() {

	vector<DamageTypes> dragonTypes{ DamageTypes::Lighting, DamageTypes::Normal };
	vector<AttackName> dragonAttacks{ AttackName::MoltenBreath, AttackName::LightningCall, AttackName::MightyDive, AttackName::OldMagic };
	Character dragon("DRAGON", characterCreator.GetSprite(CharacterTypes::Dragon), dragonTypes, dragonAttacks, float(rand() % 50), float(1000));

	vector<DamageTypes> lichTypes{ DamageTypes::Necrotic, DamageTypes::Normal };
	vector<AttackName> lichAttacks{ AttackName::Fireball, AttackName::Poison, AttackName::Lightning, AttackName::OldMagic };
	Character lich("LICH", characterCreator.GetSprite(CharacterTypes::Lich), lichTypes, lichAttacks, float(rand() % 50), float(356));

	vector<DamageTypes> golemTypes{ DamageTypes::Normal, DamageTypes::Normal };
	vector<AttackName> golemAttacks{ AttackName::ThrowRock, AttackName::Slam, AttackName::HeadSmasher, AttackName::OldMagic };
	Character golem("GOLEM", characterCreator.GetSprite(CharacterTypes::Golem), golemTypes, golemAttacks, float(rand() % 50), float(500));

	vector<DamageTypes> beholderTypes{ DamageTypes::Fire, DamageTypes::Cold };
	vector<AttackName> beholderAttacks{ AttackName::IceBreath, AttackName::Stun, AttackName::Chomp, AttackName::Fireball };
	Character beholder("BEHOLDER", characterCreator.GetSprite(CharacterTypes::Beholder), beholderTypes, beholderAttacks, float(rand() % 50), float(250));

	vector<DamageTypes> mimicTypes{ DamageTypes::Lighting, DamageTypes::Piercing };
	vector<AttackName> mimicAttacks{ AttackName::Zap, AttackName::ShortCircuit, AttackName::Dive, AttackName::Triped };
	Character mimic("MIMIC", characterCreator.GetSprite(CharacterTypes::Mimic), mimicTypes, mimicAttacks, float(rand() % 50), float(150));

	vector<DamageTypes> skeletonTypes{ DamageTypes::Necrotic, DamageTypes::Slashing };
	vector<AttackName> skeletonAttacks{ AttackName::Slash, AttackName::Poison, AttackName::Triped, AttackName::Triped };
	Character skeleton("SKELETON", characterCreator.GetSprite(CharacterTypes::Skeleton), skeletonTypes, skeletonAttacks, float(rand() % 50), float(75));



	vector<DamageTypes> knightTypes{ DamageTypes::Slashing, DamageTypes::Fire };
	vector<AttackName> knightAttacks{ AttackName::Slash, AttackName::FireSword, AttackName::Smite, AttackName::Heal };
	Character knight("KNIGHT", characterCreator.GetSprite(CharacterTypes::Knight), knightTypes, knightAttacks, float(rand() % 50), float(500));

	vector<DamageTypes> rogueTypes{ DamageTypes::Piercing, DamageTypes::Necrotic };
	vector<AttackName> rogueAttacks{ AttackName::PiercingDagger, AttackName::ShadowDagger, AttackName::Poison, AttackName::Heal };
	Character rogue("ROGUE", characterCreator.GetSprite(CharacterTypes::Rogue), rogueTypes, rogueAttacks, float(rand() % 50), float(300));

	vector<DamageTypes> wizardTypes{ DamageTypes::Lighting, DamageTypes::Fire };
	vector<AttackName> wizardAttacks{ AttackName::Fireball, AttackName::Lightning, AttackName::Poison, AttackName::Heal };
	Character wizard("WIZARD", characterCreator.GetSprite(CharacterTypes::Wizard), wizardTypes, wizardAttacks, float(rand() % 50), float(250));

	vector<DamageTypes> barbarianTypes{ DamageTypes::Fire, DamageTypes::Cold };
	vector<AttackName> barbarianAttacks{ AttackName::Bludgeon, AttackName::HeadSmasher, AttackName::FireAxe, AttackName::IceAxe };
	Character barbarian("BARBARIAN", characterCreator.GetSprite(CharacterTypes::Barbarian), barbarianTypes, barbarianAttacks, float(rand() % 50), float(450));

	playerCharacters = { knight, rogue, wizard, barbarian};
	enemyCharacters = { skeleton, mimic, beholder, golem, lich, dragon };

	currentPhase = CurrentBattlePhase::ChooseAttack;
	input = 0;
	pattack = 0;
	eattack = 0;
}

void Engine::Update() {
	do {
		cout << playerCharacters[0].name;
		currentPhase = CurrentBattlePhase::ChooseAttack;
		pattack = UserInput();
		currentPhase = CurrentBattlePhase::ConfirmAttack;
		input = UserInput();
	} while (input != 1);

	if (playerCharacters[currentActors[0]].speed + HasStatus(playerCharacters[currentActors[0]].currentStatus,Status::Frost)?-10:0 >= enemyCharacters[currentActors[1]].speed + HasStatus(enemyCharacters[currentActors[1]].currentStatus, Status::Frost) ? -10 : 0) {
		currentPhase = CurrentBattlePhase::AttackPlayer;
		UserInput();
		currentPhase = CurrentBattlePhase::AttackEnemy;
		UserInput();
	}
	else {
		currentPhase = CurrentBattlePhase::AttackEnemy;
		UserInput();
		currentPhase = CurrentBattlePhase::AttackPlayer;
		UserInput();
	}
}

int Engine::UserInput() {
	short choice;
	switch (currentPhase)
	{
	case CurrentBattlePhase::ChooseAttack:
		do {
			choice = 0;
			PrintCurrentPhase(0);
			cin >> choice;
			if (!cin.good()) { cin.clear(); cin.ignore(256, '\n'); choice = 0; }
		} while (choice < 1 || choice > 4);
		return choice - 1;

	case CurrentBattlePhase::ConfirmAttack:
		do {
			choice = 0;
			PrintCurrentPhase(pattack);
			cin >> choice;
			if (!cin.good()) { cin.clear(); cin.ignore(256, '\n'); choice = 0; }
		} while (choice < 1 || choice > 2);
		return choice;

	case CurrentBattlePhase::AttackPlayer:
		if (!EffectsBeforeAttack(&playerCharacters[currentActors[0]], true)) {
			AttackCharacter(&playerCharacters[currentActors[0]], &enemyCharacters[currentActors[1]], pattack);
			PrintCurrentPhase(pattack);
		}
		cin.ignore();
		cin.ignore();
		EffectsAfterAttack(&enemyCharacters[currentActors[1]], false);
		Heal(&playerCharacters[currentActors[0]], true);
		return 0;

	case CurrentBattlePhase::AttackEnemy:
		if (!EffectsBeforeAttack(&enemyCharacters[currentActors[1]], false)) {
			eattack = rand() % 4;
			AttackCharacter(&enemyCharacters[currentActors[1]], &playerCharacters[currentActors[0]], eattack);
			PrintCurrentPhase(eattack);
		}
		cin.ignore();
		cin.ignore();

		EffectsAfterAttack(&playerCharacters[currentActors[0]], true);
		Heal(&enemyCharacters[currentActors[1]], false);
		return 0;

	default:
		return 0;
	}
}

void Engine::PrintCurrentPhase(int choice) {
	PrintScreen(&playerCharacters[currentActors[0]], &enemyCharacters[currentActors[1]], currentPhase, choice);
}

void Engine::AttackCharacter(Character* attacker, Character* defender, short attackChoice) {
	AttackInfo info = attackInfos[attacker->attacks[attackChoice]];
	DamageCharacter(defender, info);
	if(info.status != Status::Heal) defender->currentStatus.push_back(info.status);
	else attacker->currentStatus.push_back(info.status);
}

void Engine::DamageCharacter(Character* defender, AttackInfo attack){
	defender->health -= attack.damage * GetWeakness(attack.damageType, defender->elementalTypes);
	if(defender->health > defender->maxHealth) defender->health = defender->maxHealth;
}

bool Engine::EffectsBeforeAttack(Character* attacker, bool isPlayer) // Return true if attacker is successfuly paralised
{
	vector<Status> statusList;
	statusList = attacker->currentStatus;
	bool ret = false;
	if (statusList.size() == 0) return false;
	for (int i = 0; i < statusList.size(); i++)
	{
		if (rand() % 3 == 0) {
			statusList.erase(find(statusList.begin(), statusList.end(), statusList[i]));
			i--;
			break;
		}

		if(statusList[i] == Status::Electric) {
			if (rand() % 4 == 0)
			{
				currentPhase = CurrentBattlePhase::Paralysed;
				PrintCurrentPhase(isPlayer?0:1);
				attacker->currentStatus = statusList;
				return true;
			}
		}

		if (statusList[i] == Status::None) {
			statusList.erase(find(statusList.begin(), statusList.end(), Status::None));
			i--;
			break;
		}
	}
	attacker->currentStatus = statusList;
	return ret;
}

bool Engine::EffectsAfterAttack(Character* defender, bool isPlayer)
{
	vector<Status> statusList;
	AttackInfo attack;
	statusList = defender->currentStatus;
	if (statusList.size() == 0) return false;
	for (int i = 0; i < statusList.size(); i++)
	{
		switch (statusList[i])
		{
		case Status::Poisoned:
			attack.damageType = DamageTypes::Necrotic;
			attack.damage = defender->maxHealth / 20;
			attack.status = Status::None;
			attack.name = "Poison";
			DamageCharacter(defender, attack);

			currentPhase = CurrentBattlePhase::Poisoned;
			PrintCurrentPhase(isPlayer ? 0 : 1);
			cin.ignore();
			cin.ignore();
			break;

		case Status::Burn:
			attack.damageType = DamageTypes::Fire;
			attack.damage = defender->maxHealth / 20;
			attack.status = Status::None;
			attack.name = "Fire";
			DamageCharacter(defender, attack);

			currentPhase = CurrentBattlePhase::Burned;
			PrintCurrentPhase(isPlayer ? 0 : 1);
			cin.ignore();
			cin.ignore();
			break;

		default:
			break;
		}
	}
	return true;
}

void Engine::Heal(Character* attacker, bool isPlayer)
{
	vector<Status> statusList;
	AttackInfo attack;
	statusList = attacker->currentStatus;
	if (statusList.size() == 0) return;
	for (int i = 0; i < statusList.size(); i++)
	{
		switch (statusList[i])
		{
		case Status::Heal:
			attack.damageType = DamageTypes::Normal;
			attack.damage = -(attacker->maxHealth / 20);
			attack.status = Status::None;
			attack.name = "Heal";
			DamageCharacter(attacker, attack);
			currentPhase = CurrentBattlePhase::Healed;
			PrintCurrentPhase(isPlayer ? 0 : 1);
			cin.ignore();
			cin.ignore();
			return;

		default:
			break;
		}
	}
	return;
}
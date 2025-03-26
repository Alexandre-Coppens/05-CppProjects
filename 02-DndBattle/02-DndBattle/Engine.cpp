#include <iostream>
#include "Character.h"
#include "Engine.h"

using std::cin;
using std::cout;

Engine::Engine(){
	CharacterType characterCreator;

	vector<DamageTypes> dragonTypes{ DamageTypes::Lighting, DamageTypes::Normal };
	AttackName dragonAttacks[4]{ AttackName::MoltenBreath, AttackName::LightningCall, AttackName::MightyDive, AttackName::OldMagic };
	Character dragon("DRAGON", characterCreator.GetSprite(CharacterTypes::Dragon), dragonTypes, dragonAttacks, float(rand() % 50), float(1000));

	vector<DamageTypes> lichTypes{ DamageTypes::Necrotic, DamageTypes::Normal };
	AttackName lichAttacks[4]{ AttackName::Fireball, AttackName::Poison, AttackName::Lightning, AttackName::OldMagic };
	Character lich("LICH", characterCreator.GetSprite(CharacterTypes::Lich), lichTypes, lichAttacks, float(rand() % 50), float(356));

	vector<DamageTypes> golemTypes{ DamageTypes::Normal, DamageTypes::Normal };
	AttackName golemAttacks[4]{ AttackName::ThrowRock, AttackName::Slam, AttackName::HeadSmasher, AttackName::OldMagic };
	Character golem("GOLEM", characterCreator.GetSprite(CharacterTypes::Golem), golemTypes, golemAttacks, float(rand() % 50), float(500));

	vector<DamageTypes> beholderTypes{ DamageTypes::Fire, DamageTypes::Cold };
	AttackName beholderAttacks[4]{ AttackName::IceBreath, AttackName::Stun, AttackName::Chomp, AttackName::Fireball };
	Character beholder("BEHOLDER", characterCreator.GetSprite(CharacterTypes::Beholder), beholderTypes, beholderAttacks, float(rand() % 50), float(250));

	vector<DamageTypes> mimicTypes{ DamageTypes::Lighting, DamageTypes::Piercing };
	AttackName mimicAttacks[4]{ AttackName::Zap, AttackName::ShortCircuit, AttackName::Dive, AttackName::Triped };
	Character mimic("MIMIC", characterCreator.GetSprite(CharacterTypes::Mimic), mimicTypes, mimicAttacks, float(rand() % 50), float(150));

	vector<DamageTypes> skeletonTypes{ DamageTypes::Necrotic, DamageTypes::Slashing };
	AttackName skeletonAttacks[4]{ AttackName::Slash, AttackName::Poison, AttackName::Triped, AttackName::Triped };
	Character skeleton("SKELETON", characterCreator.GetSprite(CharacterTypes::Skeleton), skeletonTypes, skeletonAttacks, float(rand() % 50), float(75));



	vector<DamageTypes> knightTypes{ DamageTypes::Slashing, DamageTypes::Fire };
	AttackName knightAttacks[4]{ AttackName::Slash, AttackName::FireSword, AttackName::Smite, AttackName::Heal };
	Character knight("KNIGHT", characterCreator.GetSprite(CharacterTypes::Knight), knightTypes, knightAttacks, float(rand() % 50), float(500));

	vector<DamageTypes> rogueTypes{ DamageTypes::Piercing, DamageTypes::Necrotic };
	AttackName rogueAttacks[4]{ AttackName::PiercingDagger, AttackName::ShadowDagger, AttackName::Poison, AttackName::Heal };
	Character rogue("ROGUE", characterCreator.GetSprite(CharacterTypes::Rogue), rogueTypes, rogueAttacks, float(rand() % 50), float(300));

	vector<DamageTypes> wizardTypes{ DamageTypes::Lighting, DamageTypes::Fire };
	AttackName wizardAttacks[4]{ AttackName::Fireball, AttackName::Lightning, AttackName::Poison, AttackName::Heal };
	Character wizard("WIZARD", characterCreator.GetSprite(CharacterTypes::Wizard), wizardTypes, wizardAttacks, float(rand() % 50), float(250));

	vector<DamageTypes> barbarianTypes{ DamageTypes::Fire, DamageTypes::Cold };
	AttackName barbarianAttacks[4]{ AttackName::Bludgeon, AttackName::HeadSmasher, AttackName::FireAxe, AttackName::IceAxe };
	Character barbarian("BARBARIAN", characterCreator.GetSprite(CharacterTypes::Barbarian), barbarianTypes, barbarianAttacks, float(rand() % 50), float(450));

	playerCharacters = { &knight, &rogue, &wizard, &barbarian, nullptr, nullptr };
	enemyCharacters = { &skeleton, &mimic, &beholder, &golem, &lich, &dragon };

	currentPhase = CurrentBattlePhase::ChooseAttack;
	input = 0;
	pattack = 0;
	eattack = 0;
}

void Engine::Update(){
	do {
		currentPhase = CurrentBattlePhase::ChooseAttack;
		pattack = UserInput();
		currentPhase = CurrentBattlePhase::ConfirmAttack;
		input = UserInput();
	} while (input != 1);

	if (playerCharacters[currentActors[0]]->speed >= enemyCharacters[currentActors[1]]->speed) {
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

void Engine::PrintCurrentPhase(int choice){
	PrintScreen(playerCharacters[currentActors[0]], enemyCharacters[currentActors[1]], currentPhase, choice);
}

void Engine::AttackCharacter(Character* attacker, Character* defender, short attackChoice){
	AttackInfo info = attackInfos[attacker->attacks[attackChoice]];
	defender->health -= info.damage * GetWeakness(info.damageType, defender->elementalTypes);
}

int Engine::UserInput(){
	short choice;
	switch (currentPhase)
	{
	case CurrentBattlePhase::ChooseAttack:
		do {
			PrintCurrentPhase(0);
			cin >> choice;
		} while (choice > 0 && choice < 5);
		return choice;

	case CurrentBattlePhase::ConfirmAttack:
		do {
			PrintCurrentPhase(pattack);
			cin >> choice;
		} while (choice > 0 && choice < 3);
		return choice;

	case CurrentBattlePhase::AttackPlayer:
		AttackCharacter(playerCharacters[currentActors[0]], enemyCharacters[currentActors[1]], pattack);
		PrintCurrentPhase(pattack);
		cin;
		return 0;

	case CurrentBattlePhase::AttackEnemy:
		eattack = rand() % 4;
		AttackCharacter(enemyCharacters[currentActors[1]], playerCharacters[currentActors[0]], eattack);
		PrintCurrentPhase(eattack);
		cin;
		return 0;

	default:
		return 0;
	}
}

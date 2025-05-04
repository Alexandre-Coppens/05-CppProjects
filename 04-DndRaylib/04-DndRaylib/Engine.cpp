#include <iostream>
#include <algorithm>
#include "Engine.h"
#include "ScreenDraw.h"
#include "Elements.h"

#include "Button.h"
#include "FlyingNumber.h"

using std::cout;
using std::to_string;

CurrentBattlePhase currentPhase;

struct AttackInfo;
struct Engine::AttackEvent;

Engine::Engine() {
}

void Engine::Start(){
	assets = AssetList::GetInstance();

	vector<DamageTypes> dragonTypes{ DamageTypes::Lighting, DamageTypes::Normal };
	vector<AttackName> dragonAttacks{ AttackName::MoltenBreath, AttackName::LightningCall, AttackName::MightyDive, AttackName::OldMagic };
	GameObject::CreateGameObject("DRAGON", new Character(&assets->SpriteList["imgCharDragon"], Vector2{ 350, 100 }, dragonTypes, dragonAttacks, float(rand() % 50), float(1000)));

	vector<DamageTypes> lichTypes{ DamageTypes::Necrotic, DamageTypes::Normal };
	vector<AttackName> lichAttacks{ AttackName::Fireball, AttackName::Poison, AttackName::Lightning, AttackName::OldMagic };
	GameObject::CreateGameObject("LICH", new Character(&assets->SpriteList["imgCharLich"], Vector2{ 350, 100 }, lichTypes, lichAttacks, float(rand() % 50), float(356)));

	vector<DamageTypes> golemTypes{ DamageTypes::Normal, DamageTypes::Normal };
	vector<AttackName> golemAttacks{ AttackName::ThrowRock, AttackName::Slam, AttackName::HeadSmasher, AttackName::OldMagic };
	GameObject::CreateGameObject("GOLEM", new Character(&assets->SpriteList["imgCharGolem"], Vector2{ 350, 100 }, golemTypes, golemAttacks, float(rand() % 50), float(500)));

	vector<DamageTypes> beholderTypes{ DamageTypes::Fire, DamageTypes::Cold };
	vector<AttackName> beholderAttacks{ AttackName::IceBreath, AttackName::Stun, AttackName::Chomp, AttackName::Fireball };
	GameObject::CreateGameObject("BEHOLDER", new Character(&assets->SpriteList["imgCharBeholder"], Vector2{ 350, 100 }, beholderTypes, beholderAttacks, float(rand() % 50), float(250)));

	vector<DamageTypes> mimicTypes{ DamageTypes::Lighting, DamageTypes::Piercing };
	vector<AttackName> mimicAttacks{ AttackName::Zap, AttackName::ShortCircuit, AttackName::Dive, AttackName::Triped };
	GameObject::CreateGameObject("MIMIC", new Character(&assets->SpriteList["imgCharMimic"], Vector2{ 350, 100 }, mimicTypes, mimicAttacks, float(rand() % 50), float(150)));

	vector<DamageTypes> skeletonTypes{ DamageTypes::Necrotic, DamageTypes::Slashing };
	vector<AttackName> skeletonAttacks{ AttackName::Slash, AttackName::Poison, AttackName::Triped, AttackName::Triped };
	GameObject::CreateGameObject("SKELETON", new Character(&assets->SpriteList["imgCharSkeleton"], Vector2{ 350, 100 }, skeletonTypes, skeletonAttacks, float(rand() % 50), float(75)));



	vector<DamageTypes> knightTypes{ DamageTypes::Slashing, DamageTypes::Fire };
	vector<AttackName> knightAttacks{ AttackName::Slash, AttackName::FireSword, AttackName::Smite, AttackName::Heal };
	GameObject::CreateGameObject("KNIGHT", new Character(&assets->SpriteList["imgCharBasic"], Vector2{ 50, 100 }, knightTypes, knightAttacks, float(rand() % 50), float(500)));

	vector<DamageTypes> rogueTypes{ DamageTypes::Piercing, DamageTypes::Necrotic };
	vector<AttackName> rogueAttacks{ AttackName::PiercingDagger, AttackName::ShadowDagger, AttackName::Poison, AttackName::Heal };
	GameObject::CreateGameObject("ROGUE", new Character(&assets->SpriteList["imgCharBasic"], Vector2{ 50, 100 }, rogueTypes, rogueAttacks, float(rand() % 50), float(300)));

	vector<DamageTypes> wizardTypes{ DamageTypes::Lighting, DamageTypes::Fire };
	vector<AttackName> wizardAttacks{ AttackName::Fireball, AttackName::Lightning, AttackName::Poison, AttackName::Heal };
	GameObject::CreateGameObject("WIZARD", new Character(&assets->SpriteList["imgCharBasic"], Vector2{ 50, 100 }, wizardTypes, wizardAttacks, float(rand() % 50), float(250)));

	vector<DamageTypes> barbarianTypes{ DamageTypes::Fire, DamageTypes::Cold };
	vector<AttackName> barbarianAttacks{ AttackName::Bludgeon, AttackName::HeadSmasher, AttackName::FireAxe, AttackName::IceAxe };
	GameObject::CreateGameObject("BARBARIAN", new Character(&assets->SpriteList["imgCharBasic"], Vector2{ 50, 100 }, barbarianTypes, barbarianAttacks, float(rand() % 50), float(450)));



	vector<DamageTypes> a{ DamageTypes::Fire, DamageTypes::Cold };
	vector<AttackName> b{ AttackName::Bludgeon, AttackName::HeadSmasher, AttackName::FireAxe, AttackName::IceAxe };
	GameObject::CreateGameObject("NONE", new Character(&assets->SpriteList[""], Vector2{ 50, 100 }, a, b, float(rand() % 50), float(9999)));

	enemyCharacters.push_back(dynamic_cast<Character*>(GameObject::GetGameObjectWithName("SKELETON")));
	enemyCharacters.push_back(dynamic_cast<Character*>(GameObject::GetGameObjectWithName("MIMIC")));
	enemyCharacters.push_back(dynamic_cast<Character*>(GameObject::GetGameObjectWithName("BEHOLDER")));
	enemyCharacters.push_back(dynamic_cast<Character*>(GameObject::GetGameObjectWithName("GOLEM")));
	enemyCharacters.push_back(dynamic_cast<Character*>(GameObject::GetGameObjectWithName("LICH")));
	enemyCharacters.push_back(dynamic_cast<Character*>(GameObject::GetGameObjectWithName("DRAGON")));
	enemyCharacters.push_back(dynamic_cast<Character*>(GameObject::GetGameObjectWithName("NONE")));

	playerCharacters.push_back(dynamic_cast<Character*>(GameObject::GetGameObjectWithName("KNIGHT")));
	playerCharacters.push_back(dynamic_cast<Character*>(GameObject::GetGameObjectWithName("ROGUE")));
	playerCharacters.push_back(dynamic_cast<Character*>(GameObject::GetGameObjectWithName("WIZARD")));
	playerCharacters.push_back(dynamic_cast<Character*>(GameObject::GetGameObjectWithName("BARBARIAN")));
	enemyCharacters.push_back(dynamic_cast<Character*>(GameObject::GetGameObjectWithName("NONE")));

	playerCharacters[0]->enabled = true;
	enemyCharacters[0]->enabled = true;

	GameObject::CreateGameObject("GOBtnAttack1", new Button(false, Vector2{ 75,310 }, Vector2{ 150, 50 }, & assets->SpriteList["imgUIButton"], 1));
	GameObject::CreateGameObject("GOBtnAttack2", new Button(false, Vector2{ 325,310 }, Vector2{ 150, 50 }, & assets->SpriteList["imgUIButton"], 2));
	GameObject::CreateGameObject("GOBtnAttack3", new Button(false, Vector2{ 75,410 }, Vector2{ 150, 50 }, & assets->SpriteList["imgUIButton"], 3));
	GameObject::CreateGameObject("GOBtnAttack4", new Button(false, Vector2{ 325,410 }, Vector2{ 150, 50 }, & assets->SpriteList["imgUIButton"], 4));

	currentPhase = CurrentBattlePhase::ChooseAttack;
	ChangeButtonDispositions();
	input = 0;
	pAttack = 0;
	eAttack = 0;
}

void Engine::Update() {
	if (events.size() > 0) {
		events[0].time -= GetFrameTime() * speed;
		if (events[0].time <= 0) {
			events.erase(events.begin());
			NextEvent();
		}
	}

	vector<GameObject*> goList = GameObject::GetAllGameObjects();
	for (GameObject* go : goList) {
		go->Update();
	}

	if (IsKeyPressed(KEY_TAB)) {
		if (speed == 1)speed = 10;
		else speed = 1;
	}

	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
		for (GameObject* go : goList) {
			if (go->IsCursorInBounds() && go->enabled) {
				input = go->Clicked();
				UserInput();
			}
		}
	}
}

void Engine::Draw() {
	BeginDrawing();
	DrawTexture(assets->SpriteList["imgBackground"], 0, 0, WHITE);
	vector<GameObject*> goList = GameObject::GetAllGameObjects();
	for (GameObject* go : goList) {
		if (go->enabled) go->Draw();
	}

	string text;
	Vector2 textAdd;
	string attackEffect;
	string confirmText;

	switch (currentPhase) {
	case CurrentBattlePhase::ConfirmAttack:
		text = attackInfos[playerCharacters[currentActors[0]]->attacks[pAttack]].name;
		textAdd = MeasureTextEx(AssetList::textFont["Alagard"], text.c_str(), 20, 5);
		DrawTextPro(AssetList::textFont["Alagard"], text.c_str(), Vector2{ (GetScreenWidth() - textAdd.x) * 0.5f, 400 - textAdd.y * 0.5f }, Vector2{ 0,0 }, 0, 20, 5, BLACK);

		text = to_string(attackInfos[playerCharacters[currentActors[0]]->attacks[pAttack]].damage);
		attackEffect = statusNames[attackInfos[playerCharacters[currentActors[0]]->attacks[pAttack]].status];

		confirmText = text + " damages and inflict " + attackEffect + ".";
		textAdd = MeasureTextEx(AssetList::textFont["Romulus"], confirmText.c_str(), 20, 5);
		DrawTextPro(AssetList::textFont["Romulus"], confirmText.c_str(), Vector2{ (GetScreenWidth() - textAdd.x) * 0.5f, 430 - textAdd.y * 0.5f }, Vector2{ 0,0 }, 0, 20, 5, BLACK);
		break;

	case CurrentBattlePhase::AttackPlayer:
		text = events[0].text;
		textAdd = MeasureTextEx(AssetList::textFont["Romulus"], text.c_str(), 15, 5);
		DrawTextPro(AssetList::textFont["Romulus"], text.c_str(), Vector2{ (GetScreenWidth() - textAdd.x) * 0.5f, 400 - textAdd.y * 0.5f }, Vector2{ 0,0 }, 0, 15, 5, BLACK);
		break;

	case CurrentBattlePhase::AttackEnemy:
		text = events[0].text;
		textAdd = MeasureTextEx(AssetList::textFont["Romulus"], text.c_str(), 15, 5);
		DrawTextPro(AssetList::textFont["Romulus"], text.c_str(), Vector2{ (GetScreenWidth() - textAdd.x) * 0.5f, 400 - textAdd.y * 0.5f }, Vector2{ 0,0 }, 0, 15, 5, BLACK);
		break;
	}



	EndDrawing();
}

int Engine::UserInput() {
	switch (currentPhase)
	{
	case CurrentBattlePhase::ChooseAttack:
		if (input >= 1 && input <= 4) {
			pAttack = input - 1;
			currentPhase = CurrentBattlePhase::ConfirmAttack;
			ChangeButtonDispositions();
		}
		return 0;

	case CurrentBattlePhase::ConfirmAttack:
		cout << input;
		if (input == 1) {
			if (playerCharacters[currentActors[0]]->speed + HasStatus(playerCharacters[currentActors[0]]->currentStatus, Status::Frost) ? -10 : 0 >= enemyCharacters[currentActors[1]]->speed + HasStatus(enemyCharacters[currentActors[1]]->currentStatus, Status::Frost) ? -10 : 0){
				currentPhase = CurrentBattlePhase::AttackPlayer;
			}
			else{
				currentPhase = CurrentBattlePhase::AttackEnemy;
			}
			eAttack = rand() % 3;
			ChangeButtonDispositions();
			lastPlayed = 0;
			AttackTurn();
		}
		if (input == 2) {
			currentPhase = CurrentBattlePhase::ChooseAttack;
			ChangeButtonDispositions();
		}
		return 0;
	}
}

void Engine::ChangeButtonDispositions() {
	vector<GameObject*> buttons = GameObject::GetAllGameObjectsWith(GameObjectType::Button);

	switch (currentPhase)
	{
	case CurrentBattlePhase::ChooseAttack:
		for (GameObject* button : buttons) {
			Button* b = dynamic_cast<Button*>(button);
			if (b->value <= 4) {
				b->enabled = true;
				b->text = attackInfos[playerCharacters[currentActors[0]]->attacks[b->value-1]].name;
			}
			else {
				b->enabled = false;
			}
		}
		return;

	case CurrentBattlePhase::ConfirmAttack:
		for (GameObject* button : buttons) {
			Button* b = dynamic_cast<Button*>(button);
			if (b->value <= 2) {
				b->enabled = true;
				if (b->value == 1) b->text = "Attack";
				else b->text = "Change";
			}
			else {
				b->enabled = false;
			}
		}
		return;


	case CurrentBattlePhase::AttackPlayer:
		for (GameObject* button : buttons) {
			button->enabled = false;
		}
		return;

	case CurrentBattlePhase::AttackEnemy:
		for (GameObject* button : buttons) {
			button->enabled = false;
		}
		return;
	}
}

void Engine::NextEvent() {
	if (events.size() > 0) {
		if (events[0].code[0] == 'p') DamageCharacter(enemyCharacters[currentActors[1]], events[0].attack);
		else if (events[0].code[0] == 'e') DamageCharacter(playerCharacters[currentActors[0]], events[0].attack);
		else if (events[0].code[0] == 'q') CloseWindow();
	}
	else{
		CheckDeath();
		if (lastPlayed == 11) {
			currentPhase = CurrentBattlePhase::ChooseAttack;
			ChangeButtonDispositions();
		}
		if (lastPlayed == 10 || lastPlayed == 1) {
			if (lastPlayed == 1) {
				currentPhase = CurrentBattlePhase::AttackPlayer;
			}
			else {
				currentPhase = CurrentBattlePhase::AttackEnemy;
			}
			ChangeButtonDispositions();
			AttackTurn();
		}
	}
}

void Engine::AttackTurn() {
	Character* attack;
	Character* defend;
	bool isPlayer;

	if (currentPhase == CurrentBattlePhase::AttackPlayer) {
		attack = playerCharacters[currentActors[0]];
		defend = enemyCharacters[currentActors[1]];
		isPlayer = true;
		lastPlayed += 10;
	}
	else{
		defend = playerCharacters[currentActors[0]];
		attack = enemyCharacters[currentActors[1]];
		isPlayer = false;
		lastPlayed += 1;
	}

	if (!EffectsBeforeAttack(attack)) {
		if(isPlayer) events.push_back(AttackEvent{ 2, "p", attack->name + " use " + attackInfos[playerCharacters[currentActors[0]]->attacks[pAttack]].name + " !\n\n It deals " + to_string(attackInfos[playerCharacters[currentActors[0]]->attacks[pAttack]].damage) + " damages and inflict " + statusNames[attackInfos[playerCharacters[currentActors[0]]->attacks[pAttack]].status] + " !", attackInfos[playerCharacters[currentActors[0]]->attacks[pAttack]] });
		else events.push_back(AttackEvent{ 2, "e", attack->name + " use " + attackInfos[enemyCharacters[currentActors[1]]->attacks[eAttack]].name + " !\n\n It deals " + to_string(attackInfos[enemyCharacters[currentActors[1]]->attacks[eAttack]].damage) + " damages and inflict " + statusNames[attackInfos[enemyCharacters[currentActors[1]]->attacks[eAttack]].status] + " !", attackInfos[enemyCharacters[currentActors[1]]->attacks[eAttack]] });
	}
	for (AttackEvent e : events) {
		if (e.attack.status == Status::Heal) {
			if (e.code == "p") e.code = "e";
			else e.code = "p";
		}
		if (e.code == "e") playerCharacters[currentActors[0]]->currentStatus.push_back(e.attack.status);
		else enemyCharacters[currentActors[1]]->currentStatus.push_back(e.attack.status);
	}
	EffectsAfterAttack(defend, !isPlayer);
	Heal(attack, isPlayer);

	NextEvent();
}

bool Engine::EffectsBeforeAttack(Character* attack) { // Return true if attacker is successfuly paralised
	vector<Status> statusList;
	statusList = attack->currentStatus;
	if (statusList.size() == 0) return false;
	for (int i = 0; i < statusList.size(); i++)
	{
		if (rand() % 3 == 0 || statusList[i] == Status::None) {
			statusList.erase(find(statusList.begin(), statusList.end(), statusList[i]));
			i--;
			break;
		}

		if (statusList[i] == Status::Electric) {
			if (rand() % 4 == 0)
			{
				currentPhase = CurrentBattlePhase::Paralysed;
				attack->currentStatus = statusList;
				events.push_back(AttackEvent{ 1, "s", attack->name + " is Paralysed! Turn Skipped.", AttackInfo{DamageTypes::Normal, 0, Status::None, ""}});
				return true;
			}
		}
	}
	attack->currentStatus = statusList;
	return false;
}

bool Engine::EffectsAfterAttack(Character* defend, bool isPlayer)
{
	vector<Status> statusList;
	AttackInfo attack;
	statusList = defend->currentStatus;
	int damage;
	if (statusList.size() == 0) return false;
	for (int i = 0; i < statusList.size(); i++)
	{
		switch (statusList[i])
		{
		case Status::Poisoned:
			damage = (int)(defend->maxHealth / 20);
			events.push_back(AttackEvent{ 1, (!isPlayer?"p":"e"), defend->name + " is Poisoned! He will take " + to_string(damage) + ".", AttackInfo{DamageTypes::Necrotic, damage, Status::None, ""} });
			break;

		case Status::Burn:
			damage = (int)(defend->maxHealth / 20);
			events.push_back(AttackEvent{ 1, (!isPlayer ?"p":"e"), defend->name + " is Burning! He will take " + to_string(damage) + ".", AttackInfo{DamageTypes::Fire, damage, Status::None, ""} });
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
	int heal;
	if (statusList.size() == 0) return;
	for (int i = 0; i < statusList.size(); i++)
	{
		switch (statusList[i])
		{
		case Status::Heal:
			heal = -(int)(attacker->maxHealth / 20);
			events.push_back(AttackEvent{ 1, (!isPlayer ? "p" : "e"), attacker->name + " is Healing! He is restoring " + to_string(heal) + " health.", AttackInfo{DamageTypes::Normal, heal, Status::None, ""} });
			return;

		default:
			break;
		}
	}
	return;
}

void Engine::AttackCharacter(Character* attacker, Character* defender, short attackChoice) {
	AttackInfo info = attackInfos[attacker->attacks[attackChoice]];
	DamageCharacter(defender, info);
}


void Engine::DamageCharacter(Character* character, AttackInfo attack){
	int damages = attack.damage * GetWeakness(attack.damageType, character->elementalTypes);
	GameObject::CreateGameObject("NumberParticle" + to_string(std::rand()), new FlyingNumber(character->position, damages));
	character->health -= damages;
	if(character->health > character->maxHealth) character->health = character->maxHealth;
}

void Engine::CheckDeath()
{
	if (enemyCharacters[currentActors[1]]->health <= 0) {
		lastPlayed = 11;
		currentActors[1]++;
		ChangeCharacter();
		if (currentActors[1] == 6 ) {
			events.push_back(AttackEvent{ 10, "",  "Well done! You win!", AttackInfo{DamageTypes::Normal, 0, Status::None, ""} });
			events.push_back(AttackEvent{ 10, "q",  "Well done! You win!", AttackInfo{DamageTypes::Normal, 0, Status::None, ""} });
			NextEvent();
		}
	}
	else if (playerCharacters[currentActors[0]]->health <= 0)
	{
		lastPlayed = 11;
		currentActors[0]++;
		ChangeCharacter();
		if (currentActors[0] == 4 ) {
			events.push_back(AttackEvent{ 10, "",  "Your Team is Dead. Game Over.", AttackInfo{DamageTypes::Normal, 0, Status::None, ""} });
			events.push_back(AttackEvent{ 10, "q",  "Your Team is Dead. Game Over.", AttackInfo{DamageTypes::Normal, 0, Status::None, ""} });
			NextEvent();
		}
	}
}

void Engine::ChangeCharacter() {
	for (Character* character : playerCharacters) {
		character->enabled = false;
	}
	playerCharacters[currentActors[0]]->enabled = true;
	for (Character* character : enemyCharacters) {
		if (character != nullptr) {
			character->enabled = false;
		}
	}
	enemyCharacters[currentActors[1]]->enabled = true;
}

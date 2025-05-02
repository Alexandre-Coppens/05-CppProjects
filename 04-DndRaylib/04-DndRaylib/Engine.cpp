#include <iostream>
#include "Engine.h"
#include "ScreenDraw.h"
#include "Elements.h"

#include "Button.h"
#include "FlyingNumber.h"

using std::cout;
using std::to_string;

CurrentBattlePhase currentPhase;

Engine::Engine() {
}

void Engine::Start(){
	assets = AssetList::GetInstance();

	vector<DamageTypes> dragonTypes{ DamageTypes::Lighting, DamageTypes::Normal };
	vector<AttackName> dragonAttacks{ AttackName::MoltenBreath, AttackName::LightningCall, AttackName::MightyDive, AttackName::OldMagic };
	GameObject::CreateGameObject("DRAGON", new Character(&assets->SpriteList["imgCharBasic"], Vector2{ 350, 100 }, dragonTypes, dragonAttacks, float(rand() % 50), float(1000)));

	vector<DamageTypes> lichTypes{ DamageTypes::Necrotic, DamageTypes::Normal };
	vector<AttackName> lichAttacks{ AttackName::Fireball, AttackName::Poison, AttackName::Lightning, AttackName::OldMagic };
	GameObject::CreateGameObject("LICH", new Character(&assets->SpriteList["imgCharBasic"], Vector2{ 350, 100 }, lichTypes, lichAttacks, float(rand() % 50), float(356)));

	vector<DamageTypes> golemTypes{ DamageTypes::Normal, DamageTypes::Normal };
	vector<AttackName> golemAttacks{ AttackName::ThrowRock, AttackName::Slam, AttackName::HeadSmasher, AttackName::OldMagic };
	GameObject::CreateGameObject("GOLEM", new Character(&assets->SpriteList["imgCharBasic"], Vector2{ 350, 100 }, golemTypes, golemAttacks, float(rand() % 50), float(500)));

	vector<DamageTypes> beholderTypes{ DamageTypes::Fire, DamageTypes::Cold };
	vector<AttackName> beholderAttacks{ AttackName::IceBreath, AttackName::Stun, AttackName::Chomp, AttackName::Fireball };
	GameObject::CreateGameObject("BEHOLDER", new Character(&assets->SpriteList["imgCharBasic"], Vector2{ 350, 100 }, beholderTypes, beholderAttacks, float(rand() % 50), float(250)));

	vector<DamageTypes> mimicTypes{ DamageTypes::Lighting, DamageTypes::Piercing };
	vector<AttackName> mimicAttacks{ AttackName::Zap, AttackName::ShortCircuit, AttackName::Dive, AttackName::Triped };
	GameObject::CreateGameObject("MIMIC", new Character(&assets->SpriteList["imgCharBasic"], Vector2{ 350, 100 }, mimicTypes, mimicAttacks, float(rand() % 50), float(150)));

	vector<DamageTypes> skeletonTypes{ DamageTypes::Necrotic, DamageTypes::Slashing };
	vector<AttackName> skeletonAttacks{ AttackName::Slash, AttackName::Poison, AttackName::Triped, AttackName::Triped };
	GameObject::CreateGameObject("SKELETON", new Character(&assets->SpriteList["imgCharBasic"], Vector2{ 350, 100 }, skeletonTypes, skeletonAttacks, float(rand() % 50), float(75)));



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

	enemyCharacters.push_back(dynamic_cast<Character*>(GameObject::GetGameObjectWithName("SKELETON")));
	enemyCharacters.push_back(dynamic_cast<Character*>(GameObject::GetGameObjectWithName("MIMIC")));
	enemyCharacters.push_back(dynamic_cast<Character*>(GameObject::GetGameObjectWithName("BEHOLDER")));
	enemyCharacters.push_back(dynamic_cast<Character*>(GameObject::GetGameObjectWithName("GOLEM")));
	enemyCharacters.push_back(dynamic_cast<Character*>(GameObject::GetGameObjectWithName("LICH")));
	enemyCharacters.push_back(dynamic_cast<Character*>(GameObject::GetGameObjectWithName("DRAON")));

	playerCharacters.push_back(dynamic_cast<Character*>(GameObject::GetGameObjectWithName("KNIGHT")));
	playerCharacters.push_back(dynamic_cast<Character*>(GameObject::GetGameObjectWithName("ROGUE")));
	playerCharacters.push_back(dynamic_cast<Character*>(GameObject::GetGameObjectWithName("WIZARD")));
	playerCharacters.push_back(dynamic_cast<Character*>(GameObject::GetGameObjectWithName("BARBARIAN")));

	playerCharacters[0]->enabled = true;
	enemyCharacters[0]->enabled = true;

	GameObject::CreateGameObject("GOBtnAttack1", new Button(false, Vector2{ 75,300 }, Vector2{ 150, 50 }, & assets->SpriteList["imgUIButton"], 1));
	GameObject::CreateGameObject("GOBtnAttack2", new Button(false, Vector2{ 325,300 }, Vector2{ 150, 50 }, & assets->SpriteList["imgUIButton"], 2));
	GameObject::CreateGameObject("GOBtnAttack3", new Button(false, Vector2{ 75,400 }, Vector2{ 150, 50 }, & assets->SpriteList["imgUIButton"], 3));
	GameObject::CreateGameObject("GOBtnAttack4", new Button(false, Vector2{ 325,400 }, Vector2{ 150, 50 }, & assets->SpriteList["imgUIButton"], 4));

	currentPhase = CurrentBattlePhase::ChooseAttack;
	ChangeButtonDispositions();
	input = 0;
	pAttack = 0;
	eAttack = 0;
}

void Engine::Update() {
	//if (playerCharacters[currentActors[0]].speed + HasStatus(playerCharacters[currentActors[0]].currentStatus,Status::Frost)?-10:0 >= enemyCharacters[currentActors[1]].speed + HasStatus(enemyCharacters[currentActors[1]].currentStatus, Status::Frost) ? -10 : 0) {
	//	currentPhase = CurrentBattlePhase::AttackPlayer;
	//	UserInput();
	//	currentPhase = CurrentBattlePhase::AttackEnemy;
	//	UserInput();
	//}
	//else {
	//	currentPhase = CurrentBattlePhase::AttackEnemy;
	//	UserInput();
	//	currentPhase = CurrentBattlePhase::AttackPlayer;
	//	UserInput();
	//}
	//CheckDeath();

	vector<GameObject*> goList = GameObject::GetAllGameObjects();
	for (GameObject* go : goList) {
		go->Update();
	}

	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
		GameObject::CreateGameObject("posNbr" + to_string(std::rand()), new FlyingNumber(GetMousePosition(), 20));
		for (GameObject* go : goList) {
			if (go->IsCursorInBounds() && go->enabled) {
				input = go->Clicked();
				UserInput();
			}
		}
	}
	if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) {
		GameObject::CreateGameObject("negNbr" + to_string(std::rand()), new FlyingNumber(GetMousePosition(), -20));
	}
}

void Engine::Draw() {
	BeginDrawing();
	ClearBackground(GRAY);
	vector<GameObject*> goList = GameObject::GetAllGameObjects();
	for (GameObject* go : goList) {
		if (go->enabled) go->Draw();
	}

	switch (currentPhase) {
	case CurrentBattlePhase::ConfirmAttack:
		string attackName = attackInfos[playerCharacters[currentActors[0]]->attacks[pAttack]].name;
		Vector2 textAdd = MeasureTextEx(AssetList::textFont["Alagard"], attackName.c_str(), 20, 5);
		DrawTextPro(AssetList::textFont["Alagard"], attackName.c_str(), Vector2{ (GetScreenWidth() - textAdd.x) * 0.5f, 400 - textAdd.y * 0.5f }, Vector2{ 0,0 }, 0, 20, 5, BLACK);

		string attackDamage = to_string(attackInfos[playerCharacters[currentActors[0]]->attacks[pAttack]].damage);
		string attackEffect = statusNames[attackInfos[playerCharacters[currentActors[0]]->attacks[pAttack]].status];

		string confirmText = attackDamage + " damages and inflict " + attackEffect + ".";
		textAdd = MeasureTextEx(AssetList::textFont["Setback"], confirmText.c_str(), 20, 5);
		DrawTextPro(AssetList::textFont["Setback"], confirmText.c_str(), Vector2{ (GetScreenWidth() - textAdd.x) * 0.5f, 430 - textAdd.y * 0.5f }, Vector2{ 0,0 }, 0, 20, 5, BLACK);
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
			ChangeButtonDispositions();
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

//void Engine::PrintCurrentPhase(int choice) {
//	DrawScreen(&playerCharacters[currentActors[0]], &enemyCharacters[currentActors[1]], currentPhase, choice);
//}
//
//int Engine::WaitForPlayerInput() {
//	vector<GameObject*> buttons = GameObject::GetAllGameObjectsWith(GameObjectType::Button);
//
//	for (int i = 0; i < 4; i++) {
//		Button* b = dynamic_cast<Button*>(buttons[i]);
//		b->text = attackInfos[playerCharacters[currentActors[0]].attacks[i]].name;
//		b->Draw();
//	}
//	EndDrawing();
//	while (!IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
//	}
//	Vector2 mousePos = GetMousePosition();
//
//	for (GameObject* x : buttons) {
//		if (Button* button = static_cast<Button*>(x)) {
//			if (button->IsCursorInBounds())return button->value;
//		}
//	}
//	return 0;
//}
//
//void Engine::AttackCharacter(Character* attacker, Character* defender, short attackChoice) {
//	AttackInfo info = attackInfos[attacker->attacks[attackChoice]];
//	DamageCharacter(defender, info);
//	if(info.status != Status::Heal) defender->currentStatus.push_back(info.status);
//	else attacker->currentStatus.push_back(info.status);
//}
//
//void Engine::DamageCharacter(Character* defender, AttackInfo attack){
//	defender->health -= attack.damage * GetWeakness(attack.damageType, defender->elementalTypes);
//	if(defender->health > defender->maxHealth) defender->health = defender->maxHealth;
//}
//
//bool Engine::EffectsBeforeAttack(Character* attacker, bool isPlayer){ // Return true if attacker is successfuly paralised{
//	vector<Status> statusList;
//	statusList = attacker->currentStatus;
//	bool ret = false;
//	if (statusList.size() == 0) return false;
//	for (int i = 0; i < statusList.size(); i++)
//	{
//		if (rand() % 3 == 0) {
//			statusList.erase(find(statusList.begin(), statusList.end(), statusList[i]));
//			i--;
//			break;
//		}
//
//		if(statusList[i] == Status::Electric) {
//			if (rand() % 4 == 0)
//			{
//				currentPhase = CurrentBattlePhase::Paralysed;
//				PrintCurrentPhase(isPlayer?0:1);
//				attacker->currentStatus = statusList;
//				return true;
//			}
//		}
//
//		if (statusList[i] == Status::None) {
//			statusList.erase(find(statusList.begin(), statusList.end(), Status::None));
//			i--;
//			break;
//		}
//	}
//	attacker->currentStatus = statusList;
//	return ret;
//}
//
//bool Engine::EffectsAfterAttack(Character* defender, bool isPlayer)
//{
//	vector<Status> statusList;
//	AttackInfo attack;
//	statusList = defender->currentStatus;
//	if (statusList.size() == 0) return false;
//	for (int i = 0; i < statusList.size(); i++)
//	{
//		switch (statusList[i])
//		{
//		case Status::Poisoned:
//			attack.damageType = DamageTypes::Necrotic;
//			attack.damage = (int)(defender->maxHealth / 20);
//			attack.status = Status::None;
//			attack.name = "Poison";
//			DamageCharacter(defender, attack);
//
//			currentPhase = CurrentBattlePhase::Poisoned;
//			PrintCurrentPhase(isPlayer ? 0 : 1);
//			break;
//
//		case Status::Burn:
//			attack.damageType = DamageTypes::Fire;
//			attack.damage = (int)(defender->maxHealth / 20);
//			attack.status = Status::None;
//			attack.name = "Fire";
//			DamageCharacter(defender, attack);
//
//			currentPhase = CurrentBattlePhase::Burned;
//			PrintCurrentPhase(isPlayer ? 0 : 1);
//			break;
//
//		default:
//			break;
//		}
//	}
//	return true;
//}
//
//void Engine::Heal(Character* attacker, bool isPlayer)
//{
//	vector<Status> statusList;
//	AttackInfo attack;
//	statusList = attacker->currentStatus;
//	if (statusList.size() == 0) return;
//	for (int i = 0; i < statusList.size(); i++)
//	{
//		switch (statusList[i])
//		{
//		case Status::Heal:
//			attack.damageType = DamageTypes::Normal;
//			attack.damage = -(int)(attacker->maxHealth / 20);
//			attack.status = Status::None;
//			attack.name = "Heal";
//			DamageCharacter(attacker, attack);
//			currentPhase = CurrentBattlePhase::Healed;
//			PrintCurrentPhase(isPlayer ? 0 : 1);
//			return;
//
//		default:
//			break;
//		}
//	}
//	return;
//}
//
//void Engine::CheckDeath()
//{
//	if (enemyCharacters[currentActors[1]].health <= 0) {
//		currentPhase = CurrentBattlePhase::Died;
//		PrintCurrentPhase(0);
//		currentActors[1]++;
//		if (currentActors[1] == enemyCharacters.size()) {
//			void CloseWindow(void);
//		}
//	}
//	else if (playerCharacters[currentActors[0]].health <= 0)
//	{
//		currentPhase = CurrentBattlePhase::Died;
//		PrintCurrentPhase(1);
//		currentActors[0]++;
//		if (currentActors[0] == playerCharacters.size()) {
//			void CloseWindow(void);
//		}
//	}
//}

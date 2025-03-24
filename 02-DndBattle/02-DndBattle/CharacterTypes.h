#pragma once
#include <string>
#include <vector>

using std::string;
using std::vector;

enum class CharacterTypes {
	Cold,		//
	Fire,		//
	Lighting,	//
	Golem,		//Normal
	Lich,		//Necrotic
	Dragon,		//Lighting

	Knight,		//Slashing + Fire
	Rogue,		//Piercing + Necrotic
	Wizard,		//Lighting + Fire
	Barbarian,	//Fire + Cold
};

class CharacterType {
public:
	vector<string> dragon;

	CharacterType();
	void Start();
	vector<string>* GetSprite(CharacterTypes character);
};
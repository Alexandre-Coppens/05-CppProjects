#pragma once
#include <string>
#include <vector>

using std::string;
using std::vector;

enum class CharacterTypes {
	Skeleton,	//Necrotic, Slashing
	Mimic,		//Ligthing, Piercing 
	Beholder,	//Fire, Cold
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
	vector<string> lich;
	vector<string> golem;
	vector<string> beholder;
	vector<string> mimic;
	vector<string> skeleton;

	vector<string> knight;
	vector<string> rogue;
	vector<string> wizard;
	vector<string> barbarian;

	vector<string> noImageFound;

	CharacterType();
	vector<string>* GetSprite(CharacterTypes character);
};
#include <string>
#include <vector>
#include "CharacterTypes.h"

using std::string;
using std::vector;

CharacterType::CharacterType() {

}

void CharacterType::Start() {
    dragon = vector<string>
          { "         /|    /   \n",
            "      __/_|/ // |  \n",
            "    //o  o   ] /   \n",
            "   [ °°      ]    \n",
            "     v v |  |        \n",
            "     ___/  /|        \n",
            "  /__ | | | |         " };
}

vector<string>* CharacterType::GetSprite(CharacterTypes character) {
	switch (character) {
	case CharacterTypes::Dragon:
        return &dragon;
	}
}
#include <string>
#include <vector>
#include "CharacterTypes.h"

using std::string;
using std::vector;

CharacterType::CharacterType() {
    dragon = vector<string>
    { "         /|    /     \n",
      "      __/_|/ // |    \n",
      "    //o  o   ] /     \n",
      "   [ **      ]       \n",
      "     v v |  |        \n",
      "     ___/  /|        \n",
      "  /__ | | | |        \n" };

    lich = vector<string>
    { "\n",
     "\n",
     "    |nOn|nn|          \n",
     "     O ^ O |  O       \n",
     "      '''|    T       \n",
     "     /    |---|       \n",
     "     |/ N |   |       \n" };

    golem = vector<string>
    { "\n",
     "\n",
     "      _______         \n",
     "     [       ]        \n",
     "     [ o  o  ]        \n",
     "    ____/ /|          \n",
     "   [HHHO] N           \n" };

    beholder = vector<string>
    { "     O        O       \n",
     "    //------//   _O   \n",
     "   {   ---    }_/     \n",
     "  {   | O |   }___O   \n",
     "   {  _---_ _--__O    \n",
     "    |/ |/ |/ }        \n",
     "   _______________    \n" };

    mimic = vector<string>
    { "\n",
     "      [---------____  \n",
     "      /-|/--|/ ---/ ] \n",
     "         /        | | \n",
     "     /|____/|___ / /  \n",
     "    [       ]      ]  \n",
     "    [_______]______]  \n" };

    skeleton = vector<string>
    { "\n",
     "\n",
     "     ------           \n",
     "     O ^ O |  /       \n",
     "      '''|   /        \n",
     "       /-T-oT         \n",
     "        / N           \n" };



    knight = vector<string>
    { "      _NNN_          \n",
     "     /  N   |    _    \n",
     "     |==_== |   / |   \n",
     "     |__|__ /  / /    \n",
     "    /|-___--| / /     \n",
     "    O|-___--|-O-      \n",
     "      |H  |H /        \n" };

    rogue = vector<string>
    { "        ______        \n",
     "      / ____  |       \n",
     "   _  |/O  O| |__    _\n",
     "  ||  || __ | |  |  //\n",
     "  )| /| /_--| |__| )/ \n",
     "    O |/=o==|  |   O  \n",
     "       |H  |H|        \n" };

    wizard = vector<string>
    { "           __/|       \n",
     "        _/____|       \n",
     "    <_/_-----__|_>    \n",
     "  *X*  |O  O w|__     \n",
     "   |  _|wwww-/ /      \n",
     "   O/  | w |  |_      \n",
     "   |   ||---|   |     \n" };

    barbarian = vector<string>
    { "      _____           \n",
     "    /   __ -    ___   \n",
     "   |-/-/ O ||  / _ -- \n",
     "   | /¤¤   // |/ //- )\n",
     "   /|-__---|--_ // |/ \n",
     "   O||___|/|   O/     \n",
     "    |H   |H|  //      \n" };

    noImageFound = { "\n", "\n", "NO\n", "IMAGE\n", "FOUND\n", "\n", "\n" };
}

vector<string>* CharacterType::GetSprite(CharacterTypes character) {
    switch (character) {
    case CharacterTypes::Dragon:
        return &dragon;
    case CharacterTypes::Lich:
        return &lich;
    case CharacterTypes::Golem:
        return &golem;
    case CharacterTypes::Beholder:
        return &beholder;
    case CharacterTypes::Mimic:
        return &mimic;
    case CharacterTypes::Skeleton:
        return &skeleton;

    case CharacterTypes::Knight:
        return &knight;
    case CharacterTypes::Rogue:
        return &rogue;
    case CharacterTypes::Wizard:
        return &wizard;
    case CharacterTypes::Barbarian:
        return &barbarian;

    default:
        return &noImageFound;
    }
}
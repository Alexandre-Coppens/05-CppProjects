#include <iostream>
#include <string>
#include <vector>
#include "Character.h"
#include "Engine.h"

using std::string;
using std::vector;

Engine engine;

int main()
{
	srand(time(NULL));
	while (true) {
		engine.Update();
	}
}
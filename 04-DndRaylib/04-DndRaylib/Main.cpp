#include <string>
#include "Engine.h"
#include "AssetsList.h"

using std::string;
Engine engine;

int main()
{
    InitWindow(550, 500, "Raylib");
    SetTargetFPS(60);

    InitAudioDevice();

	engine.Start();

	srand(time(NULL));
	while (true) {
		engine.Update();
	}
}
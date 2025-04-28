#include <iostream>
#include <string>
#include "Engine.h"
#include "AssetsList.h"

using std::string;

AssetList assets;
Engine engine;

int main()
{
    InitWindow(800, 500, "Raylib");
    SetTargetFPS(60);

    InitAudioDevice();

	engine.Start();

	srand(time(NULL));
	while (true) {
		engine.Update();
	}
}
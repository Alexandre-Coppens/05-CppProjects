#include <iostream>
#include <string>
#include "Engine.h"
#include "AssetsList.h"
#include "Main.h"

using std::string;
Engine engine;

int main()
{
    InitWindow(550, 500, "Raylib");
    SetTargetFPS(60);

    InitAudioDevice();

	engine.Start();

	srand(time(NULL));
    while (!WindowShouldClose()){
        UpdateMusicStream(AssetList::music);
		engine.Update();
		engine.Draw();
	}

    UnloadMusicStream(AssetList::music);

    CloseAudioDevice();
    CloseWindow();
}
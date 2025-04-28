#include <iostream>
#include <string>
#include <vector>
#include "Raylib.h"
#include "Character.h"
#include "Engine.h"

using std::string;
using std::vector;

Texture2D Img_Eff_Fire;
Texture2D Img_Eff_Poison;
Texture2D Img_Eff_Paralysis;
Texture2D Img_Eff_Ice;
Texture2D Img_Character;

Font textFont;

Music music;

Engine engine;

int main()
{
    InitWindow(800, 500, "Raylib");
    SetTargetFPS(60);
    InitAudioDevice();

    Image imgEffFire = LoadImage("resources/Flames.png");
    Image imgEffPoison = LoadImage("resources/Poison.png");
    Image imgEffParalysis = LoadImage("resources/Paralysis.png");
    Image imgEffIced = LoadImage("resources/Iced.png");
    Image imgCharacter = LoadImage("resources/Character.png");

    textFont = LoadFont("resources/fonts/mecha.png");
    music = LoadMusicStream("resources/balatro.mp3");

    Img_Eff_Fire = LoadTextureFromImage(imgEffFire);
    Img_Eff_Ice = LoadTextureFromImage(imgEffIced);
    Img_Eff_Paralysis = LoadTextureFromImage(imgEffParalysis);
    Img_Eff_Poison = LoadTextureFromImage(imgEffPoison);
    Img_Character = LoadTextureFromImage(imgCharacter);
    UnloadImage(imgEffFire);
    UnloadImage(imgEffIced);
    UnloadImage(imgEffParalysis);
    UnloadImage(imgEffPoison);
    UnloadImage(imgCharacter);

    SetMusicVolume(music, 2);
    PlayMusicStream(music);

	srand(time(NULL));
	while (true) {
		engine.Update();
	}
}
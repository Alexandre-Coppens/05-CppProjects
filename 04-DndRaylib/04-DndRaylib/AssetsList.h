#ifndef ASSETSLIST_H
#define ASSETSLIST_H

#include <string>
#include <vector>
#include <map>
#include "Raylib.h"

using std::string;
using std::vector;
using std::map;

class AssetList {
private:
    static Texture2D textureTemp;
    static vector<Texture2D> Sprites;
    static Font textFont;
    static Music music;

    static AssetList* instance;

public:
    static map<string, Texture2D*> SpriteList;

private:
    static void LoadTexture2D(string name, string link) {
        Image temp = LoadImage(link.c_str());
        textureTemp = LoadTextureFromImage(temp);
        Sprites.push_back(textureTemp);
        SpriteList[name] = &Sprites[Sprites.size() - 1];
        UnloadImage(temp);
    }

    AssetList() {
        LoadTexture2D("imgEffPoison", "resources/Poison.png");
        LoadTexture2D("imgEffParalysis", "resources/Paralysis.png");
        LoadTexture2D("imgEffIced", "resources/Iced.png");
        LoadTexture2D("imgEffFlames", "resources/Flames.png");
        LoadTexture2D("imgCharBasic", "resources/Character.png");
        LoadTexture2D("imgUnknown", "resources/Unknown.png");
        LoadTexture2D("Heal", "resources/Heal.png");

        textFont = LoadFont("resources/fonts/mecha.png");
        music = LoadMusicStream("resources/balatro.mp3");

        SetMusicVolume(music, 2);
        PlayMusicStream(music);

        instance = this;
    }

public:
    static AssetList* getInstance() {
        return instance;
    }

};

#endif // ASSETSLIST_H
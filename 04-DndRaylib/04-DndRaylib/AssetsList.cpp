#include "AssetsList.h"

AssetList* AssetList::instance = nullptr;
Font AssetList::textFont;
map<string, Texture2D> AssetList:: SpriteList;

AssetList::AssetList() {
    if (SpriteList.size() > 0) return;
    LoadTexture2D("imgEffPoison", "resources/Poison.png");
    LoadTexture2D("imgEffParalysis", "resources/Paralysis.png");
    LoadTexture2D("imgEffIced", "resources/Iced.png");
    LoadTexture2D("imgEffFlames", "resources/Flames.png");
    LoadTexture2D("imgCharBasic", "resources/Character.png");
    LoadTexture2D("imgUnknown", "resources/Unknown.png");
    LoadTexture2D("Heal", "resources/Heal.png");

    textFont = LoadFont("resources/fonts/alagard.png");
    music = LoadMusicStream("resources/balatro.mp3");

    SetMusicVolume(music, 2);
    PlayMusicStream(music);
}

AssetList::~AssetList(){
}

void AssetList::LoadTexture2D(string name, string link){
    Image temp = LoadImage(link.c_str());
    textureTemp = LoadTextureFromImage(temp);
    SpriteList[name] = textureTemp;
    UnloadImage(temp);
}

AssetList* AssetList::GetInstance() {
    if (instance == nullptr) {
        instance = new AssetList();
    }
    return instance;
}

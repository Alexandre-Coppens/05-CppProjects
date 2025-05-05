#include "AssetsList.h"

Texture2D AssetList::textureTemp;
Music AssetList::music;
AssetList* AssetList::instance = nullptr;
map<string, Font> AssetList::textFont;
map<string, Texture2D> AssetList:: SpriteList;

AssetList::AssetList() {
    if (SpriteList.size() > 0) return;
    LoadTexture2D("imgEffPoison", "resources/Poison.png");
    LoadTexture2D("imgEffParalysis", "resources/Paralysis.png");
    LoadTexture2D("imgEffIced", "resources/Iced.png");
    LoadTexture2D("imgEffFlames", "resources/Flames.png");
    LoadTexture2D("imgCharBasic", "resources/Character.png");
    LoadTexture2D("imgCharSkeleton", "resources/Skeleton.png");
    LoadTexture2D("imgCharMimic", "resources/Mimic.png");
    LoadTexture2D("imgCharBeholder", "resources/Beholder.png");
    LoadTexture2D("imgCharGolem", "resources/Golem.png");
    LoadTexture2D("imgCharLich", "resources/Lich.png");
    LoadTexture2D("imgCharDragon", "resources/Dragon.png");
    LoadTexture2D("imgCharKnight", "resources/Knight.png");
    LoadTexture2D("imgCharRogue", "resources/Rogue.png");
    LoadTexture2D("imgCharWizard", "resources/Wizard.png");
    LoadTexture2D("imgCharBarbarian", "resources/Barbarian.png");
    LoadTexture2D("", "resources/Unknown.png");
    LoadTexture2D("imgEffHeal", "resources/Heal.png");
    LoadTexture2D("imgUIButton", "resources/Button.png");
    LoadTexture2D("imgBackground", "resources/Background.png");

    textFont["Alagard"] = LoadFont("resources/fonts/alagard.png");
    textFont["Romulus"] = LoadFont("resources/fonts/romulus.png");
    textFont["Setback"] = LoadFont("resources/fonts/setback.png");
    music = LoadMusicStream("resources/FFCTBattle.mp3");

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

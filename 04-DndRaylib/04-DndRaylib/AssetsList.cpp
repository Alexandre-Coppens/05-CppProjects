#include "AssetsList.h"

Texture2D AssetList::textureTemp;
Music AssetList::music;
AssetList* AssetList::instance = nullptr;
map<string, Font> AssetList::textFont;
map<string, Texture2D> AssetList:: SpriteList;

AssetList::AssetList() {
    if (SpriteList.size() > 0) return;
    LoadTexture2D("imgEffPoison", "G:/Github/05-CppProjects/04-DndRaylib/04-DndRaylib/resources/Poison.png");
    LoadTexture2D("imgEffParalysis", "G:/Github/05-CppProjects/04-DndRaylib/04-DndRaylib/resources/Paralysis.png");
    LoadTexture2D("imgEffIced", "G:/Github/05-CppProjects/04-DndRaylib/04-DndRaylib/resources/Iced.png");
    LoadTexture2D("imgEffFlames", "G:/Github/05-CppProjects/04-DndRaylib/04-DndRaylib/resources/Flames.png");
    LoadTexture2D("imgCharBasic", "G:/Github/05-CppProjects/04-DndRaylib/04-DndRaylib/resources/Character.png");
    LoadTexture2D("imgCharSkeleton", "G:/Github/05-CppProjects/04-DndRaylib/04-DndRaylib/resources/Skeleton.png");
    LoadTexture2D("imgCharMimic", "G:/Github/05-CppProjects/04-DndRaylib/04-DndRaylib/resources/Mimic.png");
    LoadTexture2D("imgCharBeholder", "G:/Github/05-CppProjects/04-DndRaylib/04-DndRaylib/resources/Beholder.png");
    LoadTexture2D("imgCharGolem", "G:/Github/05-CppProjects/04-DndRaylib/04-DndRaylib/resources/Golem.png");
    LoadTexture2D("imgCharLich", "G:/Github/05-CppProjects/04-DndRaylib/04-DndRaylib/resources/Lich.png");
    LoadTexture2D("imgCharDragon", "G:/Github/05-CppProjects/04-DndRaylib/04-DndRaylib/resources/Dragon.png");
    LoadTexture2D("", "G:/Github/05-CppProjects/04-DndRaylib/04-DndRaylib/resources/Unknown.png");
    LoadTexture2D("imgEffHeal", "G:/Github/05-CppProjects/04-DndRaylib/04-DndRaylib/resources/Heal.png");
    LoadTexture2D("imgUIButton", "G:/Github/05-CppProjects/04-DndRaylib/04-DndRaylib/resources/Button.png");
    LoadTexture2D("imgBackground", "G:/Github/05-CppProjects/04-DndRaylib/04-DndRaylib/resources/Background.png");

    textFont["Alagard"] = LoadFont("G:/Github/05-CppProjects/04-DndRaylib/04-DndRaylib/resources/fonts/alagard.png");
    textFont["Romulus"] = LoadFont("G:/Github/05-CppProjects/04-DndRaylib/04-DndRaylib/resources/fonts/romulus.png");
    textFont["Setback"] = LoadFont("G:/Github/05-CppProjects/04-DndRaylib/04-DndRaylib/resources/fonts/setback.png");
    music = LoadMusicStream("G:/Github/05-CppProjects/04-DndRaylib/04-DndRaylib/resources/FFCTBattle.mp3");

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

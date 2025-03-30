#include "raylib.h"
#include "Ball.h"
#include "Paddle.h"
#include "Score.h"
#include <iostream>
#include <vector>

using std::vector;

void Start();
void Update();
void Draw();
void End();

void ChangeScene();
void LoadGameScene();
void LoadMenuScene();

Texture2D background;
Texture2D logoDvd;
Texture2D cardboardBox;
Font textFont;
Music music;

Ball ball;
Paddle player;
Paddle enemy;
Score pScore;
Score eScore;

vector<GameObject*> gameObjectList;

enum Scenes {
    MainMenu,
    Game,
};
Scenes currentScene;

void Start(){
    InitWindow(800, 500, "Raylib");
    SetTargetFPS(60);
    InitAudioDevice();

    Image imgBkrgd = LoadImage("resources/background.png");
    Image imgDvd = LoadImage("resources/Logo-Dvd.png");
    Image imgBox = LoadImage("resources/Cardboard-Box.png");
    textFont = LoadFont("resources/fonts/mecha.png");
    music = LoadMusicStream("resources/balatro.mp3");

    background = LoadTextureFromImage(imgBkrgd);
    logoDvd = LoadTextureFromImage(imgDvd);
    cardboardBox = LoadTextureFromImage(imgBox);
    UnloadImage(imgBkrgd);
    UnloadImage(imgDvd );
    UnloadImage(imgBox );

    SetMusicVolume(music, 2);
    PlayMusicStream(music);
    currentScene = Scenes::Game;
    ChangeScene();
}

void ChangeScene() {
    switch (currentScene){
    case Scenes::Game:
        LoadGameScene();
        break;
    case Scenes::MainMenu:
        LoadMenuScene();
        break;
    }
}

void LoadGameScene(){
    gameObjectList.clear();
    ball = { Vector2{GetScreenWidth() * 0.5f, GetScreenHeight() * 0.5f}, 25.0f, Vector2{5.0f, 4.0f}, &logoDvd };
    player = { Vector2{100.0f, GetScreenHeight() * 0.5f}, Vector2{20.0f, 60.0f}, 20.0f, &cardboardBox, WHITE };
    player.SetPlayer();
    player.AssignKeys(KEY_UP, KEY_DOWN);
    enemy = { Vector2{650.0f, GetScreenHeight() * 0.5f}, Vector2{20.0f, 60.0f}, 5.0f, &cardboardBox, DARKBLUE };
    enemy.AssignBall(&ball);
    pScore = { Vector2{200.0f, 50}, 50, &textFont, BEIGE};
    eScore = { Vector2{550.0f, 50}, 50, &textFont, DARKBLUE };
    ball.SetScore(&pScore, &eScore);
    ball.SetPaddle(&enemy);

    gameObjectList = { &pScore, &eScore, &ball, &player, &enemy};
}

void LoadMenuScene() {

}

void Update(){
    UpdateMusicStream(music);
    for (GameObject* object : gameObjectList) {
        object->Update(&gameObjectList);
    }
}

void Draw(){
    BeginDrawing();
    ClearBackground(BLACK);
    if(currentScene == Scenes::Game)DrawTextureEx(background, Vector2{ 0,0 }, 0, 0.55f, WHITE);
    
    for (GameObject* object : gameObjectList) {
        object->Draw();
    }

    EndDrawing();
}

void End(){
    //Unload
    UnloadMusicStream(music);   // Unload music stream buffers from RAM

    CloseAudioDevice();
    CloseWindow();
}

int main(){ // DO NOT MODIFY
    Start();
    while (!WindowShouldClose())
    {
        Update();
        Draw();
    }
    End();
    return 0;
}
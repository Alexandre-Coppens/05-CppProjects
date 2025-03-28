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

Texture2D background;
Font textFont;

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
    Image img = LoadImage("resources/background.png");
    background = LoadTextureFromImage(img);
    UnloadImage(img);
    textFont = LoadFont("resources/fonts/mecha.png");
    currentScene = Scenes::Game;
    ChangeScene();
}

void ChangeScene() {
    switch (currentScene){
    case Scenes::Game:
        LoadGameScene();
        break;
    }
}

void LoadGameScene(){
    gameObjectList.clear();
    ball = { Vector2{GetScreenWidth() * 0.5f, GetScreenHeight() * 0.5f}, 5.0f, Vector2{5.0f, 5.0f}, WHITE };
    player = { Vector2{100.0f, GetScreenHeight() * 0.5f}, Vector2{20.0f, 60.0f}, 20.0f, BEIGE };
    player.SetPlayer();
    player.AssignKeys(KEY_UP, KEY_DOWN);
    enemy = { Vector2{650.0f, GetScreenHeight() * 0.5f}, Vector2{20.0f, 60.0f}, 20.0f, DARKBLUE };
    pScore = { Vector2{200.0f, 50}, 50, &textFont, BEIGE };
    eScore = { Vector2{550.0f, 50}, 50, &textFont, DARKBLUE };
    ball.SetScore(&pScore, &eScore);

    gameObjectList = { &pScore, &eScore, &ball, &player, &enemy};
}

void Update(){
    for (GameObject* object : gameObjectList) {
        object->Update(&gameObjectList);
    }
}

void Draw(){
    BeginDrawing();
    ClearBackground(BLACK);
    DrawTextureEx(background, Vector2{ 0,0 }, 0, 0.55f, WHITE);
    
    for (GameObject* object : gameObjectList) {
        object->Draw();
    }

    EndDrawing();
}

void End(){
    //Unload
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
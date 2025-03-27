#include "raylib.h"
#include "Ball.h"
#include "Paddle.h"
#include <iostream>
#include <vector>

using std::vector;

void Start();
void Restart();
void Update();
void Draw();
void End();

Ball ball;
Paddle player;

vector<GameObject*> gameObjectList;

void Start(){
    InitWindow(100, 100, "Raylib");
    SetTargetFPS(60);
}

void Restart(){
    gameObjectList.clear();
    ball = { Vector2{GetScreenWidth() * 0.5f, GetScreenHeight() * 0.5f}, 5.0f, Vector2{5.0f, 5.0f}, BLUE };
    player = { Vector2{GetScreenWidth() * 0.5f, GetScreenHeight() * 0.5f}, Vector2{20.0f, 60.0f}, 5.0f, RED };
    player.SetPlayer();
    player.AssignKeys(KEY_UP, KEY_DOWN);

    gameObjectList = { &ball, &player };
}

void Update(){
    for (GameObject* object : gameObjectList) {
        object->Update(&gameObjectList);
    }
}

void Draw(){
    BeginDrawing();
    ClearBackground(BLACK);
    
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
    Restart();
    while (!WindowShouldClose())
    {
        Update();
        Draw();
    }
    End();
    return 0;
}
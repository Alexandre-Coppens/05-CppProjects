// 01-ConsoleStart.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "raylib.h"
#include "raymath.h"
#include <string>
#include <vector>

#include "Agent.h"
#include "UsedStates.h"

int WIDTH = 800;
int HEIGHT = 600;

int main()
{   
	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
	InitWindow(WIDTH, HEIGHT, "AI SFM Intro");
	SetTargetFPS(60);

    Agent square = Agent(Vector2(WIDTH * 0.5f, HEIGHT * 0.5f), BLACK, Vector2(20, 20));
    square.ChangeState(std::move(std::make_unique<IdleState>()));

    while (!WindowShouldClose())
    {
        square.Update(GetFrameTime());

        BeginDrawing();
        ClearBackground(RAYWHITE);

        square.Draw();
        
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
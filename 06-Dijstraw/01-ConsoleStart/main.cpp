#include "raylib.h"
#include "raymath.h"
#include <vector>
#include <algorithm>
#include <string>
#include <vector>
#include "Tile.h"
#include "Pathfinder.h"

// -----------------------------------------------------------------------------
//  Pathfinding Demo (Dijkstra & A*)
//  This file handles grid initialization, rendering, and input controls.
//  It uses ComputePath() from Pathfinder.cpp to update the route dynamically.
// -----------------------------------------------------------------------------

int WIDTH = 640;
int HEIGHT = 400;

Vector2 gridSize = Vector2(WIDTH / 20, HEIGHT / 20);
std::vector<std::vector<Tile*>> grid;

std::vector<Tile*> path;

int main()
{
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(WIDTH, HEIGHT + 80, "Pathfinding - Dijkstra & A*");
    SetTargetFPS(60);

    //--------------------------
    //INIT
    //--------------------------
    for (int y = 0; y < gridSize.y; y++)
    {
        std::vector<Tile*> row;
        for (int x = 0; x < gridSize.x; x++)
        {
            Tile tile;
            tile.position = Vector2(x, y);
            row.push_back(&tile);
        }
        grid.push_back(row);
    }
    path = { grid[0][0], grid[0][0] };

    while (!WindowShouldClose())
    {
        Vector2 mousePosition = GetMousePosition();

        if (IsMouseButtonPressed(0) && mousePosition.y <= HEIGHT) {
            path[0] = grid[floorf(mousePosition.y / 20)][floorf(mousePosition.x / 20)];
        }

        if (IsMouseButtonPressed(1) && mousePosition.y <= HEIGHT) {
            path[path.size()-1] = grid[floorf(mousePosition.y / 20)][floorf(mousePosition.x / 20)];
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        for (int y = 0; y < gridSize.y; y ++) {
            for (int x = 0; x < gridSize.x; x++) {
                DrawRectangle(x * 20, y * 20, 20, 20, BLACK);
                DrawRectangle(x * 20 + 1, y * 20 + 1, 18, 18, RAYWHITE);
            }
        }

        for (int i = 0; i < path.size(); i++) 
        {
            if (i == 0) DrawRectangle(path[i]->position.x * 20 + 1, path[i]->position.y * 20 + 1, 18, 18, DARKGREEN);
            else if (i == path.size() - 1) DrawRectangle(path[i]->position.x * 20 + 1, path[i]->position.y * 20 + 1, 18, 18, GREEN);
            else DrawRectangle(path[i]->position.x * 20 + 1, path[i]->position.y * 20 + 1, 18, 18, YELLOW);
        }
        EndDrawing();
    }

    CloseWindow();
    return 0;
}

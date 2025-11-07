#pragma once
#include "raylib.h"
#include "raymath.h"

struct Tile 
{
    Vector2 position;
    int g;
    int h;
    int f;
    Tile* parent;
    bool isEnd;

    Tile() :
        position(Vector2Zero()), g(0), h(0), f(0), parent(nullptr), isEnd(false)
    {};
};
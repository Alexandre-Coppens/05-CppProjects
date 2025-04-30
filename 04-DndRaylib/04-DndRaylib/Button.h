#pragma once

#include "GameObject.h"

using std::string;
using std::vector;
using std::map;

class Button : public GameObject {
private:
protected:
public:
    int value;
    string text;

private:
public:
    Button();
    Button(bool _enabled, Vector2 _pos, Vector2 _size, Texture2D* _sprite, int value);
    virtual ~Button();

    void Draw();
};
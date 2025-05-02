#pragma once

#include "GameObject.h"

using std::string;
using std::vector;
using std::map;

class FlyingNumber : public GameObject {
private:
    float timer;
    float speed;
    Vector2 velocity;

protected:
public:
    string value;

private:
public:
    FlyingNumber();
    FlyingNumber(Vector2 _pos, int value);
    virtual ~FlyingNumber();

    void Draw();
    void Update();
};
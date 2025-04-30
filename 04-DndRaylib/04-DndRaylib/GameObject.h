#pragma once

#include <string>
#include <vector>
#include <map>
#include "Raylib.h"

using std::string;
using std::vector;
using std::map;

enum class GameObjectType {
    Character,
    Button,
    None
};

class GameObject {
private:
protected:
    static map<string, GameObject*> GameObjectList;
    Rectangle rect;
public:
    bool enabled;
    string name;
    Vector2 position;
    Vector2 size;
    Texture2D* sprite;
    GameObjectType type;

private:
public:
    GameObject();
    GameObject(bool _enabled, string _name, Vector2 _pos, Vector2 _size, Texture2D* _sprite, GameObjectType _type);
    virtual ~GameObject();
    bool IsCursorInBounds();
    void CreateRect();
    static void CreateGameObject(const string id, GameObject* gO);
    static vector<GameObject*> GetAllGameObjectsWith(GameObjectType type);
};
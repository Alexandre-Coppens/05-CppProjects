#include "GameObject.h"

map<string, GameObject*> GameObject::GameObjectList;

GameObject::GameObject(){
	enabled = false;
	name = "";
	position = Vector2{ 0,0 };
	size = Vector2{ 0,0 };
	sprite = nullptr;
	type = GameObjectType::None;
}

GameObject::GameObject(bool _enabled, string _name, Vector2 _pos, Vector2 _size, Texture2D* _sprite, GameObjectType _type) {
	enabled = _enabled;
	name = _name;
	position = _pos;
	size = _size;
	sprite = _sprite;
	type = _type;

	GameObjectList[_name] = this;
}

GameObject::~GameObject(){
}

void GameObject::Update() {
}

void GameObject::Draw() {
	if (!enabled)return;
	DrawTextureRec(*sprite, rect, position, WHITE);
}

bool GameObject::IsCursorInBounds(){
	if (!enabled)return false;
	return GetMouseX() >= position.x && GetMouseX() <= position.x + size.x && GetMouseY() >= position.y && GetMouseY() <= position.y + size.y;
}

void GameObject::CreateRect(){
	rect.x = 0;
	rect.y = 0;
	rect.width = size.x;
	rect.height = size.y;
}

void GameObject::CreateGameObject(const string id, GameObject* gO){
	gO->name = id;
	GameObjectList[id] = gO;
}

vector<GameObject*> GameObject::GetAllGameObjects()
{
	vector<GameObject*> ret;
	for (auto const& i : GameObjectList) {
		ret.push_back(const_cast<GameObject*>(i.second));
	}
	return ret;
}

vector<GameObject*> GameObject::GetAllGameObjectsWith(GameObjectType type){
	vector<GameObject*> ret;
	for(auto const& i : GameObjectList){
		if (i.second->type == type) {
			ret.push_back(const_cast<GameObject*>(i.second));
		}
	}
    return ret;
}
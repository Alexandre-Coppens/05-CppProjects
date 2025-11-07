#pragma once
#include "IState.h"
#include "Grid.h"
#include "Agent.h"

class MoveState : public IState
{
private:
    std::vector<Vec2i> path;
    float timer = 0.25f;
public:
    MoveState(std::vector<Vec2i> _path) : path(_path) {};
    void Enter(Agent& a) override;
    void Update(Agent& a, float dt) override;
    void Exit(Agent& a) override;
};

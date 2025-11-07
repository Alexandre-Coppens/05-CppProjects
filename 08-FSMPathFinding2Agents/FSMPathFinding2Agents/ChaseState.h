#pragma once
#include "IState.h"
#include "Grid.h"
#include "Agent.h"

class ChaseState : public IState
{
private:
    std::vector<Vec2i> path;
public:
    ChaseState(std::vector<Vec2i> p) : path(p) {};
    void Enter(Agent& a) override;
    void Update(Agent& a, float dt) override;
    void Exit(Agent& a) override;
};

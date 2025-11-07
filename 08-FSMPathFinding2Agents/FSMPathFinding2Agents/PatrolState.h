#pragma once
#include "IState.h"
#include "Agent.h"

class PatrolState : public IState
{
public:
    void Enter(Agent& a) override;
    void Update(Agent& a, float dt) override;
    void Exit(Agent& a) override;
};
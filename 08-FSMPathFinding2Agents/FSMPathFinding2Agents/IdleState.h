#pragma once
#include "IState.h"

class IdleState : public IState
{
private:
    float timer = 1;
public:
    void Enter(Agent& a) override;
    void Update(Agent& a, float dt) override;
    void Exit(Agent& a) override;
};

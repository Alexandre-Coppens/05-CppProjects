#pragma once
#include "IState.h"

class StateMachine
{
private:
    IState* st = nullptr;
public:
    void ChangeState(Agent&, IState* next);
    void Update(Agent&, float dt);
};

#pragma once
class Agent;
class IState
{
public:
    virtual ~IState() = default;
    virtual void Enter(Agent&) = 0;
    virtual void Update(Agent&, float dt) = 0;
    virtual void Exit(Agent&) = 0;
};

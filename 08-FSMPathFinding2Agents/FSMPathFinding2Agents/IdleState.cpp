#include "IdleState.h"
#include "PatrolState.h"
#include "Agent.h"
#include "raylib.h"
#include <iostream>

void IdleState::Enter(Agent& a)
{
    a.SetColor(BLUE);
}

void IdleState::Update(Agent& a, float dt)
{
    //If timer <= 0, then switch state to Patrol
    timer -= dt;
    if (timer <= 0) 
    {
        a.FSM().ChangeState(a, new PatrolState());
    }
}

void IdleState::Exit(Agent& a)
{
}

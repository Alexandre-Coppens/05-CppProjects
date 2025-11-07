#include "StateMachine.h"
#include "Agent.h"

void StateMachine::ChangeState(Agent& a, IState* n)
{
    if (st) { st->Exit(a); delete st; }
    st = n; st->Enter(a);
}
void StateMachine::Update(Agent& a, float dt)
{
    if (st) st->Update(a, dt);
}
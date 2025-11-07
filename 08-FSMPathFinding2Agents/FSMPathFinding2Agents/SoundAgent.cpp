#include "SoundAgent.h"

void SoundAgent::Update(float dt)
{
    if (m_emit) m_emit = false;
    FSM().Update(*this, dt);
}

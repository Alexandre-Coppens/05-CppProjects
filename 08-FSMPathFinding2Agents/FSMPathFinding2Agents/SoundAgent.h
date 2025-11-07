#pragma once
#include "Agent.h"

class SoundAgent : public Agent
{
private:
    bool m_emit = false;

public:
    void EmitSound() { m_emit = true; }
    bool HasSound() const { return m_emit; }
    Vec2i SoundPos() const { return m_cell; }

    void Update(float dt) override; 
};

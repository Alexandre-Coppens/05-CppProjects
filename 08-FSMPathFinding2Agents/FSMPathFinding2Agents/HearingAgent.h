#pragma once
#include "Agent.h"
#include "SoundAgent.h"

class HearingAgent : public Agent
{
private:
    const SoundAgent* m_src = nullptr;
    float m_range = 20.f;
public:
    void SetSource(const SoundAgent* s) { m_src = s; }

    void Update(float dt) override;
};

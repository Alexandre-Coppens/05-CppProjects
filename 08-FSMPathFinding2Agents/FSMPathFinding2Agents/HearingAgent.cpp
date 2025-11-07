#include "HearingAgent.h"
#include "ChaseState.h"
#include "PathFinding.h"

void HearingAgent::Update(float dt)
{
    if (m_src->HasSound())
    {
        std::vector<Vec2i>path = AStar(*GetGrid(), GetCell(), m_src->GetCell(), false);

        if (path.size() <= m_range)
        {
            std::reverse(path.begin(), path.end());
            FSM().ChangeState(*this, new ChaseState(path));
        }
    }
        
    FSM().Update(*this, dt);
}

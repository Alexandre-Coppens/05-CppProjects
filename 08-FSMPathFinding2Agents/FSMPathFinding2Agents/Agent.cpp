#include "Agent.h"
#include "raylib.h"

void Agent::Draw(int s) const
{
    DrawRectangle(m_cell.x * s, m_cell.y * s, s, s, m_color);
}
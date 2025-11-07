#pragma once
#include "Vec2i.h"
#include "Grid.h"
#include "StateMachine.h"
#include "raylib.h"

class Agent
{
protected:
    Vec2i m_cell{ 0,0 };
    const Grid* m_grid = nullptr;
    Color  m_color = WHITE;
    StateMachine m_fsm;

public:
    void SetGrid(const Grid* g) { m_grid = g; }
    const Grid* GetGrid() const { return m_grid; }

    void SetCell(Vec2i c) { m_cell = c; }
    Vec2i GetCell() const { return m_cell; }

    void SetColor(Color c) { m_color = c; }
    Color GetColor() const { return m_color; }

    StateMachine& FSM() { return m_fsm; }
    virtual void Update(float dt) = 0;
    void Draw(int size) const;
};

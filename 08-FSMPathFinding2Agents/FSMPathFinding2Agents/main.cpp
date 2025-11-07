#include "raylib.h"
#include "Grid.h"
#include "SoundAgent.h"
#include "HearingAgent.h"
#include "IdleState.h"
//#include "PatrolState.h"
//#include "MoveState.h"
//#include "ChaseState.h"


int main()
{
    InitWindow(800, 600, "Séance 3 — Base Étudiants");
    SetTargetFPS(60);

    Grid g(32, 24);
    g.RandomObstacles(42, 0.18f);

    SoundAgent soundAgent;
    HearingAgent hearingAgent;

    soundAgent.SetGrid(&g);
    hearingAgent.SetGrid(&g);
    hearingAgent.SetSource(&soundAgent);

    soundAgent.SetCell({ 5,5 });
    hearingAgent.SetCell({ 20,10 });

    soundAgent.FSM().ChangeState(soundAgent, new IdleState());
    hearingAgent.FSM().ChangeState(hearingAgent, new IdleState());

    while (!WindowShouldClose())
    {
        float dt = GetFrameTime();
        soundAgent.Update(dt);
        hearingAgent.Update(dt);

        BeginDrawing();
        ClearBackground(BLACK);
        g.Draw(24);
        soundAgent.Draw(24);
        hearingAgent.Draw(24);
        EndDrawing();
    }
    CloseWindow();
}

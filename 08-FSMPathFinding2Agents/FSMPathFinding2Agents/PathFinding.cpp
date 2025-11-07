#include "Pathfinding.h"
#include <queue>
#include <algorithm>
#include <cmath>

struct Node { Vec2i p; float g = 1e9, h = 0, f = 0; int parent = -1; };

std::vector<Vec2i> AStar(const Grid& g, Vec2i s, Vec2i t, bool diag)
{
    int W = g.W(), H = g.H();
    auto id = [&](Vec2i v) {return v.y * W + v.x; };
    std::vector<Node> n(W * H);
    for (int y = 0; y < H; y++) for (int x = 0; x < W; x++) n[id({ x,y })].p = { x,y };

    auto Hc = [&](Vec2i a, Vec2i b) {return abs(a.x - b.x) + abs(a.y - b.y); };
    auto cmp = [&](int a, int b) {return n[a].f > n[b].f; };
    std::priority_queue<int, std::vector<int>, decltype(cmp)> open(cmp);

    int sId = id(s), tId = id(t);
    n[sId].g = 0; n[sId].h = Hc(s, t); n[sId].f = n[sId].h;
    open.push(sId);

    int d[8][2] = { {1,0},{-1,0},{0,1},{0,-1},{1,1},{-1,1},{1,-1},{-1,-1} };

    while (!open.empty())
    {
        int c = open.top(); open.pop();
        if (c == tId) break;
        for (int i = 0; i < (diag ? 8 : 4); i++)
        {
            Vec2i np = { n[c].p.x + d[i][0],n[c].p.y + d[i][1] };
            if (!g.InBounds(np) || !g.Walkable(np)) continue;
            int k = id(np);
            float ng = n[c].g + 1;
            if (ng < n[k].g) { n[k].g = ng; n[k].h = Hc(np, t); n[k].f = n[k].g + n[k].h; n[k].parent = c; open.push(k); }
        }
    }

    std::vector<Vec2i> path;
    for (int cur = tId; cur != -1; cur = n[cur].parent) path.push_back(n[cur].p);
    std::reverse(path.begin(), path.end());
    return path;
}

AI Single Entity — Session 1 (Dijkstra & A*) — Visual Studio 2022

This project is pre-configured for Raylib on Windows (x64), with:
- Dijkstra and A* implementations
- Toggle between algorithms at runtime
- Mouse interactions to set Start / Goal / Obstacles
- Debug draw for open/closed/path

⚠️ Binaries note
----------------
This archive expects Raylib binaries to be present in the local `include/` and `lib/` folders.
Because this environment cannot redistribute third-party binaries, please drop the following files in place (prebuilt Windows x64 recommended):

- include/raylib.h
- lib/raylib.lib
- lib/raylib.dll   (will be copied next to the .exe by a Post-Build Event)

If you already have a Raylib install, copy those files into the folders above.
The project is set up so you won't have to change any paths.

Build
-----
1) Open 'AI_SingleEntity_S1.sln' in Visual Studio 2022.
2) Build Solution (x64, Debug or Release).
3) Run. If the window fails to start, ensure 'raylib.dll' is in 'lib/' and that the post-build copy happened.

Controls
--------
- Left click   : set Start node
- Right click  : set Goal node
- Middle click : toggle obstacle on hovered cell
- SPACE        : toggle A* (ON) vs Dijkstra (OFF)
- O            : toggle Open-list visualization
- C            : toggle Closed-list visualization
- R            : reset grid (clear obstacles)
- D            : toggle 4/8 neighbors (diagonals)
- T            : cycle heuristic (Manhattan / Euclidean / Diagonal) for A*

Colors
------
- Light gray : walkable cell
- Dark gray  : obstacle
- Green      : node in OPEN list
- Red        : node in CLOSED list
- Blue       : path nodes
- Yellow     : Start / Goal

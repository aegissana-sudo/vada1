# SimpleGame (Unreal Engine)

A minimal Unreal Engine C++ project for a simple collectible game. The player pawn moves with WASD/arrow keys, and overlapping a collectible increments the score (logged to the Output Log).

## Quick start
1. Open `SimpleGame.uproject` in Unreal Engine 5.3+.
2. Create a new level at `/Game/Maps/DefaultMap` (or change the map path in `Config/DefaultEngine.ini`).
3. Add a floor mesh (e.g., a cube scaled up).
4. Place a few `CollectibleActor` instances in the level and assign a simple mesh (sphere/cube).
5. Press Play to move and collect items.

## Notes
- `SimplePlayerPawn` is the default pawn. It uses simple velocity-based movement.
- `CollectibleActor` rotates and is destroyed on overlap with the pawn.
- Score is printed to the Output Log with `UE_LOG`.

#include "raylib.h"
#include "constants.h"

int main(void)
{
    InitWindow(constants::cellSize * constants::cellCount, constants::cellSize * constants::cellCount, "Retro Snake");

    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(constants::green);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
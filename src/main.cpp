#include "raylib.h"
#include "constants.h"
#include "food.h"

int main(void)
{
    InitWindow(constants::cellSize * constants::cellCount, constants::cellSize * constants::cellCount, "Retro Snake");

    Food food = Food(7, 7);

    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(constants::green);
            food.draw();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
#include "raylib.h"
#include "constants.h"
#include "food.h"
#include "snake.h"

int main(void)
{
    InitWindow(constants::cellSize * constants::cellCount, constants::cellSize * constants::cellCount, "Retro Snake");

    Food food = Food();
    Snake snake = Snake();

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(constants::green);
        food.draw();
        snake.draw();
        
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
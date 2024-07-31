#include <raylib.h>
#include "constants.h"
#include "food.h"
#include "snake.h"

double lastUpdatetime = 0;

bool eventTriggered(double interval)
{
    double currentTime = GetTime();
    if(currentTime - lastUpdatetime >= interval)
    {
        lastUpdatetime = currentTime;
        return true;
    }
    return false;
}

int main(void)
{
    InitWindow(constants::cellSize * constants::cellCount, constants::cellSize * constants::cellCount, "Retro Snake");
    SetTargetFPS(60);
    
    Food food = Food();
    Snake snake = Snake();

    while (!WindowShouldClose())
    {
        BeginDrawing();

        if(eventTriggered(0.2))
        {
            snake.update();
        }

        ClearBackground(constants::green);
        food.draw();
        snake.draw();
        
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
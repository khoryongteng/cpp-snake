#include <raylib.h>
#include "constants.h"
#include "game_manager.h"

int main(void)
{
    InitWindow(constants::cellSize * constants::cellCount, constants::cellSize * constants::cellCount, "Retro Snake");
    SetTargetFPS(60);

    GameManager gameManager = GameManager(); 

    while (!WindowShouldClose())
    {
        gameManager.update();
        gameManager.render();
    }

    CloseWindow();

    return 0;
}
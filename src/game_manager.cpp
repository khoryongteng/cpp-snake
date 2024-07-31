#include "game_manager.h"
#include "constants.h"

GameManager::GameManager() : 
  food{}, snake{} 
{}

void GameManager::update()
{
  double currentTime = GetTime();
  if(currentTime - lastUpdateTime >= interval)
  {
    lastUpdateTime = currentTime;
    snake.update();
  }
}

void GameManager::render()
{
  BeginDrawing();
  ClearBackground(constants::green);
  food.draw();
  snake.draw();
  EndDrawing();
}
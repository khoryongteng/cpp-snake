#include "raylib.h"
#include "raymath.h"
#include "game_manager.h"
#include "constants.h"

GameManager::GameManager()
{
  snake = Snake{};
  food = Food{snake.getBody()};
}

void GameManager::update()
{
  double currentTime = GetTime();
  if(currentTime - lastUpdateTime >= interval)
  {
    lastUpdateTime = currentTime;
    snake.update();
    checkCollisionWithFood();
  }
}

void GameManager::detectControls()
{
  KeyboardKey keys[] = {KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT};

  KeyboardKey pressedKey = KEY_NULL;

  for (const KeyboardKey &key : keys)
  {
    if (IsKeyDown(key))
    {
      if (pressedKey != KEY_NULL)
      {
        return;
      }
      pressedKey = key;
    }
  }

  switch (pressedKey)
  {
    case KEY_UP:
      snake.setDirection(Snake::Direction::Up);
      return;
    case KEY_DOWN:
      snake.setDirection(Snake::Direction::Down);
      return;
    case KEY_LEFT:
      snake.setDirection(Snake::Direction::Left);
      return;
    case KEY_RIGHT:
      snake.setDirection(Snake::Direction::Right);
      return;
    default:
      return;
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

void GameManager::checkCollisionWithFood()
{
  if (Vector2Equals(snake.getHead(), food.getPosition())) {
    food.switchPosition(snake.getBody());
    snake.grow();
  }
}
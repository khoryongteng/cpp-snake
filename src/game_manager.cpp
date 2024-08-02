#include "raylib.h"
#include "raymath.h"
#include "game_manager.h"
#include "constants.h"
#include <iostream>

GameManager::GameManager()
{
  reset();
}

void GameManager::update()
{
  if (running)
  {
    double currentTime = GetTime();
    if(currentTime - lastUpdateTime >= interval)
    {
      lastUpdateTime = currentTime;
      snake.update();
      checkCollisionWithFood();
      checkCollisionWithEdges();
      checkCollisionWithTail();
    }
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

  if (!running && pressedKey != KEY_NULL)
  {
    running = true;
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

void GameManager::checkCollisionWithEdges()
{
  if(snake.getHead().x >= constants::cellCount || 
     snake.getHead().x < 0 || 
     snake.getHead().y >= constants::cellCount || 
     snake.getHead().y < 0)
  {
    gameOver();
  }
}

void GameManager::checkCollisionWithTail()
{
  const std::deque<Vector2> body = snake.getBody();
  for (size_t i = 1; i < body.size(); ++i)
  {
    if (Vector2Equals(body.at(0), body.at(i)))
    {
      gameOver();
      return; // Exit early after game over
    }
  }
}

void GameManager::gameOver()
{
  std::cout << "Game Over!" << std::endl;
  running = false;
  reset();
}

void GameManager::reset()
{
  snake = Snake{};
  food = Food{snake.getBody()};
}
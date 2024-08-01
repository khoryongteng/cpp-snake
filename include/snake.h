#pragma once
#include <deque>
#include <raylib.h>
#include <unordered_map>

class Snake
{
public:
  enum class Direction
  {
    Up,
    Down,
    Left,
    Right
  };

  Snake();

  void draw();
  void update();
  void setDirection(Direction newDirection);
private:
  std::deque<Vector2> body;
  Vector2 direction {1, 0};

  Vector2 directionToVector2(Direction newDirection) const;

  static const std::unordered_map<Direction, Vector2> directionMap;
};
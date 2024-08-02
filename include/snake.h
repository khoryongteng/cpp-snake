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

  Snake() : body{Vector2{6, 9}, Vector2{5, 9}, Vector2{4, 9}} {};

  void draw();
  void update();
  void setDirection(Direction newDirection);
  Vector2 getHead();
  std::deque<Vector2>& getBody();
  void grow();

private:
  std::deque<Vector2> body;
  Vector2 direction {1, 0};
  static const std::unordered_map<Direction, Vector2> directionMap;
  bool addSegment = false;
};
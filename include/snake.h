#pragma once
#include <deque>
#include <raylib.h>

class Snake
{
public:
  Snake();
  void draw();
  void update();
private:
  std::deque<Vector2> body;
  Vector2 direction {1, 0};
};
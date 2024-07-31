#pragma once
#include <deque>
#include "raylib.h"

class Snake
{
public:
  void draw();
private:
  std::deque<Vector2> body = {Vector2{6, 9}, Vector2{5, 9}, Vector2{4, 9}};
};
#pragma once

#include "raylib.h"

class Food {

public:
  Food(int x, int y);

  void draw();

private:
  Vector2 position;
  Texture2D texture;
};
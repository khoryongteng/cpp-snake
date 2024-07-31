#pragma once

#include "raylib.h"

class Food {

public:
  Food(float x, float y);

  void draw();

private:
  Vector2 position;
  Texture2D texture;
  
  Vector2 generateRandomPos();
};
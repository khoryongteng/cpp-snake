#pragma once

#include <raylib.h>

class Food {

public:
  Food();

  void draw();
  Vector2 getPosition();
  void switchPos();

private:
  Vector2 position;
  Texture2D texture;
  
  Vector2 generateRandomPos();
};
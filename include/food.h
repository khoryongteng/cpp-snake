#pragma once

#include <raylib.h>
#include <deque>

class Food {

public:
  Food() = default;
  Food(const std::deque<Vector2>& invalidVectors);

  void draw();
  Vector2 getPosition();
  void switchPosition(const std::deque<Vector2>& invalidVectors);

private:
  Vector2 position;
  Texture2D texture;

  Vector2 generateRandomPosition();
  bool isOverlapping(const Vector2& pos, const std::deque<Vector2>& invalidVectors);
};
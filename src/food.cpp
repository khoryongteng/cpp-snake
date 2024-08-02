#include "food.h"
#include "constants.h"

#include <raymath.h>

Food::Food(const std::deque<Vector2>& invalidVectors)
{
  switchPosition(invalidVectors);
}

void Food::draw()
{
  Rectangle segment = Rectangle{
    position.x * constants::cellSize, 
    position.y * constants::cellSize, 
    constants::cellSize, 
    constants::cellSize
  };
  DrawRectangleRounded(segment, 1, 6, constants::darkGreen);
}

Vector2 Food::getPosition()
{
  return position;
}

void Food::switchPosition(const std::deque<Vector2>& invalidVectors)
{
  Vector2 newPosition = generateRandomPosition();
  while (isColliding(newPosition, invalidVectors))
  {
    newPosition = generateRandomPosition();
  }
  position = newPosition;
}

Vector2 Food::generateRandomPosition()
{
  float x = GetRandomValue(0, constants::cellCount - 1);
  float y = GetRandomValue(0, constants::cellCount - 1);
  return Vector2{x, y};
}

bool Food::isColliding(const Vector2& pos, const std::deque<Vector2>& invalidVectors)
{
  for (const auto& invalidVector : invalidVectors) 
  {
    if (Vector2Equals(pos, invalidVector))
    {
      return true;
    }
  }
  return false;
}
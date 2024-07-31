#include "food.h"
#include "constants.h"

Food::Food(float x, float y) 
{
  position = generateRandomPos();
}

void Food::draw()
{
  DrawRectangle(
    position.x * constants::cellSize, 
    position.y * constants::cellSize, 
    constants::cellSize, 
    constants::cellSize, 
    constants::darkGreen
  );
}

Vector2 Food::generateRandomPos()
{
  float x = GetRandomValue(0, constants::cellCount - 1);
  float y = GetRandomValue(0, constants::cellCount - 1);
  return Vector2{x, y};
}
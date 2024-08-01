#include "food.h"
#include "constants.h"

Food::Food() 
{
  position = generateRandomPos();
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

void Food::switchPos()
{
  position = generateRandomPos();
}

Vector2 Food::generateRandomPos()
{
  float x = GetRandomValue(0, constants::cellCount - 1);
  float y = GetRandomValue(0, constants::cellCount - 1);
  return Vector2{x, y};
}
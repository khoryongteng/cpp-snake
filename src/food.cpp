#include "food.h"
#include "constants.h"

Food::Food(int x, int y) : position {static_cast<float>(x), static_cast<float>(y)} {}

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
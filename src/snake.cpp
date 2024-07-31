#include "snake.h"
#include "constants.h"

void Snake::draw()
{
  for(unsigned int i = 0; i < body.size(); i++)
  {
    Rectangle segment = Rectangle{
      body[i].x * constants::cellSize, 
      body[i].y * constants::cellSize, 
      constants::cellSize, 
      constants::cellSize
    };
    DrawRectangleRounded(segment, 0.5 , 6, constants::darkGreen);
  }
}
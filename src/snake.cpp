#include "snake.h"
#include "constants.h"

Snake::Snake() : body{Vector2{6, 9}, Vector2{5, 9}, Vector2{4, 9}} {}

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

void Snake::update()
{
  body.pop_back();
  auto newSegment = Vector2{body[0].x + direction.x, body[0].y + direction.y};
  body.push_front(newSegment);
}
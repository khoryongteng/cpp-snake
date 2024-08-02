#include "snake.h"
#include "constants.h"
#include <raymath.h>

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
  body.push_front(Vector2Add(body.at(0), direction));
  if (addSegment)
  {
    addSegment = false;
  }
  else
  {
    body.pop_back();
  }
}

void Snake::setDirection(Direction newDirection)
{
  Vector2 newDirectionVector = directionMap.at(newDirection);
  if (direction.x == -newDirectionVector.x && direction.y == -newDirectionVector.y) 
  {
    return;
  }
  direction = newDirectionVector;
}

Vector2 Snake::getHead()
{
  return body.at(0);
}

std::deque<Vector2>& Snake::getBody()
{
  return body;
}

void Snake::grow()
{
  addSegment = true;
}

const std::unordered_map<Snake::Direction, Vector2> Snake::directionMap = {
  {Direction::Up, Vector2{0, -1}},
  {Direction::Down, Vector2{0, 1}},
  {Direction::Left, Vector2{-1, 0}},
  {Direction::Right, Vector2{1, 0}},
};
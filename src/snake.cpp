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

void Snake::setDirection(Direction newDirection)
{
  Vector2 newDirectionVector = directionMap.at(newDirection);
  if (direction.x == -newDirectionVector.x && direction.y == -newDirectionVector.y) 
  {
    return;
  }
  direction = newDirectionVector;
}

const std::unordered_map<Snake::Direction, Vector2> Snake::directionMap = {
  {Direction::Up, Vector2{0, -1}},
  {Direction::Down, Vector2{0, 1}},
  {Direction::Left, Vector2{-1, 0}},
  {Direction::Right, Vector2{1, 0}},
};
#include "food.h"
#include "snake.h"

class GameManager {
public:
  GameManager();
  void update();
  void render();
private:
  const double interval {0.2};
  double lastUpdateTime {0};
  Food food;
  Snake snake;
};
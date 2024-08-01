#include "food.h"
#include "snake.h"

class GameManager {
public:
  GameManager() : food{}, snake{} {};
  void update();
  void detectControls();
  void render();
private:
  const double interval {0.2};
  double lastUpdateTime {0};
  Food food;
  Snake snake;
};
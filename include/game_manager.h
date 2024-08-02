#include "food.h"
#include "snake.h"

class GameManager {
public:
  GameManager();
  void update();
  void detectControls();
  void render();
private:
  Food food;
  Snake snake;
  const double interval {0.2};
  double lastUpdateTime {0};
  bool running {false};
  
  void checkCollisionWithFood();
  void checkCollisionWithEdges();
  void checkCollisionWithTail();
  void gameOver();
  void reset();
};
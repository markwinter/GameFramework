#ifndef ENGINE_H_
#define ENGINE_H_

#include "GameLoop.h"

class Engine {
 public:
  Engine();
  ~Engine();

  void Run();

 private:
  sf::RenderWindow main_window_;
  GameLoop game_loop_;
};

#endif
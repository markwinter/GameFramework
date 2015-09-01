// GameLoop.h
//
// The game loop, self explanatory.

#ifndef GAME_LOOP_H_
#define GAME_LOOP_H_

#include "GameState.h"
#include <stack>

class GameLoop {
 public:
  GameLoop();
  ~GameLoop();

  void Loop(sf::RenderWindow& main_window);

 private:
  // Might be better to use a set rather than a stack
  std::stack<std::unique_ptr<GameState>> state_stack_;
  sf::Clock game_clock_;
};

#endif
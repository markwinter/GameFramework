// GameLoop.h
//
// The game loop, self explanatory.

#ifndef GAME_LOOP_H_
#define GAME_LOOP_H_

#include "GameState.h"

class GameLoop {
 public:
  GameLoop();
  ~GameLoop();

  void Loop();

 private:

  GameState state_;

  sf::RenderWindow main_window_;

  sf::Clock game_clock_;
};

#endif
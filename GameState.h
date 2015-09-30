// GameState.h
//
// A base class to represent a certain state the game is in (e.g. ShowingMenu, Playing, Paused)
// Actual states should be inherited from this class

#ifndef GAME_STATE_H_
#define GAME_STATE_H_

class GameState {
 public:
  GameState();
  virtual ~GameState();

  virtual void Draw(sf::RenderWindow&, int32_t);
  virtual void Update(int32_t);
  virtual void HandleInput();
};

#endif
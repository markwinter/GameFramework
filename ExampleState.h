// ExampleState.h
//
// An example game state used to demonstrate how to add states to your game

#ifndef EXAMPLE_STATE_H_
#define EXAMPLE_STATE_H_

#include "GameState.h"
#include "ObjectManager.h"
#include "ExampleObject.h"
#include "AudioManager.h"

class ExampleState : public GameState {
 public:
  ExampleState();
  ~ExampleState() override;

  void Draw(sf::RenderWindow&, int32_t) override;
  void Update(int32_t) override;
  void HandleInput() override;

 private:
  ObjectManager object_manager_;
  AudioManager audio_manager_;
};

#endif
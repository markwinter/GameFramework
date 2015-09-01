#include "stdafx.h"
#include "ExampleState.h"

ExampleState::ExampleState() {
  // Create an example object to display on screen
  std::unique_ptr<ExampleObject> player = std::make_unique<ExampleObject>();
  object_manager_.Add(std::move(player));

  audio_manager_.PlayBackgroundMusic("sounds/example.flac");
}

ExampleState::~ExampleState() {

}

void ExampleState::Draw(sf::RenderWindow& window, int32_t dt) {
  object_manager_.DrawAll(window, dt);
}

void ExampleState::Update(int32_t dt) {
  object_manager_.UpdateAll(dt);
}

void ExampleState::HandleInput() {

}
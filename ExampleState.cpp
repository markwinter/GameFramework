#include "stdafx.h"
#include "ExampleState.h"

ExampleState::ExampleState() {
  // Create a bunch of sprites for testing
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 4; j++) {
      std::unique_ptr<ExampleObject> object = std::make_unique<ExampleObject>(texture_cache_);
      object->GetSprite().setPosition(i*150, j*100);
      object_manager_.Add(std::move(object));
    }
  }

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
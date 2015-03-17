#include "stdafx.h"
#include "ExampleState.h"

ExampleState::ExampleState() {
  std::unique_ptr<ExampleObject> player(new ExampleObject());
  object_manager_.Add(std::move(player));

  // SFML will play music in a seperate thread so we dont have to worry about that
  // and just play the song 
  auto song = audio_cache_.GetSong("sounds/examplesong.wav");
  if (song != nullptr) {
    song->setLoop(true);
    song->play();
  }
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
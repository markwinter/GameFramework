#include "stdafx.h"
#include "AudioManager.h"

AudioManager::AudioManager() {
  current_sounds_.reserve(max_audio_instances_);
}

AudioManager::~AudioManager() {
  current_background_music_.release();
  current_sounds_.clear();
}

void AudioManager::PlayBackgroundMusic(std::string file_name) {
  // Dont use caching for sf::Music as its streamed from file instead of loaded into memory
  current_background_music_ = std::make_unique<sf::Music>();
  current_background_music_->openFromFile(file_name);
  current_background_music_->setLoop(true);
  current_background_music_->play();
}

void AudioManager::StopBackgroundMusic() {
  current_background_music_->stop();
}

void AudioManager::PlaySound(std::string file_name) {
  auto buffer = audio_cache_.Load(file_name);

  // Could be nullptr if failed to load sound into memory from disk
  if (!buffer)
    return;

  sf::Sound new_sound;
  new_sound.setBuffer(*buffer);

  // Replace any finished sound with this new one
  for (auto sound : current_sounds_) {
    if (sound.getStatus() == sf::Sound::Stopped) {
      sound = new_sound;
      sound.play();
      return;
    }
  }

  current_sounds_.push_back(new_sound);
  current_sounds_.back().play();
}

void AudioManager::StopAllSounds() {
  current_sounds_.clear();
}


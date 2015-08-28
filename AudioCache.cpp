#include "stdafx.h"
#include "AudioCache.h"

AudioCache::AudioCache() {}

AudioCache::~AudioCache() {
  music_.clear();
  sounds_.clear();
}

std::shared_ptr<sf::Music> AudioCache::GetMusic(std::string name) {
  auto itr = music_.find(name);

  if (itr == music_.end()) {
    std::shared_ptr<sf::Music> song = std::make_shared<sf::Music>();

    if (!song->openFromFile(name)) {
      song.reset();
      return nullptr;
    }

    music_.insert(std::pair<std::string, std::shared_ptr<sf::Music>>(name, song));
    return song;
  }

  return itr->second;
}

std::shared_ptr<sf::SoundBuffer> AudioCache::GetSoundBuffer(std::string name) {
  auto itr = sounds_.find(name);

  if (itr == sounds_.end()) {
    std::shared_ptr<sf::SoundBuffer> sound = std::make_shared<sf::SoundBuffer>();

    if (!sound->loadFromFile(name)) {
      sound.reset();
      return nullptr;
    }

    sounds_.insert(std::pair<std::string, std::shared_ptr<sf::SoundBuffer>>(name, sound));
    return sound;
  }

  return itr->second;
}
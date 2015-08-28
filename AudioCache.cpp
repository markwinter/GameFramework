#include "stdafx.h"
#include "AudioCache.h"

AudioCache::AudioCache() {}

AudioCache::~AudioCache() {
  songs_.clear();
  sounds_.clear();
}

std::shared_ptr<sf::Music> AudioCache::GetSong(std::string name) {
  auto itr = songs_.find(name);

  if (itr == songs_.end()) {
    std::shared_ptr<sf::Music> song = std::make_shared<sf::Music>();

    if (!song->openFromFile(name)) {
      song.reset();
      return nullptr;
    }

    songs_.insert(std::pair<std::string, std::shared_ptr<sf::Music>>(name, song));
    return song;
  }

  return itr->second;
}

std::shared_ptr<sf::SoundBuffer> AudioCache::GetSound(std::string name) {
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
#include "stdafx.h"
#include "AudioCache.h"

AudioCache::AudioCache() {}

AudioCache::~AudioCache() {
  for (auto item : songs_)
    delete item.second;

  for (auto item : sounds_)
    delete item.second;

  songs_.clear();
  sounds_.clear();
}

sf::Music* AudioCache::GetSong(std::string name) {
  auto itr = songs_.find(name);

  // If the song was not found in the map then add it to the cache
  if (itr == songs_.end()) {
    auto song = new sf::Music();

    // If failed to load song file then return nullptr
    if (!song->openFromFile(name)) {
      delete song;
      return nullptr;
    }

    // Insert new song into map and return it
    songs_.insert(std::pair<std::string, sf::Music*>(name, song));
    return song;
  }

  return itr->second;
}

sf::SoundBuffer* AudioCache::GetSound(std::string name) {
  auto itr = sounds_.find(name);

  if (itr == sounds_.end()) {
    auto sound = new sf::SoundBuffer();

    if (!sound->loadFromFile(name)) {
      delete sound;
      return nullptr;
    }

    sounds_.insert(std::pair<std::string, sf::SoundBuffer*>(name, std::move(sound)));

    return sound;
  }

  return itr->second;
}
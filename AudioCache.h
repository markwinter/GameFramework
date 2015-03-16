// AudioCache.h
//
// An Audio Cache that stores sounds and songs. It will attempt to find the requested
// audio in the cache first before loading it from disk and caching it if not found.

#ifndef AUDIO_CACHE_H_
#define AUDIO_CACHE_H_

class AudioCache {
 public:
  AudioCache();
  ~AudioCache();

  sf::SoundBuffer* GetSound(std::string);
  sf::Music* GetSong(std::string);

 private:
  std::unordered_map<std::string, sf::SoundBuffer*> sounds_;
  std::unordered_map<std::string, sf::Music*> songs_;
};

#endif
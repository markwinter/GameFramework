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

  // GetSound() uses sf::SoundBuffer internally which is better for small audio files such
  // as a short attacking sound, or gun shot. sf::SoundBuffer needs to be loaded into 
  // an sf::Sound to actually be played
  std::shared_ptr<sf::SoundBuffer> GetSound(std::string);

  // GetSong() uses sf::Music internally which is better for large audio files as it 
  // is streamed from the file rather than loaded into memory
  std::shared_ptr<sf::Music> GetSong(std::string);

 private:
  std::unordered_map<std::string, std::shared_ptr<sf::SoundBuffer>> sounds_;
  std::unordered_map<std::string, std::shared_ptr<sf::Music>> songs_;
};

#endif
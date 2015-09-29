#ifndef AUDIO_MANAGER_H_
#define AUDIO_MANAGER_H_

#include "Cache.h"

class AudioManager {
 public:
  AudioManager();
  ~AudioManager();

  void PlayBackgroundMusic(std::string);
  void StopBackgroundMusic() const;

  void PlaySound(std::string);
  void StopAllSounds();

 private:
   Cache<sf::SoundBuffer> audio_cache_;
   // A SFML recommended limit of max sf::Music and sf::Sound instances at any one time
   const uint8_t max_audio_instances_ = 255;
   std::unique_ptr<sf::Music> current_background_music_;
   std::vector<sf::Sound> current_sounds_;
};

#endif 
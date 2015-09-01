#ifndef AUDIO_MANAGER_H_
#define AUDIO_MANAGER_H_

#include "AudioCache.h"

class AudioManager {
 public:
  AudioManager();
  ~AudioManager();

  void PlayBackgroundMusic(std::string);
  void StopBackgroundMusic();

  void PlaySound(std::string);
  void StopAllSounds();

 private:
   AudioCache audio_cache_;
   // A SFML recommended limit of max sf::Music and sf::Sound instances at any one time
   uint8_t max_audio_instances_ = 255;
   std::shared_ptr<sf::Music> current_background_music_;
   std::vector<sf::Sound> current_sounds_;
};

#endif 
#ifndef ANIMATION_H_
#define ANIMATION_H_

class Animation {
 public:
  Animation(int, float, sf::IntRect);
  ~Animation();

  inline sf::IntRect GetTextureSize() { return texture_size_; }
  inline int GetNumberOfFrames() { return num_of_frames_; }
  inline int GetFrameDuration() { return frame_duration_; }

 private:
  sf::IntRect texture_size_;
  int num_of_frames_;
  float frame_duration_;
};

#endif
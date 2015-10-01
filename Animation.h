#ifndef ANIMATION_H_
#define ANIMATION_H_

class Animation {
 public:
  Animation(int, float);
  ~Animation();

  inline int GetLength() { return num_of_frames_; }
  inline int GetFrameDuration() { return frame_duration_; }

 private:
  int num_of_frames_;
  float frame_duration_;
};

#endif
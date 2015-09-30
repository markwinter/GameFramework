#ifndef ANIMATION_FRAME_H_
#define ANIMATION_FRAME_H_

class AnimationFrame {
 public:
  AnimationFrame(int, int, float);
  ~AnimationFrame();

  inline int GetLength() { return end_frame_ - start_frame_ + 1; }
  inline int GetDuration() { return duration_; }

 private:
  int start_frame_;
  int end_frame_;
  float duration_;
};

#endif
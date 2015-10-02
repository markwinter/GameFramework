#ifndef ANIMATION_HANDLER_H_
#define ANIMATION_HANDLER_H_

#include "Animation.h"

class AnimationHandler {
 public:
  AnimationHandler();
  ~AnimationHandler();

  void AddAnimation(Animation& animation);
  void ChangeCurrentFrame(int);
  void Update(int);

  inline void StopAnimating() { is_animating_ = false; }
  inline void StartAnimating() { is_animating_ = true; }

  inline sf::IntRect GetTextureBounds() const { return texture_bounds_; }
  
 private:
  sf::IntRect texture_bounds_;
  std::vector<Animation> animations_;
  float animation_elapsed_time_;
  int current_animation_;
  bool is_animating_;
};

#endif
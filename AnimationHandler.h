#ifndef ANIMATION_HANDLER_H_
#define ANIMATION_HANDLER_H_

#include "AnimationFrame.h"

class AnimationHandler {
 public:
  AnimationHandler(std::vector<sf::IntRect>);
  ~AnimationHandler();

  void AddAnimationFrame(AnimationFrame& animation);
  void ChangeCurrentFrame(int);
  void Update(int);

  sf::IntRect texture_bounds_;

 private:
  std::vector<sf::IntRect> texture_sizes_;
  std::vector<AnimationFrame> animations_;
  float elapsed_time_;
  int current_animation_;
};

#endif
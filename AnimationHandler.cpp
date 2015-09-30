#include "stdafx.h"
#include "AnimationHandler.h"

AnimationHandler::AnimationHandler(std::vector<sf::IntRect> texture_sizes)
  : elapsed_time_(0), 
    current_animation_(-1),
    texture_sizes_(texture_sizes) {}

void AnimationHandler::AddAnimationFrame(AnimationFrame& animation) {
  animations_.push_back(animation);
}

void AnimationHandler::Update(int last_time) {
  // Check for valid animation frame
  // Set to -1 by default in ctor so ChangeCurrentFrame() must be used first to set initial frame
  if (current_animation_ == -1)
    return;

  float duration = animations_[current_animation_].GetDuration();

  // Has enough time passed to move on to the next frame?
  if ((elapsed_time_ + last_time) / duration > (elapsed_time_ / duration)) {
    // Calculate current frame number
    int frame = (int) ((elapsed_time_ + last_time) / duration);

    // Frames should wrap from last frame to first frame
    frame %= animations_[current_animation_].GetLength();

    // Set the new sprite for this frame
    // Needs changing based on spritesheet used
    sf::IntRect rect = texture_sizes_[current_animation_];

    if (frame == 0)
      rect.left = (rect.width * frame);
    else
      rect.left = frame * 5 + (rect.width * frame);

    texture_bounds_ = rect;
  }

  // Increment time
  elapsed_time_ += last_time;

  if (elapsed_time_ > duration * animations_[current_animation_].GetLength())
    elapsed_time_ = 0;
}

void AnimationHandler::ChangeCurrentFrame(int num) {
  // Check if animation changing to is already running and valid animation num
  if (current_animation_ == num || num > animations_.size() || num < 0)
    return;

  current_animation_ = num;

  texture_bounds_ = texture_sizes_[num];

  elapsed_time_ = 0;
}
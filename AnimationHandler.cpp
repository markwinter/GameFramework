#include "stdafx.h"
#include "AnimationHandler.h"

AnimationHandler::AnimationHandler(std::vector<sf::IntRect> texture_sizes)
  : animation_elapsed_time_(0),
    current_animation_(0),
    is_animating_(true),
    texture_sizes_(texture_sizes) {}

void AnimationHandler::AddAnimation(Animation& animation) {
  animations_.push_back(animation);
}

void AnimationHandler::Update(int last_time) {
  // Return if we stopped animating or there aren't any animations
  if (!is_animating_ || animations_.size() <= 0)
    return;

  float frame_duration = animations_[current_animation_].GetFrameDuration();

  // Has enough time passed to move on to the next frame?
  if ((animation_elapsed_time_ + last_time) / frame_duration > (animation_elapsed_time_ / frame_duration)) {
    // Calculate current frame number of this animation, wrapping from last to first 
    int frame = (int) ((animation_elapsed_time_ + last_time) / frame_duration);
    frame %= animations_[current_animation_].GetLength();

    // Set the new texture bounds for this frame
    // Assumes animation in spritesheet is on one horizontal line, and no gaps between sprites
    sf::IntRect rect = texture_sizes_[current_animation_];
    rect.left = (rect.width * frame);
    texture_bounds_ = rect;
  }

  animation_elapsed_time_ += last_time;

  if (animation_elapsed_time_ > frame_duration * animations_[current_animation_].GetLength())
    animation_elapsed_time_ = 0;
}

void AnimationHandler::ChangeCurrentFrame(int num) {
  // Check that frame number is valid
  if (current_animation_ == num || num > animations_.size() || num < 0)
    return;

  current_animation_ = num;

  texture_bounds_ = texture_sizes_[num];

  animation_elapsed_time_ = 0;
}
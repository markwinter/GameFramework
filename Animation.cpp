#include "stdafx.h"
#include "Animation.h"

Animation::Animation(int n, float d, sf::IntRect s) 
    : num_of_frames_(n), 
      frame_duration_(d),
      texture_size_(s) {}

Animation::~Animation() {}
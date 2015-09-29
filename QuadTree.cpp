#include "stdafx.h"
#include "Quadtree.h"
#include <iostream>
#include <stdio.h>
#include <tchar.h>

QuadTree::QuadTree() {
  // TODO: Change hardcoded values for initial size
  root_ = std::make_unique<QuadTree::Node>(0, 800, 0, 600, 0);
}

QuadTree::~QuadTree() {}

void QuadTree::Insert(GameObject& object) {
  root_->Insert(object);
}

void QuadTree::Remove(GameObject& object) {
  root_->Remove(object);
}

/* For help with debugging
void QuadTree::Size() {
  root_->Size();
}
*/

QuadTree::Node::Node() {}

QuadTree::Node::Node(int l, int r, int t, int b, int level)
      : left_(l),
        right_(r),
        top_(t),
        bottom_(b),
        level_(level) {}

void QuadTree::Node::Insert(GameObject& object) {
  if (children_.size() > 0) {
    for (auto& child : children_) {
      if (Contains(*child, object)) {
        child->Insert(object);
        return;
      }
    }
  }

  objects_.push_back(&object);

  if (objects_.size() > max_objects_ && level_ < max_levels) {
    int width = right_ - left_;
    int height = bottom_ - top_;

    // NW
    children_.push_back(std::make_unique<Node>(left_, left_ + (width/2), top_, height/2, level_+1));
    // NE
    children_.push_back(std::make_unique<Node>(left_ + (width/2), right_, top_, height/2, level_+1));
    // SW
    children_.push_back(std::make_unique<Node>(left_, width/2, top_ + (height/2), bottom_, level_+1));
    // SE
    children_.push_back(std::make_unique<Node>(left_ + (width/2), right_, top_ + (height/2), bottom_, level_+1));

    // Add objects to children
    for (auto object : objects_) {
      for (auto& child : children_) {
        if (Contains(*child, *object)) {
          child->Insert(*object);
          break;
        }
      }
    }

    objects_.clear();
  }
}

void QuadTree::Node::Remove(GameObject& object) {
  for (auto& child : children_) {
    if (Contains(*child, object)) {
      child->Remove(object);
      return;
    }
  }

  auto itr = std::find(objects_.begin(), objects_.end(), &object);
  
  if (itr != objects_.end()) {
    std::swap(*itr, objects_.back());
    objects_.pop_back();
  }
}

bool QuadTree::Node::Contains(Node& node, GameObject& object) {
  const int x = object.GetSprite().getPosition().x;
  const int y = object.GetSprite().getPosition().y;

  // NB: Does not handle sprites which are larger than node itself, just looks at center
  if (x >= node.Left() && x <= node.Right() && y >= node.Top() && y <= node.Bottom())
    return true;

  return false;
}

/* For help with debugging
void QuadTree::Node::Size() {
  std::cout << "L: " + std::to_string(Left()) + "\tR: " + std::to_string(Right()) +
    "\tT: " + std::to_string(Top()) + "\tB: " + std::to_string(Bottom()) +
    "\tObjects: " + std::to_string(objects_.size()) + "\tChildren: " +
    std::to_string(children_.size()) + "\n";

  for (auto& child : children_)
    child->Size();
}
*/

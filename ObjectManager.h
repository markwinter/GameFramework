//  ObjectManager.h
//
// A manager to store game objects to easily call the Update() and
// Draw() methods on the objects. It has delayed adding and removing of objects,
// so they are only added/removed at the start of the subsequent UpdateAll() call.

#ifndef OBJECT_MANAGER_H_
#define OBJECT_MANAGER_H_

#include "stdafx.h"
#include "GameObject.h"

// Templating

template <typename T>
class ObjectManager {
 public:
  ObjectManager();
  ~ObjectManager();

  void Add(std::unique_ptr<T>);
  void Remove(int);

  void UpdateAll(int32_t);
  void DrawAll(sf::RenderWindow&, int32_t);

 private:
  // Vector to store game objects
  std::vector<std::unique_ptr<T>> game_objects_;

  // Vectors used for delayed insertion and deletion of objects from the object vector
  std::vector<int> objects_marked_for_deletion_;
  std::vector<std::unique_ptr<T>> objects_to_be_inserted_;

  void RemoveDeleted();
  void AddInserted();

  // Should tweak this number based on the game
  int vector_size_ = 100;
};

// Implementation

template <typename T>
inline ObjectManager<T>::ObjectManager() {
  // Reserve some initial space to try and make less vector resizes
  game_objects_.reserve(vector_size_);
  objects_marked_for_deletion_.reserve(vector_size_);
  objects_to_be_inserted_.reserve(vector_size_);
}

template <typename T>
inline ObjectManager<T>::~ObjectManager() {
  game_objects_.clear();
  objects_marked_for_deletion_.clear();
  objects_to_be_inserted_.clear();
}

template <typename T>
inline void ObjectManager<T>::Add(std::unique_ptr<T> object) {
  objects_to_be_inserted_.push_back(std::move(object));
}

template <typename T>
inline void ObjectManager<T>::AddInserted() {
  // If game_objects_ is nearly out of allocated space then double it
  if (game_objects_.size() == game_objects_.capacity() - 1)
    game_objects_.reserve(game_objects_.capacity() * 2);

  for (auto& obj : objects_to_be_inserted_) {
    game_objects_.push_back(std::move(obj));
    game_objects_.back()->SetObjectManagerIndex(game_objects_.size() - 1);
  }

  objects_to_be_inserted_.clear();
}

template <typename T>
inline void ObjectManager<T>::Remove(int index) {
  objects_marked_for_deletion_.push_back(index);
}

template <typename T>
inline void ObjectManager<T>::RemoveDeleted() {
  for (int index : objects_marked_for_deletion_) {
    // If object isn't already object at end of vector, then swap it to the back
    if (index != game_objects_.size() - 1) {
      std::swap(game_objects_[index], game_objects_.back());
      // Update index for the object that was moved from the back
      game_objects_[index]->SetObjectManagerIndex(index);
    }

    // Now remove the back object (unique_ptr handles freeing the memory)
    game_objects_.pop_back();
  }

  objects_marked_for_deletion_.clear();
}

template <typename T>
inline void ObjectManager<T>::UpdateAll(int32_t dt) {
  RemoveDeleted();
  AddInserted();

  for (auto& obj : game_objects_)
    obj->Update(dt);
}

template <typename T>
inline void ObjectManager<T>::DrawAll(sf::RenderWindow& window, int32_t dt) {
  for (auto& obj : game_objects_)
    obj->Draw(window, dt);
}

#endif
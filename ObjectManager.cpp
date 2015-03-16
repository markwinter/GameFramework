#include "stdafx.h"
#include "ObjectManager.h"

ObjectManager::ObjectManager() {
  // Reserve some initial space to try and make less vector resizes
  game_objects_.reserve(vector_size_);
  objects_marked_for_deletion_.reserve(vector_size_);
  objects_to_be_inserted_.reserve(vector_size_);
}

ObjectManager::~ObjectManager() {

}

void ObjectManager::Add(std::unique_ptr<GameObject> object) {
  objects_to_be_inserted_.push_back(std::move(object));
}

void ObjectManager::AddInserted() {
  // If game_objects_ is nearly out of allocated space then double it
  if (game_objects_.size() == game_objects_.capacity() - 1)
    game_objects_.reserve(game_objects_.capacity() * 2);

  for (auto& obj : objects_to_be_inserted_) {
    game_objects_.push_back(std::move(obj));
    obj->SetObjectManagerIndex(game_objects_.size() - 1);
  }
  
  objects_to_be_inserted_.clear();
}

void ObjectManager::Remove(int index) {
  objects_marked_for_deletion_.push_back(index);
}

void ObjectManager::RemoveDeleted() {
  for (int index : objects_marked_for_deletion_) {
    // If object isn't already object at end of vector, then swap it to the back
    if (index != game_objects_.size() - 1)
      std::swap(game_objects_[index], game_objects_.back());

    // Now remove the back object (unique_ptr handles freeing the memory)
    game_objects_.pop_back();
  }

  objects_marked_for_deletion_.clear();
}

void ObjectManager::UpdateAll(int32_t dt) {
  RemoveDeleted();
  AddInserted();

  for (auto& obj : game_objects_)
    obj->Update(dt);
}

void ObjectManager::DrawAll(sf::RenderWindow& window, int32_t dt) {
  for (auto& obj : game_objects_)
    obj->Draw(window, dt);
}
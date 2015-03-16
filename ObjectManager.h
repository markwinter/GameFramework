//  ObjectManager.h
//
// A manager to store game objects to easily call the Update() and
// Draw() methods on the objects. It has delayed adding and removing of objects,
// so they are only added/removed at the start of the subsequent frame.

#ifndef OBJECT_MANAGER_H_
#define OBJECT_MANAGER_H_

#include "GameObject.h"

class ObjectManager {
 public:
  ObjectManager();
  ~ObjectManager();

  void Add(std::unique_ptr<GameObject>);
  void Remove(int);

  void UpdateAll(int32_t);
  void DrawAll(sf::RenderWindow&, int32_t);

 private:
  // Vector to store game objects
  std::vector<std::unique_ptr<GameObject>> game_objects_;

  // Vectors used for delayed insertion and deletion of objects from the object vector
  std::vector<int> objects_marked_for_deletion_;
  std::vector<std::unique_ptr<GameObject>> objects_to_be_inserted_;

  void RemoveDeleted();
  void AddInserted();

  int vector_size_;
};

#endif
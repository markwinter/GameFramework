// ExampleObject.h
//
// An example object to demonstrate how to add game objects

#ifndef EXAMPLE_OBJECT_H_
#define EXAMPLE_OBJECT_H_

#include "GameObject.h"

class ExampleObject : public GameObject {
 public:
  ExampleObject();
  ~ExampleObject() override;

  void Update(int32_t) override;
  void Draw(sf::RenderWindow&, int32_t) override;
};

#endif
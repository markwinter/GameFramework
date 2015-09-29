#include "stdafx.h"
#include "ExampleObject.h"

ExampleObject::ExampleObject() {
  Load("images/example.png");
}

ExampleObject::~ExampleObject() {}

void ExampleObject::Update(int32_t dt) {}

void ExampleObject::Draw(sf::RenderWindow& window, int32_t dt) {
  window.draw(GetSprite());
}
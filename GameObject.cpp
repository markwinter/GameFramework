#include "stdafx.h"
#include "GameObject.h"

GameObject::GameObject() {

}

GameObject::~GameObject() {

}

void GameObject::Load(std::string file_name) {
  texture_.loadFromFile(file_name);
  sprite_.setTexture(texture_);
}

void GameObject::Update(int32_t dt) {}

void GameObject::Draw(sf::RenderWindow& window, int32_t dt) {
  window.draw(sprite_);
}

int GameObject::GetObjectManagerIndex() {
  return object_manager_index_;
}

void GameObject::SetObjectManagerIndex(int n) {
  object_manager_index_ = n;
}

sf::Sprite GameObject::GetSprite() {
  return sprite_;
}
#include "stdafx.h"
#include "GameObject.h"

GameObject::GameObject() {}

GameObject::GameObject(Cache<sf::Texture>& cache) : texture_cache_(cache) {}

GameObject::~GameObject() {}

void GameObject::Load(std::string file_name) {
  sprite_.setTexture(*texture_cache_.Load(file_name));
}

void GameObject::Update(int32_t dt) {}

void GameObject::Draw(sf::RenderWindow& window, int32_t dt) {
  window.draw(sprite_);
}

int GameObject::GetObjectManagerIndex() const {
  return object_manager_index_;
}

void GameObject::SetObjectManagerIndex(int n) {
  object_manager_index_ = n;
}

sf::Sprite& GameObject::GetSprite() {
  return sprite_;
}
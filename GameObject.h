// GameObject.h
// 
// The GameObject class is to be used as a base class that all objects in the game
// should inherit from in order to be used with ObjectManager

#ifndef GAME_OBJECT_H_
#define GAME_OBJECT_H_

class GameObject {
 public:
  GameObject();
  virtual ~GameObject();

  virtual void Load(std::string);
  virtual void Update(int32_t);
  virtual void Draw(sf::RenderWindow&, int32_t);

  sf::Sprite GetSprite();

  int GetObjectManagerIndex();
  void SetObjectManagerIndex(int);

 private:
  sf::Sprite sprite_;
  sf::Texture texture_;

  int object_manager_index_;
};

#endif
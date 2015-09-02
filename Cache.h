#ifndef CACHE_H_
#define CACHE_H_

#include "stdafx.h"

template <typename T>
class Cache {
 public:
  ~Cache();
  
  std::shared_ptr<T> Load(std::string);

 private:
  std::unordered_map<std::string, std::shared_ptr<T>> items_;
};

template <typename T>
inline Cache<T>::~Cache() {
  items_.clear();
}

template <typename T>
inline std::shared_ptr<T> Cache<T>::Load(std::string file_name) {
  auto itr = items_.find(file_name);

  if (itr == items_.end()) {
    std::shared_ptr<T> new_item = std::make_shared<T>();

    if (!new_item->loadFromFile(file_name)) {
      new_item.reset();
      return nullptr;
    }

    items_.insert(std::pair<std::string, std::shared_ptr<T>>(file_name, new_item));
    return new_item;
  }

  return itr->second;
}

#endif
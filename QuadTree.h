#ifndef QUAD_TREE_H_
#define QUAD_TREE_H_

#include "GameObject.h"
#include <vector>

class QuadTree {
 public:
  QuadTree();
  ~QuadTree();

  void Insert(GameObject&);
  void Remove(GameObject&);
  //void Size();

 private:
  class Node {
   public:
    Node();
    Node(int, int, int, int, int);

    void Insert(GameObject&);
    void Remove(GameObject&);
    //void Size();

    bool Contains(Node&, GameObject&);

    int Left() { return left_; }
    int Right() { return right_; }
    int Top() { return top_; }
    int Bottom() { return bottom_; }

   private:
    int max_objects_ = 3;
    int max_levels = 5;
    int left_, right_, top_, bottom_;
    int level_;
    std::vector<GameObject*> objects_;
    std::vector<std::unique_ptr<Node>> children_;
  };
  std::unique_ptr<Node> root_;
};

#endif

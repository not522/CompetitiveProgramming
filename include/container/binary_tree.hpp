#pragma once
#include "template.hpp"

template<typename T> class BinaryTree {
protected:
  struct Node {
    Node() : l(nullptr), r(nullptr) {}
    template<typename... S> Node(S... s) : l(nullptr), r(nullptr), v(s...) {}
    shared_ptr<Node> l, r;
    T v;
  };

  shared_ptr<Node> root;
  int n;

  BinaryTree() : root(nullptr), n(0) {}

public:
  T top() const {return root->v;}
  bool empty() const {return !root;}
  void clear() {root = nullptr; n = 0;}
  int size() const {return n;}
};

#pragma once
#include "arithmetic.hpp"
#include "container/binary_tree.hpp"

template<typename T> class SkewHeap : public Addition<SkewHeap<T>>, public BinaryTree<T> {
private:
  using Node = typename BinaryTree<T>::Node;

  shared_ptr<Node> merge(shared_ptr<Node> a, shared_ptr<Node> b) {
    if (!a) return b;
    if (!b) return a;
    if (a->v > b->v) swap(a, b);
    a->r = merge(b, a->r);
    swap(a->l, a->r);
    return a;
  }

public:
  template<typename... S> void emplace(S... s) {
    this->root = merge(this->root, make_shared<Node>(s...));
    ++(this->n);
  }

  void pop() {
    this->root = merge(this->root->l, this->root->r);
    --(this->n);
  }

  SkewHeap operator+=(SkewHeap x) {
    this->root = merge(this->root, x.root);
    this->n += x.size();
    return *this;
  }
};

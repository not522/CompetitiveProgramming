#pragma once
#include "graph/tree.hpp"

template<typename Tree, typename T> class TreeDP {
private:
  Vector<bool> visited;
  Vector<T> memo;

protected:
  Tree tree;

  TreeDP(const Tree& tree) : visited(tree.size(), false), memo(tree.size()), tree(tree) {}

  virtual T visit(int, const Vector<T>&) = 0;

public:
  T solve(int v) {
    if (visited[v]) return memo[v];
    Vector<T> c;
    for (const auto& child : tree.children[v]) c.emplace_back(solve(child));
    T t = visit(v, c);
    visited[v] = true;
    return memo[v] = t;
  }
};

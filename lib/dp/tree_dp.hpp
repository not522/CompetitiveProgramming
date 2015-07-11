#pragma once
#include "graph/tree.hpp"

template<typename Tree, typename T> class TreeDP {
private:
  Tree tree;
  vector<bool> visited;
  vector<T> memo;

protected:
  TreeDP(const Tree& tree) : tree(tree), visited(tree.size(), false), memo(tree.size()) {}

  virtual T visit(int, vector<T>) = 0;

public:
  T solve(int v) {
    if (visited[v]) return memo[v];
    vector<T> c;
    for (const auto& child : tree.children[v]) c.emplace_back(solve(child));
    T t = visit(v, c);
    visited[v] = true;
    return memo[v] = t;
  }
};

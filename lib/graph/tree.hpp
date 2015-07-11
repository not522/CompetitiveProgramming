#pragma once
#include "graph/graph.hpp"

template<typename Edge> class Tree {
public:
  vector<Edge> parent;
  vector<vector<int>> children;

  Tree() {}

  Tree(int n) : children(n) {
    for (int i = 0; i < n; ++i) parent.emplace_back(i, i);
  }

  int size() const {
    return parent.size();
  }
  
  template<typename... Args> void addEdge(Args... args) {
    Edge edge(args...);
    parent[edge.from] = edge;
    children[edge.to].emplace_back(edge.from);
  }
};

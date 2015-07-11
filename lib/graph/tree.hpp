#pragma once
#include "graph/graph.hpp"

template<typename Edge> class Tree {
public:
  vector<Edge> parent;

  Tree() {}

  Tree(int n) {
    for (int i = 0; i < n; ++i) parent.emplace_back(i, i);
  }

  int size() const {
    return parent.size();
  }
  
  template<typename... Args> void addEdge(Args... args) {
    Edge edge(args...);
    parent[edge.from] = edge;
  }
};

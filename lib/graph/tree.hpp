#pragma once
#include "graph/graph.hpp"

template<typename Edge> class Tree {
public:
  vector<Edge> parent;
  vector<vector<int>> children;
  vector<int> depth;

  Tree() {}

  Tree(int n) : children(n), depth(n, -1) {
    for (int i = 0; i < n; ++i) parent.emplace_back(i, i);
  }

  int size() const {
    return parent.size();
  }
  
  template<typename... Args> void addEdge(Args... args) {
    Edge edge(args...);
    parent[edge.from] = edge;
    if (edge.from != edge.to) children[edge.to].emplace_back(edge.from);
  }

  int getDepth(int v) {
    if (depth[v] != -1) return depth[v];
    if (parent[v].to == v) return depth[v] = 0;
    return depth[v] = getDepth(parent[v].to) + 1;
  }

  vector<int> getPath(int v) {
    vector<int> res{v};
    while (v != parent[v].to) {
      v = parent[v].to;
      res.emplace_back(v);
    }
    return res;
  }
};

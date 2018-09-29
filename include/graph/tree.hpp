#pragma once
#include "template.hpp"

template<typename Edge> class Tree {
public:
  using EdgeType = Edge;

  vector<Edge> parent;
  vector<vector<int>> children;
  vector<int> depth;

  Tree() {}

  Tree(int n) : children(n), depth(n, -1) {
    for (int i = 0; i < n; ++i) parent.emplace_back(i);
  }

  int size() const {
    return parent.size();
  }
  
  template<typename... Args> void addEdge(int from, int to, Args... args) {
    parent[from] = Edge(to, args...);
    children[to].emplace_back(from);
  }

  void addEdge(int from, const Edge& edge) {
    parent[from] = edge;
    children[edge.to].emplace_back(from);
  }

  vector<Edge> getEdges(int from) const {
    vector<Edge> res;
    for (int v : children[from]) {
      auto e = parent[v];
      e.to = v;
      res.emplace_back(e);
    }
    if (from != parent[from].to) res.emplace_back(parent[from]);
    return res;
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

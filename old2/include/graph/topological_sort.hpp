#pragma once
#include "graph/graph.hpp"

template <typename Graph> Vector<int> topological_sort(const Graph &graph) {
  Vector<int> deg = graph.getIndegree(), res;
  for (int v = 0; v < graph.size(); ++v) {
    if (!deg[v]) {
      res.emplace_back(v);
    }
  }
  for (int i = 0; i < graph.size(); ++i) {
    for (int v : graph[res[i]]) {
      --deg[v];
      if (!deg[v]) {
        res.emplace_back(v);
      }
    }
  }
  return res;
}

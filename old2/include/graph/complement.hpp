#pragma once
#include "unordered_set.hpp"

template <typename Graph> Graph complement(const Graph &graph) {
  Graph res(graph.size());
  for (int v = 0; v < graph.size(); ++v) {
    UnorderedSet<int> to{v, graph.size()};
    for (const auto &edge : graph[v]) {
      to.emplace(edge.to);
    }
    for (int u = 0; u < graph.size(); ++u) {
      if (!to.contains(u)) {
        res.addEdge(v, u);
      }
    }
  }
  return res;
}

#pragma once
#include "queue.hpp"
#include "vector.hpp"

template <typename Graph> Vector<bool> bipartiteColor(const Graph &graph) {
  Vector<bool> visited(graph.size()), color(graph.size());
  Queue<int> queue;
  for (int v = 0; v < graph.size(); ++v) {
    if (visited[v]) {
      continue;
    }
    queue.emplace(v);
    visited[v] = true;
    while (!queue.empty()) {
      int u = queue.front();
      for (const auto &edge : graph[u]) {
        if (visited[edge.to]) {
          if (color[u] == color[edge.to]) {
            return Vector<bool>();
          }
        } else {
          queue.emplace(edge.to);
          visited[edge.to] = true;
          color[edge.to] = !color[u];
        }
      }
    }
  }
  return color;
}

template <typename Graph> bool isBipartite(const Graph &graph) {
  return !bipartiteGraph(graph).empty();
}

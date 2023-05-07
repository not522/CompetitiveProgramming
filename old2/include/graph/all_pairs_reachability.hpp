#pragma once
#include "vector.hpp"

template <typename Graph> class WarshallFloydReachability {
private:
  const Graph &graph;

public:
  Vector<Vector<bool>> reachability;

  WarshallFloydReachability(const Graph &graph)
      : graph(graph), reachability(graph.size(), Vector<bool>(graph.size())) {
    for (int i = 0; i < graph.size(); ++i) {
      reachability[i][i] = true;
    }
  }

  void solve() {
    for (const auto &edge : graph.getAllEdges()) {
      reachability[edge.from][edge.to] = true;
    }
    for (int k = 0; k < graph.size(); ++k) {
      for (int i = 0; i < graph.size(); ++i) {
        for (int j = 0; j < graph.size(); ++j) {
          if (reachability[i][k] && reachability[k][j]) {
            reachability[i][j] = true;
          }
        }
      }
    }
  }
};

template <typename Graph> auto reachability(Graph &graph) {
  WarshallFloydReachability<Graph> warshallFloyd(graph);
  warshallFloyd.solve();
  return warshallFloyd.reachability;
}

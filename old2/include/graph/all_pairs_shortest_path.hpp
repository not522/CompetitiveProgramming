#pragma once
#include "vector.hpp"

template <typename Graph> class WarshallFloyd {
private:
  using Cost = typename Graph::EdgeType::CostType;

  const Graph &graph;

public:
  Vector<Vector<Cost>> dis;

  WarshallFloyd(const Graph &graph)
      : graph(graph),
        dis(graph.size(), Vector<Cost>(graph.size(), inf<Cost>())) {
    for (int i = 0; i < graph.size(); ++i) {
      dis[i][i] = 0;
    }
  }

  void solve() {
    for (const auto &edge : graph.getAllEdges()) {
      chmin(dis[edge.from][edge.to], edge.cost);
    }
    for (int k = 0; k < graph.size(); ++k) {
      for (int i = 0; i < graph.size(); ++i) {
        for (int j = 0; j < graph.size(); ++j) {
          if (dis[i][k] != inf<Cost>() && dis[k][j] != inf<Cost>()) {
            chmin(dis[i][j], dis[i][k] + dis[k][j]);
          }
        }
      }
    }
  }
};

template <typename Graph> auto shortestPath(Graph &graph) {
  WarshallFloyd<Graph> warshallFloyd(graph);
  warshallFloyd.solve();
  return warshallFloyd.dis;
}

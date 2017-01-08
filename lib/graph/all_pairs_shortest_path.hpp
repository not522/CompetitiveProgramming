#pragma once
#include "template.hpp"

template<typename Graph> class WarshallFloyd {
private:
  using Cost = typename Graph::EdgeType::CostType;

  const Graph& graph;

public:
  const static Cost INF = numeric_limits<Cost>::max() / 2 - 1;

  vector<vector<Cost>> dis;

  WarshallFloyd(const Graph& graph) : graph(graph), dis(graph.size(), vector<Cost>(graph.size(), INF)) {
    for (int i = 0; i < graph.size(); ++i) dis[i][i] = 0;
  }

  void solve() {
    for (const auto& edge : graph.getEdges()) {
      dis[edge.from][edge.to] = min(dis[edge.from][edge.to], edge.cost);
    }
    for (int k = 0; k < graph.size(); ++k) {
      for (int i = 0; i < graph.size(); ++i) {
        for (int j = 0; j < graph.size(); ++j) {
          if (dis[i][k] == INF || dis[k][j] == INF) continue;
          dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
        }
      }
    }
  }
};

template<typename Graph> inline vector<vector<typename Graph::EdgeType::CostType>> shortestPath(Graph& graph) {
  WarshallFloyd<Graph> warshallFloyd(graph);
  warshallFloyd.solve();
  return warshallFloyd.dis;
}

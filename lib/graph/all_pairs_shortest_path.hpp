#pragma once
#include "graph/graph.hpp"

template<typename Cost> class AllPairsShortestPath {
public:
  const Cost INF = numeric_limits<Cost>::max() / 2 - 1;
  
  template<typename Graph> vector<vector<typename Graph::EdgeType::CostType>> solve(const Graph& graph) const {
    vector<vector<Cost>> cost(graph.size(), vector<Cost>(graph.size(), INF));
    for (int i = 0; i < graph.size(); ++i) cost[i][i] = 0;
    for (const auto& edge : graph.getEdges()) {
      cost[edge.from][edge.to] = min(cost[edge.from][edge.to], edge.cost);
    }
    for (int k = 0; k < graph.size(); ++k) {
      for (int i = 0; i < graph.size(); ++i) {
        for (int j = 0; j < graph.size(); ++j) {
          cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
        }
      }
    }
    return cost;
  }
};

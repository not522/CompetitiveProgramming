#pragma once
#include "queue.hpp"
#include "vector.hpp"

template <typename Graph>
typename Graph::EdgeType::CostType bellman_ford(const Graph &graph, int from,
                                                int to) {
  using Cost = typename Graph::EdgeType::CostType;
  constexpr auto NEGATIVE_INF = -inf<Cost>();
  Vector<Cost> cost(graph.size(), inf<Cost>());
  Queue<int> que;
  Vector<bool> in(graph.size());
  Vector<int> count(graph.size());
  cost[from] = 0;
  que.emplace(from);
  in[from] = true;
  ++count[from];
  while (que.size()) {
    int v = que.front();
    in[v] = false;
    for (const auto &edge : graph[v]) {
      if (cost[v] == NEGATIVE_INF) {
        if (cost[edge.to] != NEGATIVE_INF) {
          cost[edge.to] = NEGATIVE_INF;
          if (!in[edge.to]) {
            que.emplace(edge.to);
            in[edge.to] = true;
          }
        }
      } else if (chmin(cost[edge.to], cost[v] + edge.cost)) {
        if (!in[edge.to]) {
          que.emplace(edge.to);
          in[edge.to] = true;
          ++count[edge.to];
          if (count[edge.to] == graph.size()) {
            cost[edge.to] = NEGATIVE_INF;
          }
        }
      }
    }
  }
  return cost[to];
}

#pragma once
#include "graph/residual_graph.hpp"
#include "priority_queue.hpp"

template <typename Capacity, typename Cost> class MinCostFlow {
private:
  ResidualGraph<WeightedResidualEdge<Capacity, Cost>> graph;
  Vector<int> h, dist, prevv, preve;

public:
  MinCostFlow(const ResidualGraph<WeightedResidualEdge<Capacity, Cost>> &graph)
      : graph(graph), h(graph.size()), dist(graph.size()), prevv(graph.size()),
        preve(graph.size()) {}

  Cost solve(int s, int t, Capacity f) {
    int res = 0;
    while (f > 0) {
      PriorityQueue<Tuple<int, int>, false> que;
      fill(dist.begin(), dist.end(), inf<Cost>());
      dist[0] = 0;
      que.emplace(0, s);
      while (!que.empty()) {
        auto p = que.top();
        int v = p.get<1>();
        if (dist[v] < p.get<0>()) {
          continue;
        }
        for (int i = 0; i < int(graph[v].size()); ++i) {
          const auto &e = graph[v][i];
          if (e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to]) {
            dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
            prevv[e.to] = v;
            preve[e.to] = i;
            que.emplace(dist[e.to], e.to);
          }
        }
      }
      if (dist[t] == inf<Cost>()) {
        return -1;
      }
      for (int i = 0; i < int(graph.size()); ++i) {
        h[i] += dist[i];
      }
      Capacity d = f;
      for (int i = t; i != s; i = prevv[i]) {
        d = min(d, graph[prevv[i]][preve[i]].cap);
      }
      f -= d;
      res += d * h[t];
      for (int i = t; i != s; i = prevv[i]) {
        graph.flow(prevv[i], preve[i], d);
      }
    }
    return res;
  }
};

template <typename Capacity, typename Cost>
Cost minCostFlow(
    const ResidualGraph<WeightedResidualEdge<Capacity, Cost>> &graph, int s,
    int t, int f) {
  MinCostFlow<Capacity, Cost> mcf(graph);
  return mcf.solve(s, t, f);
}

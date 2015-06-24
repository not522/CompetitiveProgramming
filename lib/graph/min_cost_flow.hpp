#pragma once
#include "graph/edge.hpp"
#include "graph/residual_graph.hpp"

template<typename Capacity, typename Cost> class MinCostFlow {
private:
  const Cost INF;

  ResidualGraph<WeightedResidualEdge<Capacity, Cost>> graph;
  vector<int> h, dist, prevv, preve;
  
public:
  MinCostFlow(const ResidualGraph<WeightedResidualEdge<Capacity, Cost>>& graph) : INF(numeric_limits<Cost>::max()), graph(graph), h(graph.size(), 0), dist(graph.size(), 0), prevv(graph.size(), 0), preve(graph.size(), 0) {}
  
  Cost solve(int s, int t, Capacity f) {
    int res = 0;
    while (f > 0) {
      priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
      fill(dist.begin(), dist.end(), INF);
      dist[0] = 0;
      que.push(make_pair(0, s));
      while (!que.empty()) {
        auto p = que.top();
        que.pop();
        int v = p.second;
        if (dist[v] < p.first) continue;
        for (int i = 0; i < int(graph[v].size()); ++i) {
          const auto& e = graph[v][i];
          if (e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to]) {
            dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
            prevv[e.to] = v;
            preve[e.to] = i;
            que.push(make_pair(dist[e.to], e.to));
          }
        }
      }
      if (dist[t] == INF) return -1;
      for (int i = 0; i < int(graph.size()); ++i) h[i] += dist[i];
      Capacity d = f;
      for (int i = t; i != s; i = prevv[i]) d = min(d, graph[prevv[i]][preve[i]].cap);
      f -= d;
      res += d * h[t];
      for (int i = t; i != s; i = prevv[i]) graph.flow(prevv[i], preve[i], d);
    }
    return res;
  }
};

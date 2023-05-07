#pragma once
#include "graph/residual_graph.hpp"
#include "queue.hpp"

template <typename Capacity> class MaxFlow {
private:
  ResidualGraph<ResidualEdge<Capacity>> &graph;
  Vector<int> level, iter;

  void bfs(int source) {
    fill(level.begin(), level.end(), -1);
    level[source] = 0;
    Queue<int> que;
    que.push(source);
    while (!que.empty()) {
      int v = que.front();
      for (const auto &edge : graph[v]) {
        if (edge.cap == 0 || level[edge.to] >= 0) {
          continue;
        }
        level[edge.to] = level[v] + 1;
        que.push(edge.to);
      }
    }
  }

  int dfs(int v, int sink, Capacity flow) {
    if (v == sink) {
      return flow;
    }
    for (int &i = iter[v]; i < int(graph[v].size()); ++i) {
      auto &edge = graph[v][i];
      if (edge.cap == 0 || level[v] >= level[edge.to]) {
        continue;
      }
      Capacity f = dfs(edge.to, sink, min(flow, edge.cap));
      if (f == 0) {
        continue;
      }
      graph.flow(v, i, f);
      return f;
    }
    return 0;
  }

public:
  MaxFlow(ResidualGraph<ResidualEdge<Capacity>> &graph) : graph(graph) {}

  Capacity solve(int source, int sink) {
    level = Vector<int>(graph.size(), 0);
    iter = Vector<int>(graph.size(), 0);
    Capacity flow = 0, f;
    while (true) {
      bfs(source);
      if (level[sink] < 0) {
        return flow;
      }
      fill(iter.begin(), iter.end(), 0);
      while ((f = dfs(source, sink, inf<Capacity>())) > 0) {
        flow += f;
      }
    }
  }
};

template <typename Capacity>
Capacity maxFlow(ResidualGraph<ResidualEdge<Capacity>> &graph, int source,
                 int sink) {
  MaxFlow<Capacity> dinic(graph);
  return dinic.solve(source, sink);
}

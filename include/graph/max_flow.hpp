#pragma once
#include "graph/edge.hpp"
#include "graph/residual_graph.hpp"

class MaxFlow {
private:
  template<typename Capacity> class Dinic {
  private:
    const Capacity INF;

    ResidualGraph<ResidualEdge<Capacity>>& graph;
    vector<int> level, iter;

    void bfs(int source) {
      fill(level.begin(), level.end(), -1);
      level[source] = 0;
      queue<int> que;
      que.push(source);
      while (!que.empty()) {
        int v = que.front();
        que.pop();
        for (const auto& edge : graph[v]) {
          if (edge.cap == 0 || level[edge.to] >= 0) continue;
          level[edge.to] = level[v] + 1;
          que.push(edge.to);
        }
      }
    }

    int dfs(int v, int sink, Capacity flow) {
      if (v == sink) return flow;
      for (int& i = iter[v]; i < int(graph[v].size()); ++i) {
        auto& edge = graph[v][i];
        if (edge.cap == 0 || level[v] >= level[edge.to]) continue;
        Capacity f = dfs(edge.to, sink, min(flow, edge.cap));
        if (f == 0) continue;
        graph.flow(v, i, f);
        return f;
      }
      return 0;
    }

  public:
    Dinic(ResidualGraph<ResidualEdge<Capacity>>& graph) : INF(numeric_limits<Capacity>::max()), graph(graph) {}

    Capacity solve(int source, int sink) {
      level = vector<int>(graph.size(), 0);
      iter = vector<int>(graph.size(), 0);
      Capacity flow = 0, f;
      while (true) {
        bfs(source);
        if (level[sink] < 0) return flow;
        fill(iter.begin(), iter.end(), 0);
        while ((f = dfs(source, sink, INF)) > 0) flow += f;
      }
    }
  };

public:
  template<typename Capacity> Capacity solve(ResidualGraph<ResidualEdge<Capacity>>& graph, int source, int sink) {
    Dinic<Capacity> dinic(graph);
    return dinic.solve(source, sink);
  }
};

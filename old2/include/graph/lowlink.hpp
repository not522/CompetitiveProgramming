#pragma once
#include "graph/graph.hpp"

template <typename Graph> class LowLink {
private:
  using Edge = typename Graph::EdgeType;

  const Graph graph;
  Vector<bool> visited;
  Vector<int> ord, low;
  int k;

  void dfs(int pos, int par = -1) {
    visited[pos] = true;
    low[pos] = ord[pos] = k;
    ++k;
    for (const auto &edge : graph.getEdges(pos)) {
      int next = edge.to;
      if (!visited[next]) {
        dfs(next, pos);
        chmin(low[pos], low[next]);
      } else if (next != par) {
        chmin(low[pos], ord[next]);
      }
    }
  }

public:
  LowLink(const Graph &graph)
      : graph(graph), visited(graph.size()), ord(graph.size()),
        low(graph.size()), k(0) {
    for (int i = 0; i < int(graph.size()); ++i) {
      if (!visited[i]) {
        dfs(i);
      }
    }
  }

  Vector<FullEdge<Edge>> bridge() {
    Vector<FullEdge<Edge>> res;
    for (const auto &edge : graph.getAllEdges()) {
      if (ord[edge.from] < low[edge.to]) {
        res.emplace_back(edge);
      }
    }
    return res;
  }
};

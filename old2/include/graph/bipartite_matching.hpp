#pragma once
#include "graph/adjacency_list.hpp"

class BipartiteMatching {
private:
  AdjacencyList<Edge> graph;
  Vector<bool> used;

  bool dfs(int v) {
    used[v] = true;
    for (const Edge &u : graph[v]) {
      int w = match[u.to];
      if (w < 0 || (!used[w] && dfs(w))) {
        match[v] = u.to;
        match[u.to] = v;
        return true;
      }
    }
    return false;
  }

public:
  Vector<int> match;

  BipartiteMatching(const AdjacencyList<Edge> &graph)
      : graph(graph), used(graph.size()), match(graph.size(), -1) {}

  int solve() {
    int res = 0;
    for (int i = 0; i < graph.size(); ++i) {
      if (match[i] >= 0) {
        continue;
      }
      fill(used.begin(), used.end(), false);
      if (dfs(i)) {
        ++res;
      }
    }
    return res;
  }
};

int bipartiteMatching(const AdjacencyList<Edge> &graph) {
  BipartiteMatching bm(graph);
  return bm.solve();
}

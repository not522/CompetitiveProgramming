#pragma once
#include "graph/edge.hpp"
#include "graph/adjacency_list.hpp"

class BipartiteMatching {
private:
  AdjacencyList<Edge> graph;
  vector<int> match;
  vector<bool> used;
  
  bool dfs(int v) {
    used[v] = true;
    for (const Edge& u : graph[v]) {
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
  BipartiteMatching(const AdjacencyList<Edge>& graph) : graph(graph), match(graph.size(), -1), used(graph.size()) {}
  
  int run() {
    int res = 0;
    for (int i = 0; i < graph.size(); ++i) {
      if (match[i] >= 0) continue;
      fill(used.begin(), used.end(), false);
      if (dfs(i)) ++res;
    }
    return res;
  }
};

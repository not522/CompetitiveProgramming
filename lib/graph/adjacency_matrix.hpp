#pragma once
#include "graph/graph.hpp"

template<typename Edge> class AdjacencyMatrix : public Graph<Edge> {
private:
  vector<vector<vector<Edge>>> graph;

public:
  AdjacencyMatrix(int n) : graph(n, vector<vector<Edge>>(n, vector<Edge>())) {}

  int size() const {
    return graph.size();
  }

  template<typename... Args> void addEdge(int from, int to, Args... args) {
    graph[from][to].emplace_back(to, args...);
  }

  template<typename... Args> void addUndirectedEdge(int from, int to, Args... args) {
    addEdge(from, to, args...);
    addEdge(to, from, args...);
  }

  vector<Edge> getEdges(int from) const {
    vector<Edge> res;
    for (const auto& edge : graph[from]) {
      res.insert(res.end(), edge.begin(), edge.end());
    }
    return res;
  }

  vector<Edge> getEdges(int from, int to) const {
    return graph[from][to];
  }

  int getDegree(int v) const {
    int res = 0;
    for (const auto& edges : graph[v]) res += edges.size();
    return res;
  }
};

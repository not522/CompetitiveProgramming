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

  template<typename... Args> void addEdge(Args... args) {
    Edge edge(args...);
    graph[edge.from][edge.to].emplace_back(edge);
  }

  template<typename... Args> void addUndirectedEdge(Args... args) {
    Edge edge(args...);
    addEdge(edge);
    swap(edge.from, edge.to);
    addEdge(edge);
  }

  vector<Edge> getEdges() const {
    vector<Edge> res;
    for (const auto& edges : graph) {
      for (const auto& edge : edges) {
        res.insert(res.end(), edge.begin(), edge.end());
      }
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

#pragma once
#include "graph/graph.hpp"

template<typename Edge> class AdjacencyMatrix : public Graph<Edge> {
private:
  vector<vector<Edge>> graph;

public:
  AdjacencyMatrix(int n) : graph(n, vector<Edge>(n)) {}

  int size() const {return graph.size();}

  template<typename... Args> void addEdge(int from, int to, Args... args) {
    graph[from][to] = Edge(to, args...);
  }

  template<typename... Args> void addUndirectedEdge(int from, int to, Args... args) {
    addEdge(from, to, args...);
    addEdge(to, from, args...);
  }

  vector<Edge> getEdges(int from) const {
    vector<Edge> res;
    for (const auto& edge : graph[from]) {
      if (!edge.isNone()) res.emplace_back(edge);
    }
    return res;
  }

  Edge getEdge(int from, int to) const {
    return graph[from][to];
  }
};

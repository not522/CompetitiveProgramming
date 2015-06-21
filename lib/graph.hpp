#include "template.hpp"

template<typename Edge> class Graph {
protected:
  vector<vector<Edge>> graph;

public:
  Graph(int n = 0) : graph(n) {}
  
  void addEdge(const Edge& edge) {
    if (int(graph.size()) <= max(edge.from, edge.to)) graph.resize(max(edge.from, edge.to) + 1);
    graph[edge.from].emplace_back(edge);
  }
};

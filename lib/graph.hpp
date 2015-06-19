#include "template.hpp"

template<typename Edge> class Graph {
protected:
  vector<vector<Edge>> edges;

public:
  Graph(int n = 0) : edges(n) {}
  
  void addEdge(const Edge& edge) {
    if (int(edges.size()) <= max(edge.from, edge.to)) edges.resize(max(edge.from, edge.to) + 1);
    edges[edge.from].emplace_back(edge);
  }
};

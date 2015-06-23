#pragma once
#include "graph/graph.hpp"

template<typename Edge> class AdjacencyList : public Graph<Edge> {
protected:
  vector<vector<Edge>> graph;

public:
  AdjacencyList(int n) : graph(n) {}

  int size() const {
    return graph.size();
  }
  
  void addEdge(const Edge& edge) {
    graph[edge.from].emplace_back(edge);
  }

  void addUndirectedEdge(Edge edge) {
    addEdge(edge);
    swap(edge.from, edge.to);
    addEdge(edge);
  }

  vector<Edge> getEdges(int from, int to) const {
    vector<Edge> res;
    for (const auto& edge : graph[from]) {
      if (edge.to == to) res.emplace_back(edge);
    }
    return res;
  }

  int getDegree(int v) const {
    return graph[v].size();
  }

  vector<Edge>& operator[](int v) {
    return graph[v];
  }
};

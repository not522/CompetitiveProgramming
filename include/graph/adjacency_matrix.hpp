#pragma once
#include "graph/graph.hpp"

template<typename Edge> class AdjacencyMatrix : public Graph<Edge> {
private:
  vector<vector<Edge>> graph;

public:
  using EdgeType = Edge;

  AdjacencyMatrix() = default;

  AdjacencyMatrix(int n) : graph(n, vector<Edge>(n)) {}

  int size() const {return graph.size();}

  template<typename... Args> void addEdge(int from, int to, Args... args) {
    graph[from][to] = Edge(to, args...);
  }

  void addEdge(const FullEdge<Edge>& edge) {
    graph[edge.from].emplace_back(edge);
  }

  template<typename... Args> void addUndirectedEdge(int from, int to, Args... args) {
    addEdge(from, to, args...);
    addEdge(to, from, args...);
  }

  void addUndirectedEdge(FullEdge<Edge> edge) {
    graph[edge.from].emplace_back(edge);
    swap(edge.from, edge.to);
    graph[edge.to].emplace_back(edge);
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

  bool hasEdge(int from, int to) const {
    return !graph[from][to].isNone();
  }
};

template<typename Edge> istream& operator>>(istream& s, AdjacencyMatrix<Edge>& graph) {
  int n, m;
  cin >> n >> m;
  graph = readGraph<AdjacencyMatrix<Edge>>(n, m);
  return s;
}

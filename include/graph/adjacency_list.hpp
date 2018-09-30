#pragma once
#include "graph/graph.hpp"

template<typename Edge> class AdjacencyList : public Graph<Edge> {
protected:
  vector<vector<Edge>> graph;

public:
  using EdgeType = Edge;

  AdjacencyList() = default;

  AdjacencyList(int n) : graph(n) {}

  int size() const {
    return graph.size();
  }
  
  template<typename... Args> void addEdge(int from, int to, Args... args) {
    graph[from].emplace_back(to, args...);
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
    graph[edge.from].emplace_back(edge);
  }

  vector<Edge> getEdges(int from) const {
    return graph[from];
  }

  Edge getEdge(int from, int to) const {
    Edge res;
    for (const auto& edge : graph[from]) {
      if (edge.to == to) res = edge;
    }
    return res;
  }

  bool hasEdge(int from, int to) const {
    for (const auto& edge : graph[from]) {
      if (edge.to == to) return true;
    }
    return false;
  }

  vector<Edge>& operator[](int v) {
    return graph[v];
  }
};

template<typename Edge> istream& operator>>(istream& s, AdjacencyList<Edge>& graph) {
  int n, m;
  cin >> n >> m;
  graph = readGraph<AdjacencyList<Edge>>(n, m);
  return s;
}

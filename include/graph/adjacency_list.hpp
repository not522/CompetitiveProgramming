#pragma once
#include "graph/graph.hpp"

template <typename Edge> class AdjacencyList : public Graph<Edge> {
protected:
  Vector<Vector<Edge>> graph;

public:
  using EdgeType = Edge;

  AdjacencyList() = default;

  AdjacencyList(int n) : graph(n) {}

  AdjacencyList(Input &in, bool undirected = true, bool one_origin = true) {
    int n(in), m(in);
    *this = readGraph<AdjacencyList<Edge>>(in, n, m, undirected, one_origin);
  }

  AdjacencyList(Input &in, int n, int m, bool undirected = true,
                bool one_origin = true) {
    *this = readGraph<AdjacencyList<Edge>>(in, n, m, undirected, one_origin);
  }

  int size() const { return graph.size(); }

  template <typename... Args> void addEdge(int from, int to, Args... args) {
    graph[from].emplace_back(to, args...);
  }

  void addEdge(const FullEdge<Edge> &edge) {
    graph[edge.from].emplace_back(edge);
  }

  template <typename... Args>
  void addUndirectedEdge(int from, int to, Args... args) {
    addEdge(from, to, args...);
    addEdge(to, from, args...);
  }

  void addUndirectedEdge(FullEdge<Edge> edge) {
    graph[edge.from].emplace_back(edge);
    swap(edge.from, edge.to);
    graph[edge.from].emplace_back(edge);
  }

  Vector<Edge> getEdges(int from) const { return graph[from]; }

  Edge getEdge(int from, int to) const {
    for (const auto &edge : graph[from]) {
      if (edge.to == to) {
        return edge;
      }
    }
    return Edge();
  }

  bool hasEdge(int from, int to) const {
    for (const auto &edge : graph[from]) {
      if (edge.to == to) {
        return true;
      }
    }
    return false;
  }

  Vector<Edge> &operator[](int v) { return graph[v]; }

  const Vector<Edge> &operator[](int v) const { return graph[v]; }
};

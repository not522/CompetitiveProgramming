#pragma once
#include "graph/graph.hpp"

template <typename Edge> class AdjacencyMatrix : public Graph<Edge> {
private:
  Vector<Vector<Edge>> graph;

public:
  using EdgeType = Edge;

  AdjacencyMatrix() = default;

  AdjacencyMatrix(int n) : graph(n, Vector<Edge>(n)) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        graph[i][j].to = -1;
      }
    }
  }

  AdjacencyMatrix(Input &in, int n, int m, bool undirected = true,
                  bool one_origin = true) {
    *this = readGraph<AdjacencyMatrix<Edge>>(in, n, m, undirected, one_origin);
  }

  int size() const { return graph.size(); }

  template <typename... Args> void addEdge(int from, int to, Args... args) {
    graph[from][to] = Edge(to, args...);
  }

  void addEdge(const FullEdge<Edge> &edge) { graph[edge.from][edge.to] = edge; }

  template <typename... Args>
  void addUndirectedEdge(int from, int to, Args... args) {
    addEdge(from, to, args...);
    addEdge(to, from, args...);
  }

  void addUndirectedEdge(FullEdge<Edge> edge) {
    graph[edge.from][edge.to] = edge;
    swap(edge.from, edge.to);
    graph[edge.from][edge.to] = edge;
  }

  Vector<Edge> getEdges(int from) const {
    Vector<Edge> res;
    for (const auto &edge : graph[from]) {
      if (!edge.isNone()) {
        res.emplace_back(edge);
      }
    }
    return res;
  }

  Edge getEdge(int from, int to) const { return graph[from][to]; }

  bool hasEdge(int from, int to) const { return !graph[from][to].isNone(); }
};

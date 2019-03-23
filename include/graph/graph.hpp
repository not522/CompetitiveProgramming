#pragma once
#include "graph/edge.hpp"
#include "vector.hpp"

template<typename Edge> class Graph {
public:
  using EdgeType = Edge;

  virtual int size() const = 0;
  template<typename... Args> void addEdge(int from, int to, Args...) {
    (void)from;
    (void)to;
  }
  template<typename... Args> void addUndirectedEdge(int from, int to, Args...) {
    (void)from;
    (void)to;
  }

  Vector<FullEdge<Edge>> getAllEdges() const {
    Vector<FullEdge<Edge>> res;
    for (int i = 0; i < size(); ++i) {
      for (const auto& edge : getEdges(i)) {
        res.emplace_back(i, edge);
      }
    }
    return res;
  }

  virtual Vector<Edge> getEdges(int from) const = 0;
  virtual Edge getEdge(int from, int to) const = 0;
  virtual bool hasEdge(int from, int to) const = 0;

  int getDegree(int v) const {
    return getEdges(v).size();
  }

  Vector<int> getIndegree() const {
    Vector<int> degree(size());
    for (const auto& edge : getAllEdges()) ++degree[edge.to];
    return degree;
  }
};

template<typename Graph> Graph readGraph(Input &in, int n, int m, bool undirected = true, bool one_origin = true) {
  Graph graph(n);
  for (int i = 0; i < m; ++i) {
    FullEdge<typename Graph::EdgeType> edge(in);
    if (one_origin) {
      --edge.from;
      --edge.to;
    }
    if (undirected) graph.addUndirectedEdge(edge);
    else graph.addEdge(edge);
  }
  return graph;
}

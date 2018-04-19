#pragma once
#include "template.hpp"

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

  vector<pair<int, Edge>> getAllEdges() const {
    vector<pair<int, Edge>> res;
    for (int i = 0; i < size(); ++i) {
      for (const auto& edge : getEdges(i)) {
        res.emplace_back(i, edge);
      }
    }
    return res;
  }

  virtual vector<Edge> getEdges(int from) const = 0;
  virtual vector<Edge> getEdges(int from, int to) const = 0;
  virtual int getDegree(int v) const = 0;

  vector<int> getIndegree() const {
    vector<int> degree(size());
    for (const auto& edge : getAllEdges()) ++degree[edge.second.to];
    return degree;
  }
};

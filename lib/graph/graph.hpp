#pragma once
#include "template.hpp"

template<typename Edge> class Graph {
public:
  typedef Edge EdgeType;
  virtual int size() const = 0;
  template<typename... Args> void addEdge(Args...) {}
  template<typename... Args> void addUndirectedEdge(Args...) {}
  virtual vector<Edge> getEdges(int from, int to) const = 0;
  virtual int getDegree(int v) const = 0;
};

#pragma once
#include "template.hpp"

template<typename Edge> class Graph {
public:
  typedef Edge EdgeType;
  virtual int size() const = 0;
  virtual void addEdge(const Edge& edge) = 0;
  virtual void addUndirectedEdge(Edge edge) = 0;
  virtual vector<Edge> getEdges(int from, int to) const = 0;
  virtual int getDegree(int v) const = 0;
};

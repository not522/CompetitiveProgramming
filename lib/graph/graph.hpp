#pragma once
#include "template.hpp"

template<typename Edge> class Graph {
public:
  virtual int size() const {return 0;};
  virtual vector<Edge> edges(int v) const {(void)v; return vector<Edge>();}
  virtual void addEdge(const Edge& edge) {(void)edge;};
  virtual void addUndirectedEdge(Edge edge) {(void)edge;};
  virtual vector<Edge> getEdges(int from, int to) const {(void)from; (void)to; return vector<Edge>();};
  virtual int getDegree(int v) const {(void)v; return 0;}
};

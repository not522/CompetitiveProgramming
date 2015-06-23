#pragma once
#include "graph/adjacency_list.hpp"

template<typename Edge> class ResidualGraph : public AdjacencyList<Edge> {
public:
  ResidualGraph(int n) : AdjacencyList<Edge>(n) {}
  
  void add_edge(const Edge& edge) {
    Edge e = edge;
    e.rev = this->graph[edge.to].size();
    this->graph[edge.from].emplace_back(e);
    Edge rev = edge.reverse();
    this->graph[rev.from].emplace_back(rev);
  }

  void flow(int v, int i, typename Edge::CapacityType f) {
    auto& e = this->graph[v][i];
    e.cap -= f;
    this->graph[e.to][e.rev].cap += f;
  }
};

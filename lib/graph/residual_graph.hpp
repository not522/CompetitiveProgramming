#pragma once
#include "graph/adjacency_list.hpp"

template<typename Edge> class ResidualGraph : public AdjacencyList<Edge> {
public:
  ResidualGraph(int n) : AdjacencyList<Edge>(n) {}

  template<typename... Args> void addEdge(Args... args) {
    Edge edge(args...);
    edge.rev = this->graph[edge.to].size();
    this->graph[edge.from].emplace_back(edge);
    Edge rev = edge.reverse();
    rev.rev = this->graph[rev.to].size() - 1;
    this->graph[rev.from].emplace_back(rev);
  }

  template<typename... Args> void addUndirectedEdge(Args... args) {
    Edge edge(args...);
    edge.rev = this->graph[edge.to].size();
    this->graph[edge.from].emplace_back(edge);
    Edge rev = edge.reverse();
    rev.rev = this->graph[rev.to].size() - 1;
    rev.cap = edge.cap;
    this->graph[rev.from].emplace_back(rev);
  }

  void flow(int v, int i, typename Edge::CapacityType f) {
    auto& e = this->graph[v][i];
    e.cap -= f;
    this->graph[e.to][e.rev].cap += f;
  }
};

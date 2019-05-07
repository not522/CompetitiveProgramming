#pragma once
#include "graph/adjacency_list.hpp"

template <typename Edge> class ResidualGraph : public AdjacencyList<Edge> {
public:
  ResidualGraph(int n) : AdjacencyList<Edge>(n) {}

  ResidualGraph(Input &in, int n, int m, bool undirected = true,
                bool one_origin = true) {
    *this = readGraph<ResidualGraph<Edge>>(in, n, m, undirected, one_origin);
  }

  template <typename... Args> void addEdge(int from, int to, Args... args) {
    Edge edge(to, args...);
    Edge rev = edge.reverse(from);
    edge.rev = this->graph[to].size();
    rev.rev = this->graph[from].size();
    this->graph[from].emplace_back(edge);
    this->graph[to].emplace_back(rev);
  }

  void addEdge(const FullEdge<Edge> &e) {
    Edge edge = e;
    Edge rev = edge.reverse(e.from);
    edge.rev = this->graph[edge.to].size();
    rev.rev = this->graph[e.from].size();
    this->graph[e.from].emplace_back(edge);
    this->graph[edge.to].emplace_back(rev);
  }

  template <typename... Args>
  void addUndirectedEdge(int from, int to, Args... args) {
    addEdge(from, to, args...);
    this->graph[to].back().cap = this->graph[from].back().cap;
  }

  void addUndirectedEdge(const FullEdge<Edge> &e) {
    Edge edge = e;
    addEdge(e.from, edge);
    this->graph[edge.to].back().cap = this->graph[e.from].back().cap;
  }

  void flow(int v, int i, typename Edge::CapacityType f) {
    auto &e = this->graph[v][i];
    e.cap -= f;
    this->graph[e.to][e.rev].cap += f;
  }
};

#pragma once
#include "template.hpp"

template<typename Edge> struct FullEdge : public Edge {
  int from;

  FullEdge() = default;

  FullEdge(const int from, const Edge& edge) : Edge(edge), from(from) {}

  FullEdge(Input &in) {
    int from(in);
    Edge edge(in);
    *this = FullEdge(from, edge);
  }
};

struct Edge {
  using CostType = int;
  const static int cost = 1;
  int to;
  Edge(int to = -1) : to(to) {}

  Edge(Input &in) : to(in) {}

  bool isNone() const {return to == -1;}

  operator int() const {return to;}
};

std::ostream& operator<<(std::ostream& s, const FullEdge<Edge>& edge) {
  s << '(' << edge.from << ',' << edge.to << ')';
  return s;
}

template<typename Cost> struct WeightedEdge : public Edge {
  using CostType = Cost;
  Cost cost;
  WeightedEdge(int to = -1, Cost cost = 0) : Edge(to), cost(cost) {}

  WeightedEdge(Input &in) : Edge(in), cost(in) {}
};

template<typename Cost> std::ostream& operator<<(std::ostream& s, const FullEdge<WeightedEdge<Cost>>& edge) {
  s << '(' << edge.from << ',' << edge.to << ',' << edge.cost << ')';
  return s;
}

template<typename Capacity> struct ResidualEdge : public Edge {
  using CapacityType = Capacity;
  Capacity cap;
  int rev;
  ResidualEdge(int to = -1, Capacity cap = 0) : Edge(to), cap(cap) {}

  ResidualEdge(Input &in) {
    Edge edge(in);
    Capacity cap(in);
    *this = ResidualEdge(edge, cap);
  }

  ResidualEdge reverse(int from) const {return ResidualEdge(from, 0);}
};

template<typename Capacity, typename Cost> struct WeightedResidualEdge : public ResidualEdge<Capacity> {
  Cost cost;
  WeightedResidualEdge(int to = -1, Capacity cap = 0, Cost cost = 0) : ResidualEdge<Capacity>(to, cap), cost(cost) {}

  WeightedResidualEdge(Input &in) {
    ResidualEdge<Capacity> edge(in);
    Cost cost(in);
    *this = WeightedResidualEdge(edge, cost);
  }

  WeightedResidualEdge reverse(int from) const {return WeightedResidualEdge(from, 0, -cost);}
};

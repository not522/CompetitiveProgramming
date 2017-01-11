#pragma once
#include "template.hpp"

struct Edge {
  using CostType = int;
  const static int cost = 1;
  int to;
  Edge(int to) : to(to) {};
};

template<typename Cost> struct WeightedEdge : public Edge {
  using CostType = Cost;
  Cost cost;
  WeightedEdge(int to, Cost cost = 0) : Edge(to), cost(cost) {}
};

template<typename Capacity> struct ResidualEdge : public Edge {
  using CapacityType = Capacity;
  Capacity cap;
  int rev;
  ResidualEdge(int to, Capacity cap) : Edge(to), cap(cap) {}
  ResidualEdge reverse(int from) const {return ResidualEdge(from, 0);}
};

template<typename Capacity, typename Cost> struct WeightedResidualEdge : public ResidualEdge<Capacity> {
  Cost cost;
  WeightedResidualEdge(int to, Capacity cap, Cost cost) : ResidualEdge<Capacity>(to, cap), cost(cost) {}
  WeightedResidualEdge reverse(int from) const {return WeightedResidualEdge(from, 0, -cost);}
};

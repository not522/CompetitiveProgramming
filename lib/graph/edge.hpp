#pragma once
#include "template.hpp"

struct Edge {
  using CostType = int;
  const static int cost = 1;
  int from, to;
  Edge(int from, int to) : from(from), to(to) {};
};

template<typename Cost> struct WeightedEdge : public Edge {
  using CostType = Cost;
  Cost cost;
  WeightedEdge(int from, int to, Cost cost = 0) : Edge(from, to), cost(cost) {}
};

template<typename Capacity> struct ResidualEdge : public Edge {
  using CapacityType = Capacity;
  Capacity cap;
  int rev;
  ResidualEdge(int from, int to, Capacity cap) : Edge(from, to), cap(cap) {}
  ResidualEdge reverse() const {return ResidualEdge(to, from, 0);}
};

template<typename Capacity, typename Cost> struct WeightedResidualEdge : public ResidualEdge<Capacity> {
  Cost cost;
  WeightedResidualEdge(int from, int to, Capacity cap, Cost cost) : ResidualEdge<Capacity>(from, to, cap), cost(cost) {}
  WeightedResidualEdge reverse() const {return WeightedResidualEdge(this->to, this->from, 0, -cost);}
};

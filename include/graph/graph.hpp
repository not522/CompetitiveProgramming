#pragma once
#include "vector.hpp"

struct Edge {
  using CostType = int;
  const static int cost = 1;
  int to;
  Edge(int to = -1) : to(to) {}

  Edge(Input &in) : to(in) {}

  bool isNone() const {return to == -1;}

  operator int() const {return to;}
};

std::ostream& operator<<(std::ostream& s, const Edge& edge) {
  s << edge.to;
  return s;
}

template<typename Cost> struct WeightedEdge : public Edge {
  using CostType = Cost;
  Cost cost;
  WeightedEdge(int to = -1, Cost cost = 0) : Edge(to), cost(cost) {}

  WeightedEdge(Input &in) : Edge(in), cost(in) {}
};

template<typename Cost> std::ostream& operator<<(std::ostream& s, const WeightedEdge<Cost>& edge) {
  s << edge.to << ',' << edge.cost;
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

template<typename Edge> std::ostream& operator<<(std::ostream& s, const FullEdge<Edge>& edge) {
  s << '(' << edge.from << ',' << Edge(edge) << ')';
  return s;
}

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

  Vector<FullEdge<Edge>> getAllEdges() const {
    Vector<FullEdge<Edge>> res;
    for (int i = 0; i < size(); ++i) {
      for (const auto& edge : getEdges(i)) {
        res.emplace_back(i, edge);
      }
    }
    return res;
  }

  virtual Vector<Edge> getEdges(int from) const = 0;
  virtual Edge getEdge(int from, int to) const = 0;
  virtual bool hasEdge(int from, int to) const = 0;

  int getDegree(int v) const {
    return getEdges(v).size();
  }

  Vector<int> getIndegree() const {
    Vector<int> degree(size());
    for (const auto& edge : getAllEdges()) ++degree[edge.to];
    return degree;
  }
};

template<typename Graph> Graph readGraph(Input &in, int n, int m, bool undirected, bool one_origin) {
  Graph graph(n);
  for (int i = 0; i < m; ++i) {
    FullEdge<typename Graph::EdgeType> edge(in);
    if (one_origin) {
      --edge.from;
      --edge.to;
    }
    if (undirected) graph.addUndirectedEdge(edge);
    else graph.addEdge(edge);
  }
  return graph;
}

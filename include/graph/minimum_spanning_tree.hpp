#pragma once
#include "graph/shortest_path.hpp"

template <typename Edge> struct PrimState : public DijkstraState<Edge> {
  PrimState(int pos) : DijkstraState<Edge>(pos) {}

  PrimState(const int from, const Edge &edge,
            typename DijkstraState<Edge>::Cost cost)
      : DijkstraState<Edge>(from, edge, cost) {}

  PrimState next(const int from, const Edge &edge) const {
    return PrimState(from, edge, edge.cost);
  }
};

template <typename Graph>
Tree<typename Graph::EdgeType> minimumSpanningTree(Graph &graph) {
  Dijkstra<Graph, true, PrimState<typename Graph::EdgeType>> prim(graph);
  prim.solve(0);
  return prim.shortestPathTree;
}

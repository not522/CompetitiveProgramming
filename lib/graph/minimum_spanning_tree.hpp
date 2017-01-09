#pragma once
#include "graph/shortest_path.hpp"

template<typename Edge> struct PrimState : public DijkstraState<Edge> {
  PrimState(int pos) : DijkstraState<Edge>(pos) {}

  PrimState(const Edge& edge, typename DijkstraState<Edge>::Cost cost) : DijkstraState<Edge>(edge, cost) {}

  PrimState next(const Edge& edge) const {
    return PrimState(edge, edge.cost);
  }
};

template<typename Graph> Tree<typename Graph::EdgeType> minimumSpanningTree(Graph& graph) {
  Dijkstra<Graph, true, PrimState<typename Graph::EdgeType>> prim(graph);
  prim.solve(0);
  return prim.shortestPathTree;
}

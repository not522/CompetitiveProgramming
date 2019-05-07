#pragma once
#include "graph/search.hpp"
#include "graph/tree.hpp"
#include "priority_queue.hpp"

template <typename Edge> struct DijkstraState {
  using Cost = typename Edge::CostType;

  int from;
  Edge edge;
  Cost cost;

  DijkstraState(const int pos) : from(pos), edge(pos), cost(0) {}

  DijkstraState(const int from, const Edge &edge, const Cost cost)
      : from(from), edge(edge), cost(cost) {}

  DijkstraState next(const int from, const Edge &edge) const {
    return DijkstraState(from, edge, cost + edge.cost);
  }

  bool operator<(const DijkstraState &state) const { return cost > state.cost; }

  int getPos() const { return edge.to; }
};

template <typename Graph, bool Restoration = false,
          typename State = DijkstraState<typename Graph::EdgeType>>
class Dijkstra : public Search<Graph, State> {
protected:
  using Edge = typename Graph::EdgeType;
  using Cost = typename Edge::CostType;

  PriorityQueue<State> que;

  void push(const State &state) {
    if (dis[state.getPos()] <= state.cost) {
      return;
    }
    que.push(state);
    dis[state.getPos()] = state.cost;
  }

  State next() {
    State now = que.top();
    return now;
  }

  bool isRunning() { return !que.empty(); }

  void visit(const State &state) {
    if (Restoration) {
      int from = state.from, to = state.edge.to;
      if (from != to) {
        auto e = state.edge;
        e.to = from;
        shortestPathTree.addEdge(to, e);
      }
    }
  }

public:
  Vector<Cost> dis;
  Tree<Edge> shortestPathTree;

  Dijkstra(const Graph &graph)
      : Search<Graph, State>(graph), dis(graph.size(), inf<Cost>()) {
    if (Restoration) {
      shortestPathTree = Tree<Edge>(graph.size());
    }
  }
};

template <typename Graph> Dijkstra<Graph> shortestPath(Graph &graph, int from) {
  Dijkstra<Graph> dijkstra(graph);
  dijkstra.solve(from);
  return dijkstra;
}

template <typename Graph>
typename Graph::EdgeType::CostType shortestPath(Graph &graph, int from,
                                                int to) {
  return shortestPath(graph, from).dis[to];
}

template <typename Graph>
Dijkstra<Graph, true> shortestPathTree(Graph &graph, int from) {
  Dijkstra<Graph, true> dijkstra(graph);
  dijkstra.solve(from);
  return dijkstra;
}

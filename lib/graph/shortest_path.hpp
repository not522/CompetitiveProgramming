#pragma once
#include "graph/search.hpp"
#include "graph/tree.hpp"

template<typename Edge> struct DijkstraState {
  typedef typename Edge::CostType Cost;

  Edge edge;
  Cost cost;

  DijkstraState(int pos) : edge(pos, pos), cost(0) {}

  DijkstraState(const Edge& edge, Cost cost) : edge(edge), cost(cost) {}

  DijkstraState next(const Edge& edge) const {return DijkstraState(edge, cost + edge.cost);}

  bool operator<(const DijkstraState& state) const {return cost > state.cost;}

  int getPos() const {return edge.to;}
};

template<typename Graph, bool Restoration = false, typename State = DijkstraState<typename Graph::EdgeType>> class Dijkstra : public Search<Graph, State> {
protected:
  typedef typename Graph::EdgeType Edge;
  typedef typename Edge::CostType Cost;

  constexpr static Cost INF = numeric_limits<Cost>::max();

  priority_queue<State> que;

  void push(const State& state) {
    que.push(state);
    dis[state.getPos()] = state.cost;
  }

  State next() {
    State now = que.top();
    que.pop();
    return now;
  }

  bool isRunning() {return !que.empty();}

  void visit(const State& state) {
    if (Restoration) {
      auto e = state.edge;
      if (e.from != e.to) {
        swap(e.from, e.to);
        shortestPathTree.addEdge(e);
      }
    }
  }

  bool canPruning(const State& state) {return dis[state.getPos()] <= state.cost;}

public:
  vector<Cost> dis;
  Tree<Edge> shortestPathTree;

  Dijkstra(const Graph& graph) : Search<Graph, State>(graph), dis(graph.size(), INF) {
    if (Restoration) shortestPathTree = Tree<Edge>(graph.size());
  }
};

template<typename Graph> inline Dijkstra<Graph> shortestPath(Graph& graph, int from) {
  Dijkstra<Graph> dijkstra(graph);
  dijkstra.solve(from);
  return dijkstra;
}

template<typename Graph> inline typename Graph::EdgeType::CostType shortestPath(Graph& graph, int from, int to) {
  return shortestPath(graph, from).dis[to];
}

template<typename Graph> inline Dijkstra<Graph, true> shortestPathTree(Graph& graph, int from) {
  Dijkstra<Graph, true> dijkstra(graph);
  dijkstra.solve(from);
  return dijkstra;
}

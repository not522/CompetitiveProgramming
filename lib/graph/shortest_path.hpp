#pragma once
#include "graph/search.hpp"

namespace dijkstra {
  template<typename Edge> struct DijkstraState {
    typedef typename Edge::CostType Cost;
  
    int pos;
    Cost cost;
  
    DijkstraState(int pos, Cost cost = 0) : pos(pos), cost(cost) {}
  
    DijkstraState next(const Edge& edge) const {
      return DijkstraState(edge.to, cost + edge.cost);
    }
  
    bool operator<(const DijkstraState& state) const {return cost > state.cost;}
  };
}

template<typename Graph> class Dijkstra : public Search<Graph, dijkstra::DijkstraState<typename Graph::EdgeType>> {
private:
  typedef typename Graph::EdgeType Edge;
  typedef typename Edge::CostType Cost;
  typedef dijkstra::DijkstraState<Edge> State;

protected:
  const Cost INF = numeric_limits<Cost>::max();

  priority_queue<State> que;

  void push(const State& state) {
    que.push(state);
    dis[state.pos] = state.cost;
  }
  
  State next() {
    State now = que.top();
    que.pop();
    return now;
  }
  
  bool isRunning() {
    return !que.empty();
  }
  
  bool canPruning(const State& state) {
    return dis[state.pos] <= state.cost;
  }

public:
  vector<Cost> dis;

  Dijkstra(Graph& graph) : Search<Graph, State>(graph), dis(graph.size(), INF) {}
};

template<typename Graph> inline Dijkstra<Graph> shortestPath(Graph& graph, int from) {
  Dijkstra<Graph> dijkstra(graph);
  dijkstra.solve(from);
  return dijkstra;
}

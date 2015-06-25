#pragma once
#include "graph/search.hpp"

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

template<typename Graph> class Dijkstra : public Search<Graph, DijkstraState<typename Graph::EdgeType>> {
private:
  typedef typename Graph::EdgeType Edge;
  typedef typename Edge::CostType Cost;
  typedef DijkstraState<Edge> State;

protected:
  const Cost INF;

  priority_queue<State> que;

  void push(const State& state) {
    que.push(state);
    dist[state.pos] = state.cost;
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
    return dist[state.pos] <= state.cost;
  }

public:
  vector<Cost> dist;

  Dijkstra(Graph& graph, int from) : Search<Graph, State>(graph), INF(numeric_limits<Cost>::max()), dist(graph.size(), INF) {
    this->solve(from);
  }
};

template<typename Graph> Dijkstra<Graph> inline dijkstra(Graph& graph, int from) {
  return Dijkstra<Graph>(graph, from);
}

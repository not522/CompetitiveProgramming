#pragma once
#include "graph/search.hpp"

template<typename Edge> struct DijkstraState {
  typedef typename Edge::CostType Cost;
  
  int pos;
  Cost cost;
  
  DijkstraState(int pos, Cost cost = 0) : pos(pos), cost(cost) {}
  
  DijkstraState next(const Edge& edge) {
    return DijkstraState(edge.to, cost + edge.cost);
  }
  
  bool operator<(const DijkstraState& state) const {return cost > state.cost;}
};

template<typename Edge> class Dijkstra : public Search<Edge, DijkstraState<Edge>> {
private:
  typedef typename Edge::CostType Cost;
  typedef DijkstraState<Edge> State;

  priority_queue<State> que;

protected:
  void push(const State& state) {
    que.push(state);
    dist[state.pos] = state.cost;
  }
  
  State next() {
    State now = que.top();
    que.pop();
    return now;
  }
  
  bool canPruning(const State& state) {
    return dist[state.pos] <= state.cost;
  }
  
  bool isRunning() {
    return !que.empty();
  }

public:
  const Cost INF;

  vector<Cost> dist;

  Dijkstra(int n) : Search<Edge, State>(n), INF(numeric_limits<Cost>::max()), dist(n, INF) {}
};

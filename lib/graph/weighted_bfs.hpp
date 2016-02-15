#pragma once
#include "graph/search.hpp"

template<typename Edge> struct WeightedBFSState {
  typedef typename Edge::CostType Cost;

  Edge edge;
  Cost cost;

  WeightedBFSState(int pos, int prv = -1) : edge(prv, pos), cost(0) {}

  WeightedBFSState(const Edge& edge, Cost cost) : edge(edge), cost(cost) {}

  WeightedBFSState next(const Edge& edge) const {
    return WeightedBFSState(edge, cost + edge.cost);
  }

  int getPos() {
    return edge.to;
  }
};

template<typename Graph, typename State = WeightedBFSState<typename Graph::EdgeType>> class WeightedBFS : public Search<Graph, State> {
protected:
  typedef typename Graph::EdgeType Edge;
  typedef typename Edge::CostType Cost;

private:
  Cost now;
  deque<queue<State>> que;
  
  void push(const State& state) {
    if (state.cost - now >= que.size()) que.resize(state.cost - now + 1);
    que[state.cost - now].push(state);
  }
  
  State next() {
    State now = que[0].front();
    que[0].pop();
    return now;
  }
  
  bool isRunning() {
    while (!que.empty() && que[0].empty()) {
      que.pop_front();
      ++now;
    }
    return !que.empty();
  }

public:
  WeightedBFS(const Graph& graph) : Search<Graph, State>(graph), now(0) {}
};

template<typename Graph> class WeightedBFSDistance : public WeightedBFS<Graph> {
private:
  typedef WeightedBFSState<typename Graph::EdgeType> State;

  void visit(const State& state) {
    if (state.edge.from != -1) dis[state.edge.to] = dis[state.edge.from] + state.edge.cost;
  }

public:
  vector<int> dis;

  WeightedBFSDistance(const Graph& graph) : WeightedBFS<Graph>(graph), dis(graph.size(), 0) {}
};

template<typename Graph> inline WeightedBFSDistance<Graph> weightedBFSDistance(const Graph& graph, int from) {
  WeightedBFSDistance<Graph> bfs(graph);
  bfs.solve(from);
  return bfs;
}

template<typename Graph> inline typename Graph::EdgeType::CostType weightedBFSDistance(Graph& graph, int from, int to) {
  return weightedBFSDistance(graph, from).dis[to];
}

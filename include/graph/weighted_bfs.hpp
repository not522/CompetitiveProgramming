#pragma once
#include "graph/search.hpp"

template <typename Edge> struct WeightedBFSState {
  using Cost = typename Edge::CostType;

  int from;
  Edge edge;
  Cost cost;

  WeightedBFSState(const int pos, const int prv = -1)
      : from(prv), edge(pos), cost(0) {}

  WeightedBFSState(const int from, const Edge &edge, const Cost cost)
      : from(from), edge(edge), cost(cost) {}

  WeightedBFSState next(const int from, const Edge &edge) const {
    return WeightedBFSState(from, edge, cost + edge.cost);
  }

  int getPos() { return edge.to; }
};

template <typename Graph,
          typename State = WeightedBFSState<typename Graph::EdgeType>>
class WeightedBFS : public Search<Graph, State> {
protected:
  using Edge = typename Graph::EdgeType;
  using Cost = typename Edge::CostType;

private:
  Cost now;
  Deque<Queue<State>> que;

  void push(const State &state) {
    if (state.cost - now >= que.size()) {
      que.resize(state.cost - now + 1);
    }
    que[state.cost - now].push(state);
  }

  State next() {
    State now = que[0].front();
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
  WeightedBFS(const Graph &graph) : Search<Graph, State>(graph), now(0) {}
};

template <typename Graph>
class WeightedBFSDistance : public WeightedBFS<Graph> {
private:
  using State = WeightedBFSState<typename Graph::EdgeType>;

  void visit(const State &state) {
    if (state.from != -1) {
      dis[state.edge.to] = dis[state.from] + state.edge.cost;
    }
  }

public:
  vector<int> dis;

  WeightedBFSDistance(const Graph &graph)
      : WeightedBFS<Graph>(graph), dis(graph.size(), 0) {}
};

template <typename Graph>
WeightedBFSDistance<Graph> weightedBFSDistance(const Graph &graph, int from) {
  WeightedBFSDistance<Graph> bfs(graph);
  bfs.solve(from);
  return bfs;
}

template <typename Graph>
typename Graph::EdgeType::CostType weightedBFSDistance(Graph &graph, int from,
                                                       int to) {
  return weightedBFSDistance(graph, from).dis[to];
}

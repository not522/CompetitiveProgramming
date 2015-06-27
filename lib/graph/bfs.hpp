#pragma once
#include "graph/search.hpp"

template<typename Edge> struct BFSState {
  int pos, prev;

  BFSState(int pos, int prev = -1) : pos(pos), prev(prev) {}
  
  BFSState next(const Edge& edge) const {
    return BFSState(edge.to, pos);
  }
};

template<typename Graph> class BFS : public Search<Graph, BFSState<typename Graph::EdgeType>> {
private:
  typedef typename Graph::EdgeType Edge;
  typedef BFSState<Edge> State;
  
protected:
  queue<State> que;
  
  void push(const State& state) {
    que.push(state);
  }
  
  State next() {
    State now = que.front();
    que.pop();
    return now;
  }
  
  bool isRunning() {
    return !que.empty();
  }

  void visit(const State& state) {
    if (state.prev != -1) dist[state.pos] = dist[state.prev] + 1;
  }

public:
  vector<int> dist;
  
  BFS(Graph& graph, int from) : Search<Graph, State>(graph), dist(graph.size(), 0) {
    this->solve(from);
  }
};

template<typename Graph> BFS<Graph> inline bfs(Graph& graph, int from) {
  return BFS<Graph>(graph, from);
}

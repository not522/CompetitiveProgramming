#pragma once
#include "template.hpp"

template<typename Graph, typename State> class Search {
protected:
  typedef typename Graph::EdgeType Edge;

  Graph& graph;
  vector<bool> visited;

  virtual void push(const State& state) = 0;
  virtual State next() = 0;
  virtual bool isRunning() = 0;

  virtual void visit(const State& state) {(void)state;}
  virtual bool canPruning(const State& state) {(void)state; return false;}

  void solve(int from) {
    push(State(from));
    while (isRunning()) {
      State now = next();
      if (visited[now.pos]) continue;
      visited[now.pos] = true;
      visit(now);
      for (const Edge& edge : graph[now.pos]) {
        State nextState = now.next(edge);
        if (visited[nextState.pos]) continue;
        if (canPruning(nextState)) continue;
        push(nextState);
      }
    }
  }
  
public:
  Search(Graph& graph) : graph(graph), visited(graph.size(), false) {}

  bool isReachable(int v) {
    return visited[v];
  }
};

#pragma once
#include "graph/adjacency_list.hpp"

template<typename Edge, typename State> class Search : public AdjacencyList<Edge> {
protected:
  vector<bool> visited;

  virtual void push(const State& state) = 0;
  virtual State next() = 0;
  virtual bool canPruning(const State& state) = 0;
  virtual bool isRunning() = 0;

  void visit(const State& state) {(void)state;}
  
public:
  Search(int n) : AdjacencyList<Edge>(n), visited(n, false) {}

  void solve(int from) {
    push(State(from));
    while (isRunning()) {
      State now = next();
      if (visited[now.pos]) continue;
      visited[now.pos] = true;
      visit(now);
      for (const Edge& edge : (*this)[now.pos]) {
        State nextState = now.next(edge);
        if (canPruning(nextState)) continue;
        push(nextState);
      }
    }
  }
};

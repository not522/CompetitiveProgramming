#pragma once
#include "vector.hpp"

template <typename Graph, typename State> class Search {
protected:
  using Edge = typename Graph::EdgeType;

  const Graph graph;
  Vector<bool> visited;

  virtual void push(const State &) = 0;

  virtual State next() = 0;

  virtual bool isRunning() = 0;

  virtual void visit(const State &) {}

public:
  Search(const Graph &graph) : graph(graph), visited(graph.size(), false) {}

  void solve(const Vector<int> &from) {
    for (int i : from) {
      push(State(i));
    }
    while (isRunning()) {
      State now = next();
      int pos = now.getPos();
      if (visited[pos]) {
        continue;
      }
      visited[pos] = true;
      visit(now);
      for (const Edge &edge : graph.getEdges(pos)) {
        State nextState = now.next(pos, edge);
        if (visited[nextState.getPos()]) {
          continue;
        }
        push(nextState);
      }
    }
  }

  void solve(int from) { solve(Vector<int>({from})); }

  bool isReachable(int v) { return visited[v]; }
};

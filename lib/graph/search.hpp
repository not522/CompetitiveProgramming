#pragma once
#include "template.hpp"

template<typename Graph, typename State> class Search {
protected:
  typedef typename Graph::EdgeType Edge;

  const Graph graph;
  vector<bool> visited;

  virtual void push(const State&) = 0;
  virtual State next() = 0;
  virtual bool isRunning() = 0;

  virtual void visit(const State&) {}
  virtual bool canPruning(const State&) {return false;}

public:
  Search(const Graph& graph) : graph(graph), visited(graph.size(), false) {}

  void solve(vector<int> from) {
    for (int i : from) push(State(i));
    while (isRunning()) {
      State now = next();
      int pos = now.getPos();
      if (visited[pos]) continue;
      visited[pos] = true;
      visit(now);
      for (const Edge& edge : graph.getEdges(pos)) {
        State nextState = now.next(edge);
        if (visited[nextState.getPos()]) continue;
        if (canPruning(nextState)) continue;
        push(nextState);
      }
    }
  }

  void solve(int from) {solve(vector<int>({from}));}

  bool isReachable(int v) {return visited[v];}
};

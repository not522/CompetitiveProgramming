#pragma once
#include "graph/search.hpp"

namespace bfs {
  template<typename Edge> struct BFSState {
    int pos, prv;

    BFSState(int pos, int prv = -1) : pos(pos), prv(prv) {}
  
    BFSState next(const Edge& edge) const {
      return BFSState(edge.to, pos);
    }
  };
}

template<typename Graph> class BFS : public Search<Graph, bfs::BFSState<typename Graph::EdgeType>> {
protected:
  typedef typename Graph::EdgeType Edge;
  typedef bfs::BFSState<Edge> State;

private:
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

public:
  BFS(const Graph& graph) : Search<Graph, State>(graph) {}
};

namespace bfs_distance {
  template<typename Graph> class BFSDistance : public BFS<Graph> {
  private:
    typedef typename BFS<Graph>::State State;

    void visit(const State& state) {
      if (state.prv != -1) dis[state.pos] = dis[state.prv] + 1;
    }

  public:
    vector<int> dis;

    BFSDistance(const Graph& graph) : BFS<Graph>(graph), dis(graph.size(), 0) {}
  };
}

template<typename Graph> inline bfs_distance::BFSDistance<Graph> bfsDistance(const Graph& graph, int from) {
  bfs_distance::BFSDistance<Graph> bfs(graph);
  bfs.solve(from);
  return bfs;
}

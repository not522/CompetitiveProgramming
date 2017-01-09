#pragma once
#include "graph/search.hpp"
#include "graph/tree.hpp"

template<typename Edge> struct BFSState {
  int pos, prv;

  BFSState(int pos, int prv = -1) : pos(pos), prv(prv) {}
  
  BFSState next(const Edge& edge) const {return BFSState(edge.to, pos);}

  int getPos() {return pos;}
};

template<typename Graph, typename State = BFSState<typename Graph::EdgeType>> class BFS : public Search<Graph, State> {
protected:
  using Edge = typename Graph::EdgeType;

  queue<State> que;
  
  void push(const State& state) {que.push(state);}
  
  State next() {
    State now = que.front();
    que.pop();
    return now;
  }
  
  bool isRunning() {return !que.empty();}

public:
  BFS(const Graph& graph) : Search<Graph, State>(graph) {}
};

template<typename Graph, bool Restoration = false> class BFSDistance : public BFS<Graph> {
private:
  using Edge = typename Graph::EdgeType;
  using State = BFSState<typename Graph::EdgeType>;

  void visit(const State& state) {
    if (state.prv != -1) {
      if (Restoration) shortestPathTree.addEdge(state.pos, state.prv);
      dis[state.pos] = dis[state.prv] + 1;
    }
  }

public:
  vector<int> dis;
  Tree<Edge> shortestPathTree;

  BFSDistance(const Graph& graph) : BFS<Graph>(graph), dis(graph.size(), 0) {
    if (Restoration) shortestPathTree = Tree<Edge>(graph.size());
  }
};

template<typename Graph> BFSDistance<Graph> bfsDistance(const Graph& graph, int from) {
  BFSDistance<Graph> bfs(graph);
  bfs.solve(from);
  return bfs;
}

template<typename Graph> typename Graph::EdgeType::CostType bfsDistance(const Graph& graph, int from, int to) {
  return bfsDistance(graph, from).dis[to];
}

template<typename Graph> BFSDistance<Graph, true> bfsDistanceTree(const Graph& graph, int from) {
  BFSDistance<Graph, true> bfs(graph);
  bfs.solve(from);
  return bfs;
}

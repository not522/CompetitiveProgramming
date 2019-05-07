#pragma once
#include "graph/search.hpp"
#include "graph/tree.hpp"
#include "stack.hpp"

template <typename Edge> struct DFSState {
  int from;
  Edge edge;

  DFSState(const int pos) : from(pos), edge(pos) {}

  DFSState(const int from, const Edge &edge) : from(from), edge(edge) {}

  DFSState next(const int from, const Edge &edge) const {
    return DFSState(from, edge);
  }

  int getPos() { return edge.to; }
};

template <typename Graph, typename State = DFSState<typename Graph::EdgeType>>
class DFS : public Search<Graph, State> {
protected:
  using Edge = typename Graph::EdgeType;
  using StateType = State;

private:
  Stack<State> st;

  void push(const State &state) { st.push(state); }

  State next() {
    State now = st.top();
    return now;
  }

  bool isRunning() { return !st.empty(); }

public:
  DFS(const Graph &graph) : Search<Graph, State>(graph) {}
};

template <typename Graph> class DFSTree : public DFS<Graph> {
private:
  using Edge = typename Graph::EdgeType;
  using State = typename DFS<Graph>::StateType;

  void visit(const State &state) {
    int from = state.from, to = state.edge.to;
    if (from == -1) {
      return;
    }
    Edge edge = state.edge;
    edge.to = from;
    tree.addEdge(to, edge);
  }

public:
  Tree<Edge> tree;

  DFSTree(const Graph &graph) : DFS<Graph>(graph), tree(graph.size()) {}
};

template <typename Graph>
Tree<typename Graph::EdgeType> dfsTree(const Graph &graph, int root) {
  DFSTree<Graph> dfs(graph);
  dfs.solve(root);
  return dfs.tree;
}

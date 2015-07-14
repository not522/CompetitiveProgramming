#pragma once
#include "graph/tree.hpp"
#include "graph/search.hpp"

template<typename Edge> struct DFSState {

  Edge edge;

  DFSState(int pos) : edge(pos, pos) {}

  DFSState(const Edge& edge) : edge(edge) {}

  DFSState next(const Edge& edge) const {
    return DFSState(edge);
  }

  int getPos() {
    return edge.to;
  }
};

template<typename Graph, typename State = DFSState<typename Graph::EdgeType>> class DFS : public Search<Graph, State> {
protected:
  typedef typename Graph::EdgeType Edge;

private:
  stack<State> st;
  
  void push(const State& state) {
    st.push(state);
  }
  
  State next() {
    State now = st.top();
    st.pop();
    return now;
  }
  
  bool isRunning() {
    return !st.empty();
  }

public:
  DFS(const Graph& graph) : Search<Graph, State>(graph) {}
};

namespace dfs_tree {
  template<typename Graph> class DFSTree : public DFS<Graph> {
  private:
    typedef typename Graph::EdgeType Edge;
    typedef typename DFS<Graph>::State State;

    void visit(const State& state) {
      Edge edge = state.edge;
      if (edge.from != -1) {
        swap(edge.from, edge.to);
        tree.addEdge(edge);
      }
    }

  public:
    Tree<Edge> tree;

    DFSTree(const Graph& graph) : DFS<Graph>(graph), tree(graph.size()) {}
  };
}

template<typename Graph> inline Tree<typename Graph::EdgeType> dfsTree(const Graph& graph, int root) {
  dfs_tree::DFSTree<Graph> dfs(graph);
  dfs.solve(root);
  return dfs.tree;
}

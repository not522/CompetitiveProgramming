#include "graph/adjacency_list.hpp"
#include "graph/bfs.hpp"
#include "graph/minimum_spanning_tree.hpp"
#include "queue.hpp"

using LabeledGraph = AdjacencyList<LabeledEdge<int>>;

template <typename Edge> struct State {
  int pos, prv;
  Edge edge;

  State(const int pos, const int prv = -1, const Edge &edge = -1)
      : pos(pos), prv(prv), edge(edge) {}

  State next(const int pos, const Edge &edge) const {
    return State(edge.to, pos, edge);
  }

  int getPos() { return pos; }
};

class Coloring
    : public BFS<LabeledGraph, State<typename LabeledGraph::EdgeType>> {
private:
  using Edge = typename LabeledGraph::EdgeType;

  void visit(const State<Edge> &state) {
    if (state.prv != -1) {
      if (d[state.prv] == state.edge.label) {
        d[state.pos] = state.edge.label % graph.size() + 1;
      } else {
        d[state.pos] = state.edge.label;
      }
    }
  }

public:
  Vector<int> d;

  Coloring(const LabeledGraph &graph, int v, int k)
      : BFS<LabeledGraph, State<Edge>>(graph), d(graph.size(), -1) {
    d[v] = k % graph.size() + 1;
  }
};

int main() {
  LabeledGraph graph(in);
  auto tree = minimumSpanningTree(graph).toGraph();
  Queue<int> que;
  Vector<int> d(graph.size(), -1);
  for (int i = 0; i < graph.size(); ++i) {
    if (tree[i].size() == 1) {
      Coloring coloring(tree, i, tree[i][0].label);
      coloring.solve(i);
      for (int i = 0; i < graph.size(); ++i) {
        cout << coloring.d[i] << endl;
      }
      return 0;
    }
  }
}

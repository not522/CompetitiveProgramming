#include "graph/edge.hpp"
#include "graph/adjacency_list.hpp"
#include "graph/shortest_path.hpp"

using MyGraph = AdjacencyList<Edge>;

struct LexicalTreeState : public DijkstraState<Edge> {
  LexicalTreeState(const DijkstraState<Edge>& state) : DijkstraState<Edge>(state) {}
  
  bool operator<(const DijkstraState& state) const {
    return edge.to > state.edge.to;
  }
};

class LexicalTree : public Dijkstra<MyGraph, false, LexicalTreeState> {
private:
  void visit(const LexicalTreeState& state) {
    if (state.from != state.edge.to) cout << " ";
    cout << state.edge.to + 1;
  }

public:
  LexicalTree(const MyGraph& graph) : Dijkstra(graph) {}
};

int main() {
  int n;
  cin >> n;
  MyGraph graph(n);
  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    cin >> a >> b;
    graph.addUndirectedEdge(a - 1, b - 1);
  }
  LexicalTree lexicalTree(graph);
  lexicalTree.solve(0);
  cout << endl;
}

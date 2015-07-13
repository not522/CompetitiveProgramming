#include "graph/adjacency_matrix.hpp"
#include "graph/clique.hpp"

struct Edge {int from, to;};

int main() {
  int n, m;
  cin >> n >> m;
  AdjacencyMatrix<Edge> graph(n);
  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    --x; --y;
    graph.addUndirectedEdge((Edge){x, y});
  }
  Clique<AdjacencyMatrix, Edge> clique(graph);
  cout << clique.maximum().size() << endl;
}

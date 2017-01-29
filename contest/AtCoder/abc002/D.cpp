#include "graph/adjacency_matrix.hpp"
#include "graph/clique.hpp"
#include "graph/edge.hpp"

int main() {
  int n, m;
  cin >> n >> m;
  AdjacencyMatrix<Edge> graph(n);
  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    --x; --y;
    graph.addUndirectedEdge(x, y);
  }
  Clique<AdjacencyMatrix, Edge> clique(graph);
  cout << clique.maximum().size() << endl;
}

#include "graph/edge.hpp"
#include "graph/adjacency_matrix.hpp"
#include "graph/count_walk.hpp"

int main() {
  int n, m;
  cin >> n >> m;
  AdjacencyMatrix<Edge> graph(n);
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    graph.addUndirectedEdge(a - 1, b - 1);
  }
  auto mat = countWalk(graph, 2);
  for (int i = 0; i < n; ++i) {
    int c = 0;
    for (int j = 0; j < n; ++j) {
      if (i != j && graph.getEdges(i, j).empty() && mat[i][j]) ++c;
    }
    cout << c << endl;
  }
}

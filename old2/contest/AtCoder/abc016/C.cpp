#include "graph/adjacency_matrix.hpp"
#include "graph/count_walk.hpp"

int main() {
  int n(in), m(in);
  AdjacencyMatrix<Edge> graph(in, n, m);
  auto mat = countWalk(graph, 2);
  for (int i = 0; i < n; ++i) {
    int c = 0;
    for (int j = 0; j < n; ++j) {
      if (i != j && graph.getEdge(i, j).isNone() && mat[i][j]) {
        ++c;
      }
    }
    cout << c << endl;
  }
}

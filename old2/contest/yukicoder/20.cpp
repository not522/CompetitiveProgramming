#include "graph/adjacency_list.hpp"
#include "graph/shortest_path.hpp"
#include "vector.hpp"

int main() {
  setBoolName("YES", "NO");
  int n(in), v(in), x(in), y(in);
  --x, --y;
  auto l = Vector<int>::makeVector(in, n, n);
  AdjacencyList<WeightedEdge<int>> graph(n * n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i != n - 1) {
        graph.addEdge(i * n + j, i * n + j + n, l[i + 1][j]);
        graph.addEdge(i * n + j + n, i * n + j, l[i][j]);
      }
      if (j != n - 1) {
        graph.addEdge(i * n + j, i * n + j + 1, l[i][j + 1]);
        graph.addEdge(i * n + j + 1, i * n + j, l[i][j]);
      }
    }
  }
  if (shortestPath(graph, 0, n * n - 1) < v) {
    cout << true << endl;
  } else if (x == -1 && y == -1) {
    cout << false << endl;
  } else {
    cout << ((v - shortestPath(graph, 0, y * n + x)) * 2 >
             shortestPath(graph, y * n + x, n * n - 1))
         << endl;
  }
}

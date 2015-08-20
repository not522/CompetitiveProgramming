#include "graph/edge.hpp"
#include "graph/adjacency_list.hpp"
#include "graph/shortest_path.hpp"

int main() {
  int n, v, x, y;
  cin >> n >> v >> x >> y;
  --x, --y;
  vector<vector<int>> l(n, vector<int>(n));
  for (auto& i : l) {
    for (int& j : i) cin >> j;
  }
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
    cout << "YES" << endl;
    return 0;
  }
  if (x == -1 && y == -1) {
    cout << "NO" << endl;
    return 0;
  }
  int d1 = shortestPath(graph, 0, y * n + x);
  int d2 = shortestPath(graph, y * n + x, n * n - 1);
  cout << ((v - d1) * 2 > d2 ? "YES" : "NO") << endl;
}
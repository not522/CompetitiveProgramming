#include "graph/bipartite_matching.hpp"

int main() {
  int n;
  cin >> n;
  vector<int> a(n), b(n), c(n), d(n);
  for (int i = 0; i < n; ++i) cin >> a[i] >> b[i];
  for (int i = 0; i < n; ++i) cin >> c[i] >> d[i];
  AdjacencyList<Edge> graph(2 * n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (a[i] < c[j] && b[i] < d[j]) graph.addUndirectedEdge(i, j + n);
    }
  }
  cout << bipartite_matching(graph) << endl;
}

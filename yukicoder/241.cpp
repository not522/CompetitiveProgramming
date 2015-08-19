#include "graph/bipartite_matching.hpp"

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int& i : a) cin >> i;
  AdjacencyList<Edge> graph(2 * n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (a[i] == j) continue;
      graph.addEdge(i, j + n);
    }
  }
  BipartiteMatching match(graph);
  if (match.solve() != n) {
    cout << -1 << endl;
  } else {
    for (int i = 0; i < n; ++i) cout << match.match[i] - n << endl;
  }
}

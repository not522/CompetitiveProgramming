#include "graph/bipartite_matching.hpp"

int main() {
  int t, n, m;
  cin >> t >> n;
  vector<int> a(n);
  for (auto& i : a) cin >> i;
  cin >> m;
  vector<int> b(m);
  for (auto& i : b) cin >> i;
  AdjacencyList<Edge> graph(n + m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (a[i] > b[j]) continue;
      if (a[i] + t < b[j]) continue;
      graph.addEdge(i, j + n);
    }
  }
  BipartiteMatching matching(graph);
  cout << (matching.solve() == m ? "yes" : "no") << endl;
}

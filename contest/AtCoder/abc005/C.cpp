#include "graph/bipartite_matching.hpp"

int main() {
  set_bool_name("yes", "no");
  int t(in), n(in);
  Vector<int> a(n, in);
  int m(in);
  Vector<int> b(m, in);
  AdjacencyList<Edge> graph(n + m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (a[i] <= b[j] && b[j] <= a[i] + t) {
        graph.addEdge(i, j + n);
      }
    }
  }
  cout << (bipartiteMatching(graph) == m) << endl;
}

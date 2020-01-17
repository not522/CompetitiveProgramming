#include "graph/max_flow.hpp"
#include "unordered_set.hpp"

int main() {
  setBoolName("SHIROBAKO", "BANSAKUTSUKITA");
  int w(in), n(in);
  ResidualGraph<ResidualEdge<int>> graph(w + n + 2);
  int id = 0;
  int source = id++;
  int sink = id++;
  Vector<int> a(n);
  for (int &i : a) {
    i = id++;
  }
  for (int i = 0; i < n; ++i) {
    int j(in);
    graph.addEdge(source, a[i], j);
  }
  int m(in);
  Vector<int> b(m);
  for (int &i : b) {
    i = id++;
  }
  for (int i = 0; i < m; ++i) {
    int c(in);
    graph.addEdge(b[i], sink, c);
  }
  for (int i = 0; i < m; ++i) {
    int q(in);
    UnorderedSet<int> x;
    for (int j = 0; j < q; ++j) {
      int k(in);
      x.insert(k - 1);
    }
    for (int j = 0; j < n; ++j) {
      if (x.count(j)) {
        continue;
      }
      graph.addEdge(a[j], b[i], w);
    }
  }
  MaxFlow<int> mf(graph);
  cout << (mf.solve(source, sink) >= w) << endl;
}

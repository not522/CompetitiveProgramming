#include "graph/edge.hpp"
#include "graph/max_flow.hpp"

int main() {
  int w, n;
  cin >> w >> n;
  ResidualGraph<ResidualEdge<int>> graph(w + n + 2);
  int id = 0;
  int source = id++;
  int sink = id++;
  vector<int> a(n);
  for (int& i : a) i = id++;
  for (int i = 0; i < n; ++i) {
    int j;
    cin >> j;
    graph.addEdge(source, a[i], j);
  }
  int m;
  cin >> m;
  vector<int> b(m);
  for (int& i : b) i = id++;
  for (int i = 0; i < m; ++i) {
    int c;
    cin >> c;
    graph.addEdge(b[i], sink, c);
  }
  for (int i = 0; i < m; ++i) {
    int q;
    cin >> q;
    unordered_set<int> x;
    for (int j = 0; j < q; ++j) {
      int k;
      cin >> k;
      x.insert(k - 1);
    }
    for (int j = 0; j < n; ++j) {
      if (x.count(j)) continue;
      graph.addEdge(a[j], b[i], w);
    }
  }
  MaxFlow mf;
  cout << (mf.solve(graph, source, sink) >= w ? "SHIROBAKO" : "BANSAKUTSUKITA") << endl;
}

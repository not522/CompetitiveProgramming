#include "graph/adjacency_list.hpp"
#include "graph/topological_sort.hpp"

int main() {
  int n, m;
  cin >> n >> m;
  AdjacencyList<Edge> graph1(n), graph2(n);
  for (int i = 0; i < n - 1 + m; ++i) {
    int a, b;
    cin >> a >> b;
    graph1.addEdge(a - 1, b - 1);
    graph2.addEdge(b - 1, a - 1);
  }
  auto sorted = topological_sort(graph1);
  vector<int> order(n);
  for (int i = 0; i < n; ++i) order[sorted[i]] = i;
  vector<int> p(n);
  for (int v = 0; v < n; ++v) {
    int q = -1;
    for (int u : graph2[v]) {
      if (order[u] < order[v] && (q == -1 || order[q] < order[u])) q = u;
    }
    p[v] = q + 1;
  }
  cout << p;
}

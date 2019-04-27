#include "graph/adjacency_list.hpp"
#include "graph/bellman_ford.hpp"

int main() {
  int n, m;
  cin >> n >> m;
  AdjacencyList<WeightedEdge<int64_t>> graph(n);
  for (int i = 0; i < m; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    graph[a - 1].emplace_back(b - 1, -c);
  }
  auto res = bellman_ford(graph, 0, n - 1);
  if (res == numeric_limits<int64_t>::min()) cout << "inf" << endl;
  else cout << -res << endl;
}

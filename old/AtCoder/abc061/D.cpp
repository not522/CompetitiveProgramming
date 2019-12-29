#include "graph/adjacency_list.hpp"
#include "graph/bellman_ford.hpp"

int main() {
  int n(in), m(in);
  AdjacencyList<WeightedEdge<int64_t>> graph(n);
  for (int i = 0; i < m; ++i) {
    int a(in), b(in), c(in);
    graph[a - 1].emplace_back(b - 1, -c);
  }
  auto res = bellman_ford(graph, 0, n - 1);
  if (res == -inf<int64_t>()) {
    cout << "inf" << endl;
  } else {
    cout << -res << endl;
  }
}

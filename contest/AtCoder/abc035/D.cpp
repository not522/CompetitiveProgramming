#include "graph/adjacency_list.hpp"
#include "graph/shortest_path.hpp"

int main() {
  int n(in), m(in), t(in);
  Vector<int> a(n, in);
  AdjacencyList<WeightedEdge<int64_t>> graph1(n), graph2(n);
  for (int i = 0; i < m; ++i) {
    int a(in), b(in), c(in);
    graph1.addEdge(a - 1, b - 1, c);
    graph2.addEdge(b - 1, a - 1, c);
  }
  auto dijkstra1 = shortestPath(graph1, 0);
  auto dijkstra2 = shortestPath(graph2, 0);
  int64_t res = 0;
  for (int i = 0; i < n; ++i) {
    if (dijkstra1.isReachable(i) && dijkstra2.isReachable(i)) {
      chmax(res, a[i] * (t - dijkstra1.dis[i] - dijkstra2.dis[i]));
    }
  }
  cout << res << endl;
}

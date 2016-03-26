#include "minmax.hpp"
#include "vector.hpp"
#include "graph/adjacency_list.hpp"
#include "graph/edge.hpp"
#include "graph/shortest_path.hpp"

int main() {
  int n, m, t;
  cin >> n >> m >> t;
  vector<int> a(n);
  cin >> a;
  AdjacencyList<WeightedEdge<long long>> graph1(n), graph2(n);
  for (int i = 0; i < m; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    graph1.addEdge(a - 1, b - 1, c);
    graph2.addEdge(b - 1, a - 1, c);
  }
  auto dijkstra1 = shortestPath(graph1, 0);
  auto dijkstra2 = shortestPath(graph2, 0);
  long long res = 0;
  for (int i = 0; i < n; ++i) {
    if (!dijkstra1.isReachable(i) || !dijkstra2.isReachable(i)) continue;
    chmax(res, a[i] * (t - dijkstra1.dis[i] - dijkstra2.dis[i]));
  }
  cout << res << endl;
}

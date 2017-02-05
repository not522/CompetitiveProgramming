#include "minmax.hpp"
#include "vector.hpp"
#include "graph/edge.hpp"
#include "graph/adjacency_list.hpp"
#include "graph/shortest_path.hpp"

int main() {
  int n;
  cin >> n;
  vector<double> x(n), y(n), t(n), r(n);
  for (int i = 0; i < n; ++i) cin >> x[i] >> y[i] >> t[i] >> r[i];
  AdjacencyList<WeightedEdge<double>> graph(n);
  for (int i = 0; i < n; ++i) {
    for (int j = 1; j < n; ++j) {
      graph.addEdge(i, j, hypot(x[i] - x[j], y[i] - y[j]) / min(t[i], r[j]));
    }
  }
  auto dis = shortestPath(graph, 0).dis;
  rsort(dis);
  double res = 0;
  for (int i = 0; i < n - 1; ++i) chmax(res, dis[i] + i);
  cout << res << endl;
}

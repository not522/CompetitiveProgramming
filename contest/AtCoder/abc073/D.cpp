#include "permutation.hpp"
#include "graph/adjacency_list.hpp"
#include "graph/all_pairs_shortest_path.hpp"

int main() {
  int n, m, r;
  cin >> n >> m >> r;
  vector<int> t(r);
  cin >> t;
  AdjacencyList<WeightedEdge<int>> graph(n);
  for (int i = 0; i < m; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    graph.addUndirectedEdge(a - 1, b - 1, c);
  }
  auto cost = shortestPath(graph);
  int res = numeric_limits<int>::max();
  for (const auto& p : Permutation(r)) {
    int k = 0;
    for (int i = 0; i < r - 1; ++i) k += cost[t[p[i]] - 1][t[p[i + 1]] - 1];
    chmin(res, k);
  }
  cout << res << endl;
}

#include "graph/adjacency_list.hpp"
#include "graph/all_pairs_shortest_path.hpp"
#include "permutation.hpp"

int main() {
  int n(in), m(in), r(in);
  Vector<int> t(r, in);
  AdjacencyList<WeightedEdge<int>> graph(in, n, m);
  auto cost = shortestPath(graph);
  int res = inf<int>();
  for (const auto &p : Permutation(r)) {
    int k = 0;
    for (int i = 0; i < r - 1; ++i) {
      k += cost[t[p[i]] - 1][t[p[i + 1]] - 1];
    }
    chmin(res, k);
  }
  cout << res << endl;
}

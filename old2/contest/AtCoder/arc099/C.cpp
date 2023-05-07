#include "container/bitset.hpp"
#include "container/union_find.hpp"
#include "graph/adjacency_list.hpp"
#include "graph/bipartite.hpp"
#include "graph/complement.hpp"

int main() {
  int n(in), m(in);
  AdjacencyList<Edge> graph(in, n, m);
  graph = complement(graph);
  auto color = bipartiteColor(graph);
  if (color.empty()) {
    cout << -1 << endl;
    return 0;
  }
  UnionFind uf(n);
  for (int v = 0; v < n; ++v) {
    for (const auto &edge : graph[v]) {
      uf.unite(v, edge.to);
    }
  }
  Bitset dp;
  dp[0] = 1;
  for (const auto &group : uf.groups()) {
    int a = 0, b = 0;
    for (int v : group) {
      if (color[v]) {
        ++a;
      } else {
        ++b;
      }
    }
    dp = (dp << a) | (dp << b);
  }
  int res = inf<int>();
  for (auto i : dp) {
    chmin(res, i * (i - 1) / 2 + (n - i) * (n - i - 1) / 2);
  }
  cout << res << endl;
}

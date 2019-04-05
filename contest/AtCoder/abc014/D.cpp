#include "graph/adjacency_list.hpp"
#include "graph/dfs.hpp"
#include "graph/lowest_common_ancestor.hpp"

int main() {
  int n(in);
  AdjacencyList<Edge> graph(in, n, n - 1);
  LowerCommonAncestor<Edge> lca(dfsTree(graph, 0));
  int q(in);
  for (int i = 0; i < q; ++i) {
    int a(in), b(in);
    --a, --b;
    int c = lca.solve(a, b);
    cout << lca.getDepth(a) + lca.getDepth(b) - 2 * lca.getDepth(c) + 1 << endl;
  }
}

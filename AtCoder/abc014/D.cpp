#include "graph/edge.hpp"
#include "graph/dfs.hpp"
#include "graph/adjacency_list.hpp"
#include "graph/lower_common_ancestor.hpp"

int main() {
  int n;
  cin >> n;
  AdjacencyList<Edge> graph(n);
  for (int i = 0; i < n - 1; ++i) {
    int x, y;
    cin >> x >> y;
    graph.addUndirectedEdge(x - 1, y - 1);
  }
  LowerCommonAncestor<Edge> lca(dfsTree(graph, 0));
  int q;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    int c = lca.solve(a, b);
    cout << lca.calcDepth(a) + lca.calcDepth(b) - 2 * lca.calcDepth(c) + 1 << endl;
  }
}

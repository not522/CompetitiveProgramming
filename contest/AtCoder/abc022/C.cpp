#include "graph/edge.hpp"
#include "graph/adjacency_list.hpp"
#include "graph/shortest_path.hpp"
#include "graph/lower_common_ancestor.hpp"

int main() {
  int n, m;
  cin >> n >> m;
  AdjacencyList<WeightedEdge<int>> graph(n);
  for (int i = 0; i < m; ++i) {
    int u, v, l;
    cin >> u >> v >> l;
    graph.addUndirectedEdge(u - 1, v - 1, l);
  }
  auto info = shortestPathTree(graph, 0);
  LowerCommonAncestor<WeightedEdge<int>> lca(info.shortestPathTree);
  const int INF = numeric_limits<int>::max();
  int res = INF;
  for (const auto& edge : graph.getAllEdges()) {
    if (!info.isReachable(edge.from) || !info.isReachable(edge.to)) continue;
    if (info.shortestPathTree.parent[edge.from].to == edge.to) continue;
    if (info.shortestPathTree.parent[edge.to].to == edge.from) continue;
    if (lca.solve(edge.from, edge.to) != 0) continue;
    res = min(res, info.dis[edge.from] + info.dis[edge.to] + edge.cost);
  }
  cout << (res != INF ? res : -1) << endl;
}

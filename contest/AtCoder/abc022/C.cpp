#include "graph/adjacency_list.hpp"
#include "graph/lowest_common_ancestor.hpp"
#include "graph/shortest_path.hpp"

int main() {
  int n(in), m(in);
  AdjacencyList<WeightedEdge<int>> graph(in, n, m);
  auto info = shortestPathTree(graph, 0);
  LowerCommonAncestor<WeightedEdge<int>> lca(info.shortestPathTree);
  int res = inf<int>();
  for (const auto &edge : graph.getAllEdges()) {
    if (!info.isReachable(edge.from) || !info.isReachable(edge.to)) {
      continue;
    }
    if (info.shortestPathTree.parent[edge.from].to == edge.to) {
      continue;
    }
    if (info.shortestPathTree.parent[edge.to].to == edge.from) {
      continue;
    }
    if (lca.solve(edge.from, edge.to) != 0) {
      continue;
    }
    chmin(res, info.dis[edge.from] + info.dis[edge.to] + edge.cost);
  }
  cout << (res != inf<int>() ? res : -1) << endl;
}

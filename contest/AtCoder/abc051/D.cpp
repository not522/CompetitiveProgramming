#include "graph/adjacency_list.hpp"
#include "graph/all_pairs_shortest_path.hpp"
#include "graph/edge.hpp"

int main() {
  using Graph = AdjacencyList<WeightedEdge<int>>;
  int n, m, res = 0;
  cin >> n >> m;
  Graph graph(n);
  for (int i = 0; i < m; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    graph.addUndirectedEdge(a - 1, b - 1, c);
  }
  const auto& dis = shortestPath(graph);
  for (const auto& edge : graph.getAllEdges()) {
    if (dis[edge.from][edge.to] < edge.cost) ++res;
  }
  cout << res / 2 << endl;
}

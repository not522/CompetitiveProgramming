#include "graph/adjacency_list.hpp"
#include "graph/all_pairs_shortest_path.hpp"
#include "graph/edge.hpp"

int main() {
  int n, m;
  cin >> n >> m;
  AdjacencyList<WeightedEdge<int>> graph(n);
  for (int i = 0; i < m; ++i) {
    int a, b, t;
    cin >> a >> b >> t;
    --a; --b;
    graph.addUndirectedEdge(a, b, t);
  }
  auto info = shortestPath(graph);
  int res = numeric_limits<int>::max();
  for (const auto& d : info.dis) res = min(res, *max_element(d.begin(), d.end()));
  cout << res << endl;
}

#include "graph/adjacency_list.hpp"
#include "graph/shortest_path.hpp"

int main() {
  int n;
  cin >> n;
  AdjacencyList<WeightedEdge<int64_t>> graph(n);
  for (int i = 0; i < n - 1; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    graph.addUndirectedEdge(a - 1, b - 1, c);
  }
  int q, k;
  cin >> q >> k;
  auto dis = shortestPath(graph, k - 1).dis;
  for (int i = 0; i < q; ++i) {
    int x, y;
    cin >> x >> y;
    cout << dis[x - 1] + dis[y - 1] << endl;
  }
}

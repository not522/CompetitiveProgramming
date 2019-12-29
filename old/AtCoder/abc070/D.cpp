#include "graph/adjacency_list.hpp"
#include "graph/shortest_path.hpp"

int main() {
  int n(in);
  AdjacencyList<WeightedEdge<int64_t>> graph(in, n, n - 1);
  int q(in), k(in);
  auto dis = shortestPath(graph, k - 1).dis;
  for (int i = 0; i < q; ++i) {
    int x(in), y(in);
    cout << dis[x - 1] + dis[y - 1] << endl;
  }
}

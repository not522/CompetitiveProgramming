#include "bit_operation.hpp"
#include "graph/edge.hpp"
#include "graph/adjacency_list.hpp"
#include "graph/bfs.hpp"

int main() {
  using Graph = AdjacencyList<Edge>;
  int n;
  cin >> n;
  Graph graph(n);
  for (int i = 0; i < n; ++i) {
    int c = count_bit(i + 1);
    if (i + c < n) graph.addEdge(i, i + c);
    if (i - c >= 0) graph.addEdge(i, i - c);
  }
  auto info = bfsDistance(graph, 0);
  cout << (info.isReachable(n - 1) ? info.dis[n - 1] + 1 : -1) << endl;
}

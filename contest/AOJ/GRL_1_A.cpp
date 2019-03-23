#include "graph/adjacency_list.hpp"
#include "graph/edge.hpp"
#include "graph/shortest_path.hpp"

int main() {
  int v(in), e(in), r(in);
  AdjacencyList<WeightedEdge<int>> graph(in, v, e, false, false);
  auto info = shortestPath(graph, r);
  for (int i = 0; i < v; ++i) {
    if (info.isReachable(i)) {
      cout << info.dis[i] << endl;
    } else {
      cout << "INF" << endl;
    }
  }
}

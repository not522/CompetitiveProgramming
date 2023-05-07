#include "graph/adjacency_list.hpp"
#include "graph/all_pairs_shortest_path.hpp"

int main() {
  int res = 0;
  AdjacencyList<WeightedEdge<int>> graph(in);
  const auto dis = shortestPath(graph);
  for (const auto &edge : graph.getAllEdges()) {
    if (dis[edge.from][edge.to] < edge.cost) {
      ++res;
    }
  }
  cout << res / 2 << endl;
}

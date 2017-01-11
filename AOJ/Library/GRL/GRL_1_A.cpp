#include "graph/edge.hpp"
#include "graph/adjacency_list.hpp"
#include "graph/shortest_path.hpp"

int main() {
  int v, e, r;
  cin >> v >> e >> r;
  AdjacencyList<WeightedEdge<int>> graph(v);
  for (int i = 0; i < e; ++i) {
    int s, t, d;
    cin >> s >> t >> d;
    graph.addEdge(s, t, d);
  }
  auto info = shortestPath(graph, r);
  for (int i = 0; i < v; ++i) {
    if (info.isReachable(i)) cout << info.dis[i] << endl;
    else cout << "INF" << endl;
  }
}

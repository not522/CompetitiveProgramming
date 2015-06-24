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
    graph.addEdge(WeightedEdge<int>(s, t, d));
  }
  ShortestPath<AdjacencyList, WeightedEdge<int>> shortestPath(graph);
  shortestPath.solve(r);
  for (int c : shortestPath.dist) {
    if (c != shortestPath.INF) cout << c << endl;
    else cout << "INF" << endl;
  }
}

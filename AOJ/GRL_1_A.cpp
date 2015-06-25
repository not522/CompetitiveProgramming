#include "graph/edge.hpp"
#include "graph/dijkstra.hpp"

int main() {
  int v, e, r;
  cin >> v >> e >> r;
  Dijkstra<WeightedEdge<int>> graph(v);
  for (int i = 0; i < e; ++i) {
    int s, t, d;
    cin >> s >> t >> d;
    graph.addEdge(WeightedEdge<int>(s, t, d));
  }
  graph.solve(r);
  for (int c : graph.dist) {
    if (c != graph.INF) cout << c << endl;
    else cout << "INF" << endl;
  }
}

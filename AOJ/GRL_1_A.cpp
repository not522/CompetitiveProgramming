#include "adjacency_list.hpp"
#include "shortest_path.hpp"

struct Edge {
  int from, to, cost;
};

int main() {
  int v, e, r;
  cin >> v >> e >> r;
  AdjacencyList<Edge> graph(v);
  for (int i = 0; i < e; ++i) {
    int s, t, d;
    cin >> s >> t >> d;
    graph.addEdge((Edge){s, t, d});
  }
  ShortestPath<AdjacencyList, Edge> shortestPath(graph);
  shortestPath.run(r);
  for (int c : shortestPath.dist) {
    if (c != shortestPath.INF) cout << c << endl;
    else cout << "INF" << endl;
  }
}

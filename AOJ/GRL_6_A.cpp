#include "graph/max_flow.hpp"

int main() {
  int v, e;
  cin >> v >> e;
  ResidualGraph<ResidualEdge<int>> graph(v);
  for (int i = 0; i < e; ++i) {
    int u, v, c;
    cin >> u >> v >> c;
    graph.addEdge(u, v, c);
  }
  MaxFlow maxFlow;
  cout << maxFlow.solve(graph, 0, v - 1) << endl;
}

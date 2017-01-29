#include "graph/max_flow.hpp"

int main() {
  int n, g, e;
  cin >> n >> g >> e;
  int id = 0;
  int sink = id++;
  vector<int> v(n);
  for (int& i : v) i = id++;
  ResidualGraph<ResidualEdge<int>> graph(id);
  for (int i = 0; i < g; ++i) {
    int p;
    cin >> p;
    graph.addEdge(v[p], sink, 1);
  }
  for (int i = 0; i < e; ++i) {
    int a, b;
    cin >> a >> b;
    graph.addUndirectedEdge(v[a], v[b], 1);
  }
  MaxFlow maxFlow;
  cout << maxFlow.solve(graph, v[0], sink) << endl;
}

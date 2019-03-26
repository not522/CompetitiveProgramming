#include "graph/max_flow.hpp"

int main() {
  int n(in), g(in), e(in), id = 0, sink = id++;
  Vector<int> v(n);
  for (int &i : v) {
    i = id++;
  }
  ResidualGraph<ResidualEdge<int>> graph(id);
  for (int i = 0; i < g; ++i) {
    graph.addEdge(v[int(in)], sink, 1);
  }
  for (int i = 0; i < e; ++i) {
    int a(in), b(in);
    graph.addUndirectedEdge(v[a], v[b], 1);
  }
  cout << maxFlow(graph, v[0], sink) << endl;
}

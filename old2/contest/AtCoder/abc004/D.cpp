#include "graph/min_cost_flow.hpp"

int main() {
  Vector<int> n(3, in), v(3), box(2000);
  int id = 0, source = id++, sink = id++;
  for (int &i : v) {
    i = id++;
  }
  for (int &i : box) {
    i = id++;
  }
  ResidualGraph<WeightedResidualEdge<int, int>> graph(id);
  for (int i = 0; i < 3; ++i) {
    graph.addEdge(source, v[i], n[i], 0);
    for (int j = 0; j < 2000; ++j) {
      graph.addEdge(v[i], box[j], 1, abs((i * 100 - 100) - (j - 1000)));
    }
  }
  for (int i = 0; i < 2000; ++i) {
    graph.addEdge(box[i], sink, 1, 0);
  }
  cout << minCostFlow(graph, source, sink, n.accumulate()) << endl;
}

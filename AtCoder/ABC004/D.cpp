#include "graph/min_cost_flow.hpp"

int main() {
  array<int, 3> n;
  for (int& i : n) cin >> i;
  int id = 0;
  int source = id++, sink = id++;
  array<int, 3> v;
  array<int, 2000> box;
  for (int& i : v) i = id++;
  for (int& i : box) i = id++;
  ResidualGraph<WeightedResidualEdge<int, int>> graph(id);
  for (int i = 0; i < 3; ++i) {
    graph.add_edge(WeightedResidualEdge<int, int>(source, v[i], n[i], 0));
    for (int j = 0; j < 2000; ++j) {
      graph.add_edge(WeightedResidualEdge<int, int>(v[i], box[j], 1, abs((i * 100 - 100) - (j - 1000))));
    }
  }
  for (int i = 0; i < 2000; ++i) {
    graph.add_edge(WeightedResidualEdge<int, int>(box[i], sink, 1, 0));
  }
  MinCostFlow<int, int> mcf(graph);
  cout << mcf.run(source, sink, accumulate(n.begin(), n.end(), 0)) << endl;
}

#include "graph/adjacency_list.hpp"
#include "graph/all_pairs_shortest_path.hpp"

int main() {
  int n(in), m(in);
  AdjacencyList<WeightedEdge<int>> graph(in, n, m);
  cout << shortestPath(graph).min([](const auto &d) { return d.max(); }).max()
       << endl;
}

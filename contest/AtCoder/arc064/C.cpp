#include "vector.hpp"
#include "geometry/distance.hpp"
#include "graph/adjacency_list.hpp"
#include "graph/edge.hpp"
#include "graph/shortest_path.hpp"

int main() {
  double xs, ys, xt, yt;
  cin >> xs >> ys >> xt >> yt;
  int n;
  cin >> n;
  vector<Circle> c(n);
  cin >> c;
  c.emplace_back(xs, ys, 0);
  c.emplace_back(xt, yt, 0);
  AdjacencyList<WeightedEdge<long double>> graph(n + 2);
  for (int i = 0; i < n + 2; ++i) {
    for (int j = i + 1; j < n + 2; ++j) {
      graph.addUndirectedEdge(i, j, distance(c[i], c[j]));
    }
  }
  cout << shortestPath(graph, n, n + 1) << endl;
}

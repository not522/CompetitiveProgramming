#include "graph/adjacency_list.hpp"
#include "graph/edge.hpp"
#include "graph/shortest_path.hpp"

int main() {
  int x, y;
  cin >> x >> y;
  AdjacencyList<WeightedEdge<int>> g(4);
  g.addUndirectedEdge(0, 1, 1);
  g.addUndirectedEdge(2, 3, 1);
  int v[] = {abs(x), -abs(x), abs(y), -abs(y)};
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      if (v[i] <= v[j]) g.addEdge(i, j, v[j] - v[i]);
    }
  }
  cout << shortestPath(g, x > 0 ? 0 : 1, y > 0 ? 2 : 3) << endl;
}

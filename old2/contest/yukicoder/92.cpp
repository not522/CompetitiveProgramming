#include "graph/adjacency_list.hpp"
#include "set.hpp"
#include "string.hpp"

int main() {
  int n(in), m(in), k(in);
  AdjacencyList<WeightedEdge<int>> graph(in, n + 1, m, true, false);
  Set<int> now, next;
  for (int i = 1; i <= n; ++i) {
    now.insert(i);
  }
  for (int i = 0; i < k; ++i) {
    int d(in);
    for (const auto &edge : graph.getAllEdges()) {
      if (now.count(edge.from) && d == edge.cost) {
        next.insert(edge.to);
      }
    }
    now = next;
    next.clear();
  }
  cout << now.size() << endl;
  now.output(" ");
}

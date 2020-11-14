#include "graph/adjacency_list.hpp"
#include "graph/all_pairs_reachability.hpp"
#include "string.hpp"

int main() {
  int n(in);
  Vector<String> s(n, in);
  AdjacencyList<Edge> graph(n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (s[i][j] == '1') {
        graph.addEdge(j, i);
      }
    }
  }
  auto reachable = reachability(graph);
  double res = 0;
  for (int i = 0; i < n; ++i) {
    res += 1.0 / reachable[i].count_if([](bool b) { return b; });
  }
  cout << res << endl;
}

#include "permutation.hpp"
#include "graph/adjacency_list.hpp"
#include "graph/edge.hpp"

int main() {
  int n, m, r = 0;
  cin >> n >> m;
  AdjacencyList<Edge> graph(n);
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    graph.addUndirectedEdge(a - 1, b - 1);
  }
  for (const auto& perm : Permutation(n - 1)) {
    bool f = true;
    if (!graph.hasEdge(0, perm[0] + 1)) f = false;
    for (int i = 0; i < n - 2; ++i) {
      if (!graph.hasEdge(perm[i] + 1, perm[i + 1] + 1)) f = false;
    }
    if (f) ++r;
  }
  cout << r << endl;
}

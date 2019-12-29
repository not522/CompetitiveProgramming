#include "graph/adjacency_list.hpp"
#include "permutation.hpp"

int main() {
  AdjacencyList<Edge> graph(in);
  int n = graph.size(), r = 0;
  for (const auto &perm : Permutation(n - 1)) {
    bool f = true;
    if (!graph.hasEdge(0, perm[0] + 1)) {
      f = false;
    }
    for (int i = 0; i < n - 2; ++i) {
      if (!graph.hasEdge(perm[i] + 1, perm[i + 1] + 1)) {
        f = false;
      }
    }
    if (f) {
      ++r;
    }
  }
  cout << r << endl;
}

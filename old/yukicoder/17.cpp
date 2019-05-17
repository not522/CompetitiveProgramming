#include "vector.hpp"
#include "graph/adjacency_list.hpp"
#include "graph/all_pairs_shortest_path.hpp"

int main() {
  using Graph = AdjacencyList<WeightedEdge<int>>;
  int n(in);
  Vector<int> s(n, in);
  int m(in);
  Graph graph(in, n, m, true, false);
  auto dis = shortestPath(graph);
  int res = inf<int>();
  for (int i = 1; i < n - 1; ++i) {
    for (int j = 1; j < n - 1; ++j) {
      if (i != j) {
        if (dis[0][i] == inf<int>() || dis[i][j] == inf<int>() || dis[j][n - 1] == inf<int>()) {
          continue;
        }
        chmin(res, dis[0][i] + dis[i][j] + dis[j][n - 1] + s[i] + s[j]);
      }
    }
  }
  cout << res << endl;
}

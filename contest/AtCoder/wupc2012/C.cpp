#include "vector.hpp"
#include "graph/adjacency_list.hpp"
#include "graph/bfs.hpp"
#include "graph/edge.hpp"

int main() {
  int n, m, s = -1, c = -1, g = -1;
  cin >> n >> m;
  vector<string> v(n);
  cin >> v;
  AdjacencyList<Edge> graph(n * m);
  for (int i = 1; i < n - 1; ++i) {
    for (int j = 1; j < m - 1; ++j) {
      if (v[i][j] == 'S') s = i * m + j;
      if (v[i][j] == 'C') c = i * m + j;
      if (v[i][j] == 'G') g = i * m + j;
      if (v[i][j] == '#') continue;
      if (v[i + 1][j] != '#') graph.addUndirectedEdge(i * m + j, i * m + m + j);
      if (v[i][j + 1] != '#') graph.addUndirectedEdge(i * m + j, i * m + j + 1);
    }
  }
  auto state = bfsDistance(graph, c);
  cout << (state.isReachable(s) && state.isReachable(g) ? state.dis[s] + state.dis[g] : -1) << endl;
}

#include "vector.hpp"
#include "graph/adjacency_list.hpp"
#include "graph/edge.hpp"
#include "graph/shortest_path.hpp"

int main() {
  int h, w, s = -1, g = -1;
  cin >> h >> w;
  vector<string> c(h);
  cin >> c;
  AdjacencyList<WeightedEdge<int>> graph(h * w);
  const int dy[] = {0, -1, 0, 1};
  const int dx[] = {1, 0, -1, 0};
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (c[i][j] == 's') s = i * w + j;
      if (c[i][j] == 'g') g = i * w + j;
      for (int k = 0; k < 4; ++k) {
        int ii = i + dy[k];
        int jj = j + dx[k];
        if (ii < 0 || h <= ii || jj < 0 || w <= jj) continue;
        graph.addEdge(ii * w + jj, i * w + j, c[i][j] == '#' ? 1 : 0);
      }
    }
  }
  cout << (shortestPath(graph, s, g) <= 2 ? "YES" : "NO") << endl;
}

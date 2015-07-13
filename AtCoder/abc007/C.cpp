#include "graph/edge.hpp"
#include "graph/adjacency_list.hpp"
#include "graph/bfs.hpp"

int main() {
  int r, c, sy, sx, gy, gx;
  cin >> r >> c >> sy >> sx >> gy >> gx;
  --sy; --sx; --gy; --gx;
  vector<string> v(r);
  for (string& s : v) cin >> s;
  AdjacencyList<Edge> graph(r * c);
  const int dy[] = {0, -1, 0, 1};
  const int dx[] = {1, 0, -1, 0};
  for (int i = 1; i < r - 1; ++i) {
    for (int j = 1; j < c - 1; ++j) {
      if (v[i][j] == '#') continue;
      for (int k = 0; k < 4; ++k) {
        int ii = i + dy[k];
        int jj = j + dx[k];
        if (v[ii][jj] == '#') continue;
        graph.addEdge(Edge(i * c + j, ii * c + jj));
      }
    }
  }
  auto info = bfsDistance(graph, sy * c + sx);
  cout << info.dis[gy * c + gx] << endl;
}

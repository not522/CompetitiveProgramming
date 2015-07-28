#include "graph/edge.hpp"
#include "graph/adjacency_list.hpp"
#include "graph/weighted_bfs.hpp"

int main() {
  int w, h;
  cin >> w >> h;
  vector<string> c(h);
  for (auto& i : c) cin >> i;
  AdjacencyList<WeightedEdge<int>> graph(w * h);
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w - 1; ++j) {
      graph.addEdge(i * w + j, i * w + j + 1, c[i][j + 1] == '.' ? 0 : 1);
    }
    for (int j = 0; j < w - 1; ++j) {
      graph.addEdge(i * w + j + 1, i * w + j, c[i][j] == '.' ? 0 : 1);
    }
  }
  for (int i = 0; i < h - 1; ++i) {
    for (int j = 0; j < w; ++j) {
      graph.addEdge(i * w + j, i * w + j + w, c[i + 1][j] == '.' ? 0 : 1);
    }
    for (int j = 0; j < w; ++j) {
      graph.addEdge(i * w + j + w, i * w + j, c[i][j] == '.' ? 0 : 1);
    }
  }
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (c[i][j] == '.') {
        auto dis = weightedBFSDistance(graph, i * w + j).dis;
        int res = 0;
        for (int a = 0; a < h; ++a) {
          for (int b = 0; b < w; ++b) {
            if (c[a][b] == '.') res = max(res, dis[a * w + b]);
          }
        }
        cout << res << endl;
        return 0;
      }
    }
  }
}

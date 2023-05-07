#include "adjacent_loop.hpp"
#include "graph/adjacency_list.hpp"
#include "graph/shortest_path.hpp"
#include "string.hpp"

int main() {
  int h(in), w(in), ch(in), cw(in), dh(in), dw(in);
  --ch;
  --cw;
  --dh;
  --dw;
  Vector<String> s(h, in);
  AdjacencyList<WeightedEdge<int>> graph(h * w);
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (s[i][j] == '#') {
        continue;
      }
      for (auto [y, x] : AdjacentLoop<2>(i, j, h, w)) {
        if (s[y][x] == '#') {
          continue;
        }
        graph.addUndirectedEdge(i * w + j, y * w + x, 0);
      }
      for (int y = i - 2; y <= i + 2; ++y) {
        for (int x = j - 2; x <= j + 2; ++x) {
          if (y < 0 || h <= y || x < 0 || w <= x) {
            continue;
          }
          if (s[y][x] == '#') {
            continue;
          }
          graph.addUndirectedEdge(i * w + j, y * w + x, 1);
        }
      }
    }
  }
  auto dis = shortestPath(graph, ch * w + cw, dh * w + dw);
  if (dis == inf<int>()) {
    cout << -1 << endl;
  } else {
    cout << dis << endl;
  }
}

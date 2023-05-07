#include "adjacent_loop.hpp"
#include "graph/adjacency_list.hpp"
#include "graph/bfs.hpp"
#include "string.hpp"

int main() {
  int r(in), c(in), sy(in), sx(in), gy(in), gx(in);
  --sy;
  --sx;
  --gy;
  --gx;
  Vector<String> v(r, in);
  AdjacencyList<Edge> graph(r * c);
  for (int i = 1; i < r - 1; ++i) {
    for (int j = 1; j < c - 1; ++j) {
      if (v[i][j] == '#') {
        continue;
      }
      for (auto [ii, jj] : AdjacentLoop<4>(i, j, r, c)) {
        if (v[ii][jj] != '#') {
          graph.addEdge(i * c + j, ii * c + jj);
        }
      }
    }
  }
  auto info = bfsDistance(graph, sy * c + sx);
  cout << info.dis[gy * c + gx] << endl;
}

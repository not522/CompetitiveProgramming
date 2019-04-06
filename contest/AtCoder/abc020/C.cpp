#include "adjacent_loop.hpp"
#include "binary_search.hpp"
#include "graph/adjacency_list.hpp"
#include "graph/shortest_path.hpp"
#include "string.hpp"

int main() {
  int h(in), w(in), t(in);
  Vector<String> s(h, in);
  auto f = [&](int64_t n) {
    AdjacencyList<WeightedEdge<int64_t>> graph(h * w);
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        for (auto p : AdjacentLoop<4>(i, j, h, w)) {
          int ii, jj;
          std::tie(ii, jj) = p;
          graph.addEdge(i * w + j, ii * w + jj, s[ii][jj] == '#' ? n : 1);
        }
      }
    }
    int a = -1, b = -1;
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        if (s[i][j] == 'S') {
          a = i * w + j;
        }
        if (s[i][j] == 'G') {
          b = i * w + j;
        }
      }
    }
    return shortestPath(graph, a, b) <= t;
  };
  cout << binarySearch(f, 1, t) << endl;
}

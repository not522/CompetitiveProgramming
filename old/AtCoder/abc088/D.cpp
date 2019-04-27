#include "adjacent_loop.hpp"
#include "graph/adjacency_list.hpp"
#include "graph/shortest_path.hpp"

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  cin >> s;
  AdjacencyList<Edge> graph(h * w);
  int res = 0;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (s[i][j] == '.') ++res;
      for (auto p : AdjacentLoop<2>(i, j, h, w)) {
        if (s[i][j] == '.' && s[p.first][p.second] == '.') {
          graph.addUndirectedEdge(i * w + j, p.first * w + p.second);
        }
      }
    }
  }
  int c = shortestPath(graph, 0, h * w - 1);
  cout << (c != numeric_limits<int>::max() ? res - c - 1 : -1) << endl;
}

#include "graph/edge.hpp"
#include "graph/adjacency_list.hpp"
#include "graph/dfs.hpp"

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> c(h);
  for (auto& s : c) cin >> s;
  typedef AdjacencyList<Edge> Graph;
  Graph graph(h * w);
  int sv = -1, gv = -1;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (c[i][j] == 's') sv = i * w + j;
      if (c[i][j] == 'g') gv = i * w + j;
      if (j < w - 1 && c[i][j] != '#' && c[i][j + 1] != '#') {
        graph.addUndirectedEdge(i * w + j, i * w + j + 1);
      }
      if (i < h - 1 && c[i][j] != '#' && c[i + 1][j] != '#') {
        graph.addUndirectedEdge(i * w + j, i * w + j + w);
      }
    }
  }
  DFS<Graph> dfs(graph);
  dfs.solve(sv);
  cout << (dfs.isReachable(gv) ? "Yes" : "No") << endl;
}

#include "graph/edge.hpp"
#include "graph/adjacency_list.hpp"
#include "graph/all_pairs_shortest_path.hpp"

int main() {
  typedef AdjacencyList<WeightedEdge<int>> Graph;
  int n;
  cin >> n;
  vector<int> s(n);
  for (int& i : s) cin >> i;
  Graph graph(n);
  int m;
  cin >> m;
  for (int i = 0; i < m; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    graph.addUndirectedEdge(a, b, c);
  }
  auto dis = shortestPath(graph).dis;
  int res = numeric_limits<int>::max();
  const int INF = WarshallFloyd<Graph>::INF;
  for (int i = 1; i < n - 1; ++i) {
    for (int j = 1; j < n - 1; ++j) {
      if (i == j) continue;
      if (dis[0][i] == INF || dis[i][j] == INF || dis[j][n - 1] == INF) continue;
      res = min(res, dis[0][i] + dis[i][j] + dis[j][n - 1] + s[i] + s[j]);
    }
  }
  cout << res << endl;
}

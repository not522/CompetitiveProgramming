#include "graph/adjacency_list.hpp"
#include "graph/shortest_path.hpp"

int main() {
  int h, w;
  cin >> h >> w;
  AdjacencyList<WeightedEdge<int>> graph(10);
  for (int i = 0; i < 10; ++i) {
    for (int j = 0; j < 10; ++j) {
      int c;
      cin >> c;
      graph[j].emplace_back(i, c);
    }
  }
  auto dis = shortestPath(graph, 1).dis;
  int res = 0, a;
  for (int i = 0; i < h * w; ++i) {
    cin >> a;
    if (a != -1) res += dis[a];
  }
  cout << res << endl;
}

#include "graph/adjacency_list.hpp"
#include "graph/bfs.hpp"

int main() {
  set_bool_name("Fennec", "Snuke");
  int n;
  cin >> n;
  AdjacencyList<Edge> graph(n);
  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    cin >> a >> b;
    graph.addUndirectedEdge(a - 1, b - 1);
  }
  auto dis1 = bfsDistance(graph, 0).dis;
  auto dis2 = bfsDistance(graph, n - 1).dis;
  int a = 0;
  for (int i = 0; i < n; ++i) {
    if (dis1[i] <= dis2[i]) ++a;
  }
  cout << (a > n - a) << endl;
}

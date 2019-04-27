#include "graph/edge.hpp"
#include "graph/adjacency_list.hpp"
#include "string/to_string.hpp"

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  AdjacencyList<WeightedEdge<int>> graph(n + 1);
  for (int i = 0; i < m; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    graph.addUndirectedEdge(a, b, c);
  }
  set<int> now, next;
  for (int i = 1; i <= n; ++i) now.insert(i);
  for (int i = 0; i < k; ++i) {
    int d;
    cin >> d;
    for (const auto& edge : graph.getAllEdges()) {
      if (now.count(edge.from) && d == edge.cost) next.insert(edge.to);
    }
    now = next;
    next.clear();
  }
  cout << now.size() << endl << to_string(now) << endl;
}

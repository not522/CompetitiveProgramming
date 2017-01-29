#include "vector.hpp"
#include "graph/adjacency_list.hpp"
#include "graph/bfs.hpp"
#include "graph/edge.hpp"

bool ok(const string& a, const string& b) {
  return inner_product(a.begin(), a.end(), b.begin(), 0, plus<int>(), [](char a, char b){return a == b ? 0 : 1;}) == 1;
}

int main() {
  string first, last;
  int n;
  cin >> first >> last >> n;
  if (first == last) {
    cout << 0 << endl << first << endl << last << endl;
    return 0;
  }
  vector<string> s(n);
  cin >> s;
  AdjacencyList<Edge> graph(n + 2);
  if (ok(first, last)) graph.addUndirectedEdge(n, n + 1);
  for (int i = 0; i < n; ++i) if (ok(first, s[i])) graph.addUndirectedEdge(i, n);
  for (int i = 0; i < n; ++i) if (ok(last, s[i])) graph.addUndirectedEdge(i, n + 1);
  for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) {
    if (ok(s[i], s[j])) graph.addUndirectedEdge(i, j);
  }
  auto state = bfsDistanceTree(graph, n + 1);
  if (state.isReachable(n)) {
    cout << state.dis[n] - 1 << endl;
    cout << first << endl;
    for (int i : state.shortestPathTree.getPath(n)) if (i < n) cout << s[i] << endl;
    cout << last << endl;
  } else {
    cout << -1 << endl;
  }
}

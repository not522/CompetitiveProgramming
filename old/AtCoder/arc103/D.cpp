#include "vector.hpp"
#include "graph/bfs.hpp"
#include "graph/edge.hpp"

int main() {
  int n;
  cin >> n;
  map<int64_t, int> d;
  for (int i = 0; i < n; ++i) {
    int64_t a;
    cin >> a;
    d[a] = i;
  }
  vector<int> k(n, 1);
  Tree<Edge> tree(n);
  auto itr = d.rbegin();
  for (int i = 0; i < n - 1; ++i, ++itr) {
    auto c = itr->first - n + 2 * k[itr->second];
    auto next = d.find(c);
    if (next == d.end() || next->second == itr->second) {
      cout << -1 << endl;
      return 0;
    }
    k[next->second] += k[itr->second];
    tree.addEdge(itr->second, next->second);
  }
  auto dis = bfsDistance(tree, d.begin()->second);
  int64_t c = 0;
  for (int i = 0; i < n; ++i) c += dis.dis[i];
  if (c != d.begin()->first) {
    cout << -1 << endl;
  } else {
    for (int v = 0; v < n; ++v) {
      for (int u : tree.children[v]) cout << v + 1 << " " << u + 1 << endl;
    }
  }
}

#include "graph/adjacency_list.hpp"

int main() {
  int n(in), m(in);
  AdjacencyList<Edge> graph(in, n, m, false);
  Vector<double> dp1(n);
  Vector<int> mxi(n);
  for (int v = n - 1; v >= 0; --v) {
    double mx = 0;
    for (const auto &edge : graph[v]) {
      if (chmax(mx, dp1[edge.to] + 1)) {
        mxi[v] = edge.to;
      }
      dp1[v] += (dp1[edge.to] + 1) / graph[v].size();
    }
  }
  double res = dp1[0];
  for (int u = 0; u < n; ++u) {
    if (graph[u].size() == 1) {
      continue;
    }
    Vector<double> dp2(n);
    for (int v = n - 1; v >= 0; --v) {
      for (const auto &edge : graph[v]) {
        if (v != u) {
          dp2[v] += (dp2[edge.to] + 1) / graph[v].size();
        } else if (mxi[v] != edge.to) {
          dp2[v] += (dp2[edge.to] + 1) / (graph[v].size() - 1);
        }
      }
    }
    chmin(res, dp2[0]);
  }
  cout << res << endl;
}

#include "vector.hpp"

struct Edge {
  int to, cost, dist;

  Edge() {}

  Edge(int to, int cost, int dist) : to(to), cost(cost), dist(dist) {}
};

int main() {
  int n(in), c(in), v(in);
  Vector<int> s(v, in), t(v, in), y(v, in), m(v, in);
  Vector<Vector<Edge>> edge(n);
  for (int i = 0; i < v; ++i) {
    edge[s[i] - 1].emplace_back(Edge(t[i] - 1, y[i], m[i]));
  }
  Vector<Vector<int>> dp(n, Vector<int>(c + 1, inf<int>()));
  fill(dp[0].begin(), dp[0].end(), 0);
  for (int i = 0; i < n; ++i) {
    for (const auto &e : edge[i]) {
      for (int j = 0; j <= c - e.cost; ++j) {
        dp[e.to][j + e.cost] = min(dp[e.to][j + e.cost], dp[i][j] + e.dist);
      }
    }
  }
  cout << (dp[n - 1][c] != inf<int>() ? dp[n - 1][c] : -1) << endl;
}

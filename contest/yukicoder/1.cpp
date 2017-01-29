#include "vector.hpp"

struct Edge {
  int to, cost, dist;

  Edge() {}

  Edge(int to, int cost, int dist) : to(to), cost(cost), dist(dist) {}
};

int main() {
  int n, c, v;
  cin >> n >> c >> v;
  vector<int> s(v), t(v), y(v), m(v);
  vector<vector<Edge>> edge(n);
  cin >> s >> t >> y >> m;
  for (int i = 0; i < v; ++i) edge[s[i] - 1].emplace_back(Edge(t[i] - 1, y[i], m[i]));
  const int INF = numeric_limits<int>::max() / 2;
  vector<vector<int>> dp(n, vector<int>(c + 1, INF));
  fill(dp[0].begin(), dp[0].end(), 0);
  for (int i = 0; i < n; ++i) {
    for (const auto& e : edge[i]) {
      for (int j = 0; j <= c - e.cost; ++j) {
        dp[e.to][j + e.cost] = min(dp[e.to][j + e.cost], dp[i][j] + e.dist);
      }
    }
  }
  cout << (dp[n - 1][c] != INF ? dp[n - 1][c] : -1) << endl;
}

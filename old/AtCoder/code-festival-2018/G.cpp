#include "template.hpp"

vector<int> solve(const vector<int>& c) {
  int n = c.size();
  vector<int> res(n + 1, -1);
  {
    vector<vector<int>> dp1(n + 1, vector<int>(2, -1));
    vector<vector<int>> dp2(n + 1, vector<int>(2, -1));
    dp1[0][0] = 0;
    for (int i = 1; i < n; ++i) {
      for (int j = 0; j <= n; ++j) dp2[j][0] = dp2[j][1] = -1;
      for (int j = 0; j <= i; ++j) {
        if (dp1[j][0] != -1) {
          chmax(dp2[j + 1][0], dp1[j][0] + c[i]);
          chmax(dp2[j + 1][1], dp1[j][0] + 2 * c[i]);
        }
        if (dp1[j][1] != -1) {
          chmax(dp2[j][0], dp1[j][1]);
          chmax(dp2[j + 1][1], dp1[j][1] + c[i]);
        }
      }
      swap(dp1, dp2);
    }
    for (int i = 0; i <= n; ++i) {
      if (dp1[i][0] != -1) chmax(res[i + 1], dp1[i][0] + c[0]);
      if (dp1[i][1] != -1) chmax(res[i], dp1[i][1]);
    }
  }
  {
    vector<vector<int>> dp1(n + 1, vector<int>(2, -1));
    vector<vector<int>> dp2(n + 1, vector<int>(2, -1));
    dp1[1][1] = c[0];
    for (int i = 1; i < n; ++i) {
      for (int j = 0; j <= n; ++j) dp2[j][0] = dp2[j][1] = -1;
      for (int j = 0; j <= i; ++j) {
        if (dp1[j][0] != -1) {
          chmax(dp2[j + 1][0], dp1[j][0] + c[i]);
          chmax(dp2[j + 1][1], dp1[j][0] + 2 * c[i]);
        }
        if (dp1[j][1] != -1) {
          chmax(dp2[j][0], dp1[j][1]);
          chmax(dp2[j + 1][1], dp1[j][1] + c[i]);
        }
      }
      swap(dp1, dp2);
    }
    for (int i = 0; i <= n; ++i) {
      if (dp1[i][0] != -1) chmax(res[i], dp1[i][0] + c[0]);
      if (dp1[i][1] != -1) chmax(res[i], dp1[i][1]);
    }
  }
  return res;
}

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n), b(n);
  cin >> a >> b;
  vector<vector<int>> g(n);
  for (int i = 0; i < n; ++i) {
    g[a[i] - 1].emplace_back(b[i] - 1);
    g[b[i] - 1].emplace_back(a[i] - 1);
  }
  vector<vector<int>> c;
  vector<bool> used(n);
  for (int i = 0; i < n; ++i) {
    if (used[i]) continue;
    int v = i, p = -1;
    vector<int> circle;
    do {
      used[v] = true;
      circle.emplace_back(v + 1);
      auto u = g[v][0];
      if (u == p) u = g[v][1];
      p = v;
      v = u;
    } while (v != i);
    c.emplace_back(circle);
  }
  vector<int> dp(n + 1, -1);
  dp[0] = 0;
  for (int i = 0; i < int(c.size()); ++i) {
    auto v = solve(c[i]);
    vector<int> dp2(n + 1, -1);
    for (int j = 0; j <= n; ++j) {
      if (dp[j] == -1) continue;
      for (int x = c[i].size() / 2; x < int(v.size()) && j + x <= n; ++x) {
        if (v[x] == -1) continue;
        chmax(dp2[j + x], dp[j] + v[x]);
      }
    }
    dp = dp2;
  }
  int res = 0;
  for (int i = k; i <= n; ++i) chmax(res, dp[i]);
  cout << res << endl;
}

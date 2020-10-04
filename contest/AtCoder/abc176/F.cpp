#include "queue.hpp"
#include "vector.hpp"

int main() {
  int n(in);
  Vector<int> a(3 * n, in);
  --a;
  int res = 0;
  auto dp = Vector<int>::makeVector(n, n);
  dp = -1e9;
  Vector<int> dp_max(n, -1e9);
  int dp_max_all = 0;
  dp[a[0]][a[1]] = 0;
  dp_max[a[0]] = 0;
  dp_max[a[1]] = 0;
  Queue<Tuple<int, int, int>> que;
  for (int i = 2; i + 3 < 3 * n; i += 3) {
    if (a[i] == a[i + 1] && a[i + 1] == a[i + 2]) {
      ++res;
    } else {
      if (a[i] == a[i + 1]) {
        for (int k = 0; k < n; ++k) {
          que.emplace(k, a[i + 2], max(dp[k][a[i]], dp[a[i]][k]) + 1);
        }
      } else if (a[i] == a[i + 2]) {
        for (int k = 0; k < n; ++k) {
          que.emplace(k, a[i + 1], max(dp[k][a[i]], dp[a[i]][k]) + 1);
        }
      } else if (a[i + 1] == a[i + 2]) {
        for (int k = 0; k < n; ++k) {
          que.emplace(k, a[i], max(dp[k][a[i + 1]], dp[a[i + 1]][k]) + 1);
        }
      }
      que.emplace(a[i], a[i + 1], dp[a[i + 2]][a[i + 2]] + 1);
      que.emplace(a[i], a[i + 2], dp[a[i + 1]][a[i + 1]] + 1);
      que.emplace(a[i + 1], a[i + 2], dp[a[i]][a[i]] + 1);
      for (int k = 0; k < n; ++k) {
        for (int j = 0; j < 3; ++j) {
          que.emplace(k, a[i + j], dp_max[k]);
        }
      }
      que.emplace(a[i], a[i + 1], dp_max_all);
      que.emplace(a[i], a[i + 2], dp_max_all);
      que.emplace(a[i + 1], a[i + 2], dp_max_all);
    }
    while (!que.empty()) {
      auto [i, j, v] = que.front();
      chmax(dp[i][j], v);
      chmax(dp_max[i], v);
      chmax(dp_max[j], v);
      chmax(dp_max_all, v);
    }
  }
  cout << res + max(dp_max_all, dp[a.back()][a.back()] + 1) << endl;
}

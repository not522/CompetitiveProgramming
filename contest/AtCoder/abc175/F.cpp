#include "priority_queue.hpp"
#include "string.hpp"

void enque(PriorityQueue<Tuple<int64_t, int, int, int>, false> &que, String a,
           String b, int i, int j, int64_t cost) {
  b.reverse();
  int t = min(a.size(), b.size());
  if (a.substr(0, t) != b.substr(0, t)) {
    return;
  }
  if (a.size() < b.size()) {
    que.emplace(cost, 1, j, b.size() - a.size());
  } else {
    que.emplace(cost, 0, i, a.size() - b.size());
  }
}

int main() {
  int n(in);
  Vector<String> s(n);
  Vector<int64_t> c(n);
  read(s, c);
  int64_t res = inf<int64_t>();
  for (int i = 0; i < n; ++i) {
    if (s[i].isPalindrome()) {
      chmin(res, c[i]);
    }
  }
  auto dp = Vector<int64_t>::makeVector(2, n, 21);
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < 21; ++k) {
        dp[i][j][k] = inf<int64_t>();
      }
    }
  }
  PriorityQueue<Tuple<int64_t, int, int, int>, false> que;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      enque(que, s[i], s[j], i, j, c[i] + c[j]);
    }
  }
  while (!que.empty()) {
    auto [cost, id, i, k] = que.top();
    if (id == 0 && s[i].substr(s[i].size() - k).isPalindrome()) {
      chmin(res, cost);
      continue;
    }
    if (id == 1 && s[i].substr(0, k).isPalindrome()) {
      chmin(res, cost);
      continue;
    }
    if (!chmin(dp[id][i][k], cost)) {
      continue;
    }
    if (id == 0) {
      for (int j = 0; j < n; ++j) {
        enque(que, s[i].substr(s[i].size() - k), s[j], i, j, cost + c[j]);
      }
    } else {
      for (int j = 0; j < n; ++j) {
        enque(que, s[j], s[i].substr(0, k), j, i, cost + c[j]);
      }
    }
  }
  if (res != inf<int64_t>()) {
    cout << res << endl;
  } else {
    cout << -1 << endl;
  }
}

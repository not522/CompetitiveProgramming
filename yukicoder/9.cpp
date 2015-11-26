#include "vector.hpp"

int main() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  cin >> a >> b;
  int res = numeric_limits<int>::max();
  for (int i = 0; i < n; ++i) {
    priority_queue<tuple<int, int>, vector<tuple<int, int>>, greater<tuple<int, int>>> que;
    for (int i : a) que.push(make_tuple(i, 0));
    for (int i = 0; i < n; ++i) {
      auto p = que.top();
      que.pop();
      que.push(make_tuple(get<0>(p) + b[i] / 2, get<1>(p) + 1));
    }
    int mx = 0;
    while (!que.empty()) {
      mx = max(mx, get<1>(que.top()));
      que.pop();
    }
    res = min(res, mx);
    rotate(b.begin(), b.begin() + 1, b.end());
  }
  cout << res << endl;
}

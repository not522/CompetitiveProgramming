#include "vector.hpp"

int main() {
  int64_t w, h, res = 0;
  cin >> w >> h;
  vector<int64_t> p(w), q(h);
  cin >> p >> q;
  priority_queue<pair<int64_t, int>, vector<pair<int64_t, int>>, greater<pair<int64_t, int>>> que;
  for (auto i : p) que.emplace(i, 0);
  for (auto i : q) que.emplace(i, 1);
  while (!que.empty()) {
    auto now = que.top();
    que.pop();
    if (now.second == 0) {
      res += now.first * (h + 1);
      --w;
    } else {
      res += now.first * (w + 1);
      --h;
    }
  }
  cout << res << endl;
}

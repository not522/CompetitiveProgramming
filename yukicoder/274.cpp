#include "template.hpp"

int main() {
  int n, m;
  cin >> n >> m;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
  for (int i = 0; i < n; ++i) {
    int l, r;
    cin >> l >> r;
    if (l > m - r - 1) que.push(make_pair(m - r - 1, m - l - 1));
    else que.push(make_pair(l, r));
  }
  int t = -1;
  while (!que.empty()) {
    auto now = que.top();
    que.pop();
    if (t >= now.first) {
      if (now.first >= m - now.second - 1) {
        cout << "NO" << endl;
        return 0;
      }
      que.push(make_pair(m - now.second - 1, m - now.first - 1));
    } else {
      t = now.second;
    }
  }
  cout << "YES" << endl;
}

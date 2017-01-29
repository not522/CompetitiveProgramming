#include "template.hpp"

int main() {
  int n, m, x[2];
  cin >> n >> m >> x[0] >> x[1];
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    que.push(make_pair(a, 0));
  }
  for (int i = 0; i < m; ++i) {
    int b;
    cin >> b;
    que.push(make_pair(b, 1));
  }
  int c = 0, t = 0, res = 0;
  while (!que.empty()) {
    auto now = que.top();
    que.pop();
    if (now.second != c) continue;
    if (now.first < t) continue;
    t = now.first + x[c];
    c = 1 - c;
    ++res;
  }
  cout << res / 2 << endl;
}

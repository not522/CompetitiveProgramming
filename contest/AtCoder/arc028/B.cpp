#include "vector.hpp"

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> x(n);
  cin >> x;
  priority_queue<pair<int, int>> que;
  for (int i = 0; i < n; ++i) {
    que.push(make_pair(x[i], i + 1));
    if ((int)que.size() > k) que.pop();
    if ((int)que.size() == k) cout << que.top().second << endl;
  }
}

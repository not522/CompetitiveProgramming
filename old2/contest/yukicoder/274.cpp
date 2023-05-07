#include "priority_queue.hpp"
#include "tuple.hpp"

int main() {
  setBoolName("YES", "NO");
  int n(in), m(in);
  PriorityQueue<Tuple<int, int>, false> que;
  for (int i = 0; i < n; ++i) {
    int l(in), r(in);
    if (l > m - r - 1) {
      que.emplace(m - r - 1, m - l - 1);
    } else {
      que.emplace(l, r);
    }
  }
  int t = -1;
  while (!que.empty()) {
    auto now = que.top();
    if (t >= now.get<0>()) {
      if (now.get<0>() >= m - now.get<1>() - 1) {
        cout << false << endl;
        return 0;
      }
      que.emplace(m - now.get<1>() - 1, m - now.get<0>() - 1);
    } else {
      t = now.get<1>();
    }
  }
  cout << true << endl;
}

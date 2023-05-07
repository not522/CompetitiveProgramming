#include "priority_queue.hpp"
#include "vector.hpp"

int main() {
  int n(in);
  Vector<int> a(n, in), b(n, in);
  int res = inf<int>();
  for (int i = 0; i < n; ++i) {
    PriorityQueue<Tuple<int, int>, false> que;
    for (int i : a) {
      que.emplace(i, 0);
    }
    for (int i = 0; i < n; ++i) {
      auto p = que.top();
      que.emplace(p.get<0>() + b[i] / 2, p.get<1>() + 1);
    }
    int mx = 0;
    while (!que.empty()) {
      chmax(mx, que.top().get<1>());
    }
    chmin(res, mx);
    b.rotate(1);
  }
  cout << res << endl;
}

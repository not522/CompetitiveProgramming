#include "priority_queue.hpp"
#include "vector.hpp"

int main() {
  int n(in), m(in);
  Vector<int> x(2, in);
  PriorityQueue<Tuple<int, int>, false> que;
  for (int i = 0; i < n; ++i) {
    que.emplace(int(in), 0);
  }
  for (int i = 0; i < m; ++i) {
    que.emplace(int(in), 1);
  }
  int c = 0, t = 0, res = 0;
  while (!que.empty()) {
    auto now = que.top();
    if (now.get<0>() >= t && now.get<1>() == c) {
      t = now.get<0>() + x[c];
      c = 1 - c;
      ++res;
    }
  }
  cout << res / 2 << endl;
}

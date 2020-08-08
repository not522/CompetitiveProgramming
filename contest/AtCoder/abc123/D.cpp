#include "priority_queue.hpp"
#include "set.hpp"
#include "vector.hpp"

int main() {
  int x(in), y(in), z(in), k(in);
  Vector<int64_t> a(x, in), b(y, in), c(z, in);
  a.rsort();
  b.rsort();
  c.rsort();
  PriorityQueue<Tuple<int64_t, int, int, int>> que;
  Set<Tuple<int, int, int>> s;
  que.emplace(a[0] + b[0] + c[0], 0, 0, 0);
  s.emplace(0, 0, 0);
  for (int i = 0; i < k; ++i) {
    auto [v, ai, bi, ci] = que.top();
    cout << v << endl;
    if (ai + 1 < x && !s.contains(Tuple<int, int, int>(ai + 1, bi, ci))) {
      que.emplace(v - a[ai] + a[ai + 1], ai + 1, bi, ci);
      s.emplace(ai + 1, bi, ci);
    }
    if (bi + 1 < y && !s.contains(Tuple<int, int, int>(ai, bi + 1, ci))) {
      que.emplace(v - b[bi] + b[bi + 1], ai, bi + 1, ci);
      s.emplace(ai, bi + 1, ci);
    }
    if (ci + 1 < z && !s.contains(Tuple<int, int, int>(ai, bi, ci + 1))) {
      que.emplace(v - c[ci] + c[ci + 1], ai, bi, ci + 1);
      s.emplace(ai, bi, ci + 1);
    }
  }
}

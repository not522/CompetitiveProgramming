#include "deque.hpp"
#include "vector.hpp"

int main() {
  int a(in), b(in), q(in), si = 0, ti = 0;
  Deque<int64_t> s(a, in), t(b, in);
  Vector<int64_t> x(q, in), res(q);
  constexpr int64_t INF = 1e11;
  s.emplace_front(-INF);
  s.emplace_back(INF);
  t.emplace_front(-INF);
  t.emplace_back(INF);
  auto ind = x.argsort();
  for (int i = 0; i < q; ++i) {
    auto y = x[ind[i]];
    while (s[si + 1] < y) {
      ++si;
    }
    while (t[ti + 1] < y) {
      ++ti;
    }
    auto r1 = y - min(s[si], t[ti]);
    auto r2 = max(s[si + 1], t[ti + 1]) - y;
    auto r3 = s[si + 1] - t[ti] + min(s[si + 1] - y, y - t[ti]);
    auto r4 = t[ti + 1] - s[si] + min(t[ti + 1] - y, y - s[si]);
    res[ind[i]] = min({r1, r2, r3, r4});
  }
  res.output();
}

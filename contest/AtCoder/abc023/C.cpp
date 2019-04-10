#include "set.hpp"
#include "tuple.hpp"
#include "vector.hpp"

int main() {
  int r(in), c(in), k(in), n(in);
  Vector<int> v(r, 0), u(c, 0);
  Set<Tuple<int, int>> s;
  for (int i = 0; i < n; ++i) {
    int a(in), b(in);
    --a, --b;
    ++v[a], ++u[b];
    s.emplace(a, b);
  }
  int64_t res = 0;
  for (auto p : s) {
    if (v[p.get<0>()] + u[p.get<1>()] - 1 == k) {
      ++res;
    }
    if (v[p.get<0>()] + u[p.get<1>()] == k) {
      --res;
    }
  }
  v.sort();
  u.sort();
  for (auto i : v) {
    auto b = u.equal_range(k - i);
    res += b.second - b.first;
  }
  cout << res << endl;
}

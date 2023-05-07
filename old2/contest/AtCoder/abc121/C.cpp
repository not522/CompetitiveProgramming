#include "vector.hpp"

int main() {
  int n(in), m(in);
  Vector<Tuple<int, int>> p(n, in);
  p.sort();
  int64_t res = 0;
  for (int i = 0; i < n; ++i) {
    if (m <= p[i].get<1>()) {
      cout << res + int64_t(p[i].get<0>()) * m << endl;
      return 0;
    }
    res += int64_t(p[i].get<0>()) * p[i].get<1>();
    m -= p[i].get<1>();
  }
}

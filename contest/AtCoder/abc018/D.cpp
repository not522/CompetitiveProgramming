#include "container/fix_size_set.hpp"

int main() {
  int n(in), m(in), p(in), q(in), r(in);
  Vector<int> x(r), y(r), z(r);
  read(x, y, z);
  x -= 1;
  y -= 1;
  int res = 0;
  for (auto s : fixSizeSet(n, p)) {
    Vector<int> v(m);
    for (int i = 0; i < r; ++i) {
      if (s.contains(x[i])) {
        v[y[i]] += z[i];
      }
    }
    chmax(res, v.nth_element(q, true).subvector(q).accumulate());
  }
  cout << res << endl;
}

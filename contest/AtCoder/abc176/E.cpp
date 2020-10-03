#include "set.hpp"
#include "vector.hpp"

int main() {
  int h(in), w(in), m(in);
  Vector<int> a(m), b(m);
  read(a, b);
  Vector<int64_t> cnt_y(h + 1), cnt_x(w + 1);
  for (int k : a) {
    ++cnt_y[k];
  }
  for (int k : b) {
    ++cnt_x[k];
  }
  auto ymax = cnt_y.max(), xmax = cnt_x.max();
  auto lim = ymax + xmax;
  Vector<int> my, mx;
  for (int i = 0; i <= h; ++i) {
    if (cnt_y[i] == ymax) {
      my.emplace_back(i);
    }
  }
  for (int i = 0; i <= w; ++i) {
    if (cnt_x[i] == xmax) {
      mx.emplace_back(i);
    }
  }
  if (int64_t(my.size()) * mx.size() > m) {
    cout << lim << endl;
    return 0;
  }
  Set<Tuple<int, int>> s;
  for (int i = 0; i < m; ++i) {
    s.emplace(a[i], b[i]);
  }
  for (int y : my) {
    for (int x : mx) {
      if (!s.count(makeTuple(y, x))) {
        cout << lim << endl;
        return 0;
      }
    }
  }
  cout << lim - 1 << endl;
}

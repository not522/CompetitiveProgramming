#include "coordinate_compression.hpp"
#include "cumulative_sum_1D.hpp"

int main() {
  int n(in), c(in);
  (void)c;
  Vector<Tuple<int, int, int>> v, u;
  for (int i = 0; i < n; ++i) {
    int s(in), t(in), k(in);
    v.emplace_back(k, s, t);
  }
  v.sort();
  u.emplace_back(v[0]);
  for (int i = 1; i < n; ++i) {
    if (v[i].get<1>() == u.back().get<2>() &&
        v[i].get<0>() == u.back().get<0>()) {
      u.back().get<2>() = v[i].get<2>();
    } else {
      u.emplace_back(v[i]);
    }
  }
  Vector<int> w;
  for (auto i : u) {
    w.emplace_back(2 * i.get<1>() - 1);
    w.emplace_back(2 * i.get<2>());
  }
  auto coord = coordinateCompression(w);
  CumulativeSum1D<int> sum(coord.size());
  for (auto i : u) {
    sum.add(coord[2 * i.get<1>() - 1], coord[2 * i.get<2>()], 1);
  }
  cout << sum.max() << endl;
}

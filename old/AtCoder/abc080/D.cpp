#include "coordinate_compression.hpp"
#include "cumulative_sum_1D.hpp"

int main() {
  int n, c;
  cin >> n >> c;
  vector<tuple<int, int, int>> v, u;
  for (int i = 0; i < n; ++i) {
    int s, t, k;
    cin >> s >> t >> k;
    v.emplace_back(k, s, t);
  }
  sort(v);
  u.emplace_back(v[0]);
  for (int i = 1; i < n; ++i) {
    if (get<1>(v[i]) == get<2>(u.back()) && get<0>(v[i]) == get<0>(u.back())) {
      get<2>(u.back()) = get<2>(v[i]);
    } else {
      u.emplace_back(v[i]);
    }
  }
  vector<int> w;
  for (auto i : u) {
    w.emplace_back(2 * get<1>(i) - 1);
    w.emplace_back(2 * get<2>(i));
  }
  auto coord = coordinateCompression(w);
  CumulativeSum1D<int> sum(coord.size());
  for (auto i : u) sum.add(coord[2 * get<1>(i) - 1], coord[2 * get<2>(i)], 1);
  cout << sum.max() << endl;
}

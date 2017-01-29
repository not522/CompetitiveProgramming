#include "container/fix_size_set.hpp"

int main() {
  int n, m, p, q, r;
  cin >> n >> m >> p >> q >> r;
  vector<int> x(r), y(r), z(r);
  for (int i = 0; i < r; ++i) {
    cin >> x[i] >> y[i] >> z[i];
    --x[i], --y[i];
  }
  int res = 0;
  for (auto s : FixSizeSet(n, p)) {
    vector<int> v(m, 0);
    for (int i = 0; i < r; ++i) {
      if (s.in(x[i])) v[y[i]] += z[i];
    }
    nth_element(v.begin(), v.begin() + q, v.end(), greater<int>());
    res = max(res, accumulate(v.begin(), v.begin() + q, 0));
  }
  cout << res << endl;
}

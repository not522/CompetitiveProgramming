#include "minmax.hpp"
#include "vector.hpp"

int main() {
  int n;
  cin >> n;
  vector<pair<int64_t, int>> a(n), b(n);
  vector<int64_t> x(n + 1), y(n + 1);
  for (int i = 0; i < n; ++i) cin >> a[i].first >> b[i].first;
  for (int i = 0; i < n; ++i) a[i].second = b[i].second = i;
  sort(a), sort(b);
  for (int i = 0; i < n; ++i) x[i + 1] = x[i] + a[i].first;
  for (int i = 0; i < n; ++i) y[i + 1] = y[i] + b[i].first;
  int64_t res = min(x.back(), y.back());
  bitset<100000> s, t;
  for (int i = 0; i < n - 1; ++i) {
    s[a[i].second] = true;
    t[b[n - i - 1].second] = true;
    if (s != t) {
      chmin(res, x[i + 1] + y[n - i - 1]);
    } else {
      chmin(res, x[i + 1] + y[n - i - 1] + a[i + 1].first - a[i].first);
      chmin(res, x[i + 1] + y[n - i - 1] + b[n - i - 1].first - b[n - i - 2].first);
    }
  }
  cout << res << endl;
}

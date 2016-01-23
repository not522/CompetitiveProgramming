#include "vector.hpp"

int main() {
  int n;
  cin >> n;
  vector<long long> a(n), b(n);
  cin >> a >> b;
  long long t = 0, mx = 0, res = 0;
  int pos = 0;
  for (int i = 0; i < n; ++i) {
    mx = max(mx, b[pos]);
    res = max(res, t + mx * (n - i));
    if (t + a[pos] < 0) {
      t += mx;
    } else {
      t += a[pos];
      ++pos;
    }
  }
  cout << max(res, t) << endl;
}

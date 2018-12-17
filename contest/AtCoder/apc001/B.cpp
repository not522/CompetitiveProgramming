#include "vector.hpp"

int main() {
  int n;
  cin >> n;
  vector<int64_t> a(n), b(n);
  cin >> a >> b;
  int64_t k = accumulate(b) - accumulate(a);
  for (int i = 0; i < n; ++i) {
    if (a[i] < b[i]) a[i] += (b[i] - a[i] + 1) / 2 * 2;
  }
  cout << (k >= accumulate(a) - accumulate(b)) << endl;
}

#include "vector.hpp"

int main() {
  int64_t n, x, r = 0, k;
  cin >> n >> x;
  vector<int> a(1);
  for (int i = 0; i < n; ++i) {
    cin >> k;
    a.emplace_back(k);
    if (a[i] + a[i + 1] > x) {
      r += a[i] + a[i + 1] - x;
      a[i + 1] = x - a[i];
    }
  }
  cout << r << endl;
}

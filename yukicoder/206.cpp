#include "math/fft.hpp"

int main() {
  int l, m, n;
  cin >> l >> m >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < l; ++i) {
    int k;
    cin >> k;
    ++a[k - 1];
  }
  for (int i = 0; i < m; ++i) {
    int k;
    cin >> k;
    ++b[n - k];
  }
  int q;
  cin >> q;
  auto c = convolution(a, b);
  for (int i = n - 1; i < n + q - 1; ++i) cout << c[i] << endl;
}

#include "math/fft.hpp"

int main() {
  int n;
  cin >> n;
  vector<int> a(n + 1), b(n + 1);
  for (int i = 1; i <= n; ++i) cin >> a[i] >> b[i];
  auto c = convolution(a, b);
  for (int i = 1; i <= 2 * n; ++i) cout << c[i] << endl;
}

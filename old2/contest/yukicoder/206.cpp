#include "math/fft.hpp"

int main() {
  int l(in), m(in), n(in);
  Vector<int> a(n), b(n);
  for (int i = 0; i < l; ++i) {
    int k(in);
    ++a[k - 1];
  }
  for (int i = 0; i < m; ++i) {
    int k(in);
    ++b[n - k];
  }
  int q(in);
  auto c = convolution(a, b);
  for (int i = n - 1; i < n + q - 1; ++i) {
    cout << c[i] << endl;
  }
}

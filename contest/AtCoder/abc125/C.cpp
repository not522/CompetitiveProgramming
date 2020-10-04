#include "math.hpp"

int main() {
  int n(in), res = 0;
  Vector<int> a(n, in), b(n), c(n);
  b[0] = a[0];
  for (int i = 1; i < n; ++i) {
    b[i] = gcd(b[i - 1], a[i]);
  }
  c[n - 1] = a[n - 1];
  for (int i = n - 2; i >= 0; --i) {
    c[i] = gcd(c[i + 1], a[i]);
  }
  for (int i = 1; i < n - 1; ++i) {
    chmax(res, gcd(b[i - 1], c[i + 1]));
  }
  cout << max({res, b[n - 2], c[1]}) << endl;
}

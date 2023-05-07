#include "vector.hpp"

int main() {
  int n(in), l(in);
  Vector<int> x(n), w(n), t(n);
  read(x, w, t);
  int p = 0, k = 0;
  for (int i = 0; i < n; ++i) {
    k += x[i] - p;
    if (k % (2 * t[i]) >= t[i] || (k + w[i]) % (2 * t[i]) > t[i]) {
      k += 2 * t[i] - k % (2 * t[i]);
    }
    k += w[i];
    p = x[i] + w[i];
  }
  k += l - x.back() - w.back();
  cout << k << endl;
}

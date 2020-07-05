#include "vector.hpp"

int main() {
  int n(in);
  Vector<int> w(n, in);
  int a = w.accumulate(), b = 0, res = a;
  for (int i = 0; i < n; ++i) {
    chmin(res, abs(a - b));
    a -= w[i];
    b += w[i];
  }
  cout << res << endl;
}

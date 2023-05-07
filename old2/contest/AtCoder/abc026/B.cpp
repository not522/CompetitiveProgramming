#include "math.hpp"

int main() {
  int n(in);
  Vector<double> r(n, in);
  r.rsort();
  double res = 0;
  for (int i = 0; i < n; ++i) {
    res += (i % 2 ? -1 : 1) * r[i] * r[i] * pi();
  }
  cout << res << endl;
}

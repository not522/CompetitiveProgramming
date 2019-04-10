#include "vector.hpp"

int main() {
  int n(in), t(in);
  Vector<int> a(n, in);
  int res = 0, p = a[0];
  for (int i : a) {
    res += i + t - max(p, i);
    p = i + t;
  }
  cout << res << endl;
}

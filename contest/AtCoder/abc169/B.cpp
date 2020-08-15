#include "vector.hpp"

int main() {
  int n(in);
  Vector<int64_t> a(n, in);
  int64_t res = 1;
  for (auto i : a) {
    if (2e18 / res < i) {
      res = 2e18;
    } else {
      res *= i;
    }
  }
  if (res <= 1000000000000000000) {
    cout << res << endl;
  } else {
    cout << -1 << endl;
  }
}

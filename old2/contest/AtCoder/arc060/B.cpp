#include "template.hpp"

int main() {
  int64_t n(in), s(in);
  for (int b = 2; b < 1000000; ++b) {
    int64_t sm = 0;
    for (auto m = n; m; m /= b) {
      sm += m % b;
    }
    if (sm == s) {
      cout << b << endl;
      return 0;
    }
  }
  for (int64_t x = 1000000; x > 0; --x) {
    int64_t y = s - x;
    if (y >= 0 && (n - y) % x == 0 && max(x, y) < (n - y) / x) {
      cerr << x << " " << y << endl;
      cout << (n - y) / x << endl;
      return 0;
    }
  }
  if (n == s) {
    cout << n + 1 << endl;
  } else {
    cout << -1 << endl;
  }
}
